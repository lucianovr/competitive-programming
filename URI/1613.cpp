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

const int INF = 0x3F3F3F3F;
const double EPS = 1e-10;

int cmp(double x, double y = 0, double tol = EPS) { return ((x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1); }

inline bool cmp_eq(double x, double y) { return cmp(x, y) == 0; }
inline bool cmp_lt(double x, double y) { return cmp(x, y) < 0; }

int dx[] = {0, 0, -1, 1, -1, -1, 1, 1};
int dy[] = {-1, 1, 0, 0, -1, 1, 1, -1};

struct point {
    int x, y;
    point() {}
    point(int x, int y) : x(x), y(y) {}
    void read() { scanf("%d %d", &x, &y); }
};

struct seg {
    point p1, p2;
    seg() {}
    seg(point p1, point p2) : p1(p1), p2(p2) {}
    bool operator<(seg a) { return p1.y < a.p1.y; }
};

vector<seg> s;
point e;

int cross(point p, point q, point r) {
    int ux = q.x - p.x, uy = q.y - p.y;
    int vx = r.x - q.x, vy = r.y - q.y;
    int ret = ux * vy - uy * vx;
    if (ret > 0)
        return 1;
    if (ret < 0)
        return -1;
    return 0;
}

int func(int n, point p) {
    int f1, f2;
    for (int i = 0; i < n; i++) {
        f1 = cross(e, s[i].p1, p);
        f2 = cross(e, s[i].p2, p);

        if (f1 == 1 && f2 == -1) {
            // cout << "protegido pela parede " << i << "\n";
            return 1;
        }
        if (f1 <= 0)
            return 0;
    }
    return 0;
}

bool comp(seg a, seg b) { return (a.p1.y < b.p1.y); }

int main() {

    int t, n, m, y1, y2;
    point g;

    scanf("%d", &t);
    while (t--) {
        s.clear();

        e.read();
        scanf("%d", &n);
        rep(i, 0, n) {
            scanf("%d %d", &y1, &y2);
            s.pb(seg(point(0, y1), point(0, y2)));
        }

        sort(s.begin(), s.end(), comp);

        scanf("%d", &m);
        int cnt = 0;
        rep(i, 0, m) {
            g.read();
            if (func(n, g)) {
                // cout << "ponto " << i << " esta protegido\n";
                cnt++;
            }
            // else cout << "nao esta protegido\n";
            // printf("\n");
        }

        printf("%d\n", cnt);
    }
    return 0;
}
