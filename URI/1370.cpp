#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctype.h>
#include <iostream>
#include <map>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define rep(i, a, b) for (int i = a; i < b; ++i)
#define pb push_back

const int INF = 0x3f3f3f3f;
const double EPS = 1e-10;
int cmp(double x, double y = 0, double tol = EPS) { return ((x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1); }

struct point {
    int x, y;
    point(int _x = 0, int _y = 0) : x(_x), y(_y) {}
    void read() { scanf("%d%d", &x, &y); }

    point operator+(point q) { return point(x + q.x, y + q.y); }
    point operator-(point q) { return point(x - q.x, y - q.y); }
    long long operator*(point q) { return x * q.x + y * q.y; } // escalar
    long long operator%(point q) { return x * q.y - y * q.x; } // vetorial

    point operator*(int t) { return point(x * t, y * t); } // scale
    point operator/(int t) { return point(x / t, y / t); } // scale

    friend ostream &operator<<(ostream &o, point p) { return o << "(" << p.x << ", " << p.y << ")"; }
};

double abs(point o) { return hypot((double)o.x, (double)o.y); }

point P[400];
pair<point, point> S[200];
double M[400][400];
int p, s;

int ccw(point a, point b, point c) {
    long long ret = (b - a) % (c - b);
    return (ret > 0 ? 1 : (ret == 0 ? 0 : -1));
}

bool intersectSeg(point a, point b, point c, point d) {
    int d1, d2, d3, d4;
    d1 = ccw(a, c, d);
    d2 = ccw(b, c, d);
    d3 = ccw(c, a, b);
    d4 = ccw(d, a, b);
    return d1 * d2 == -1 && d3 * d4 == -1;
}

bool func(point a, point b) {
    for (int i = 0; i < s; i++)
        if (intersectSeg(a, b, S[i].first, S[i].second))
            return true;
    return false;
}

void MontaGrafo() {
    for (int i = 0; i < p; i++)
        for (int j = i + 1; j < p; j++)
            if (func(P[i], P[j]))
                M[i][j] = M[j][i] = -1.0;
            else
                M[i][j] = M[j][i] = abs(P[i] - P[j]);
}

double dijkstra() {
    int s;
    double dist[400];
    int vis[400];
    priority_queue<pair<double, int>> Q;

    rep(i, 0, p + 1) {
        vis[i] = 0;
        dist[i] = -1;
    }
    dist[0] = 0;
    Q.push(make_pair(0, 0));

    while (!Q.empty()) {
        pair<double, int> top = Q.top();
        Q.pop();
        s = top.second;

        if (vis[s])
            continue;

        vis[s] = 1;
        if (s == 1)
            break;

        for (int i = 0; i < p; i++) {
            if (i != s && M[s][i] > -0.5) {
                if (dist[i] < 0 || dist[i] > dist[s] + M[s][i]) {
                    dist[i] = dist[s] + M[s][i];
                    Q.push(make_pair(-dist[i], i));
                }
            }
        }
    }
    return dist[1];
}

string str;
int main() {
    int n, x, y, x2, y2;
    point ini, fim, p1, p2;
    int t = 1;

    // vector<double> Vec;
    double resp;
    while (true) {
        scanf("%d%d%d%d%d", &x, &y, &x2, &y2, &n);

        if (x == y && x == x2 && x == y2 && x == n && x == 0)
            break;

        ini = point(x, y);
        fim = point(x2, y2);
        p = 0;
        s = 0;
        P[p++] = ini;
        P[p++] = fim;

        if (n)
            for (int i = 0; i < n; i++) {
                ini.read();
                fim.read();
                P[p++] = ini;
                P[p++] = fim;
                S[s++] = make_pair(ini, fim);
            }

        if (n == 0)
            resp = abs(ini - fim);
        else {
            MontaGrafo();
            resp = dijkstra();
        }
        printf("%.2lf\n", resp);
    }
    return 0;
}
