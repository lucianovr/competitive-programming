#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <utility>
#include <vector>

using namespace std;
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define pb push_back
#define debug(x) cout << #x << " = " << x << endl;

const int INF = 0x3f3f3f3f;

const double EPS = 1e-9;

inline int cmp(double x, double y = 0, double tol = EPS) { return ((x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1); }

struct point {
    double x, y;
    void read() { scanf("%lf %lf", &x, &y); }
    point(double _x = 0, double _y = 0) : x(_x), y(_y){};

    point operator+(point q) { return point(x + q.x, y + q.y); }
    point operator-(point q) { return point(x - q.x, y - q.y); }
    point operator*(double t) { return point(x * t, y * t); }
    point operator/(double t) { return point(x / t, y / t); }

    double operator*(point q) { return x * q.x + y * q.y; }
    double operator%(point q) { return x * q.y - y * q.x; }

    friend ostream &operator<<(ostream &o, point p) { return o << "(" << p.x << ", " << p.y << ")"; }
};
point pivot;
vector<point> hull, pts;

double abs(point u) { return hypot(u.x, u.y); }
typedef pair<point, double> circle;

bool in_circle(circle C, point p) { return cmp(abs(p - C.first), C.second) <= 0; }
point circumcenter(point p, point q, point r) {
    point a = p - r, b = q - r, c = point(a * (p + r) / 2, b * (q + r) / 2);
    return point(c % point(a.y, b.y), point(a.x, b.x) % c) / (a % b);
}
circle spanning_circle(vector<point> &T) {
    int n = T.size();
    random_shuffle(T.begin(), T.end());
    circle C(point(), -1000000);
    for (int i = 0; i < n; i++)
        if (!in_circle(C, T[i])) {
            C = circle(T[i], 0);
            for (int j = 0; j < i; j++)
                if (!in_circle(C, T[j])) {
                    C = circle((T[i] + T[j]) / 2, abs(T[i] - T[j]) / 2);
                    for (int k = 0; k < j; k++)
                        if (!in_circle(C, T[k])) {
                            point o = circumcenter(T[i], T[j], T[k]);
                            C = circle(o, abs(o - T[k]));
                        }
                }
        }
    return C;
}

int ccw(point p, point a, point b) { // p->a->b
    point U = a - p, V = b - a;
    double ans = U % V;
    return cmp(ans);
}
bool angle_cmp(point a, point b) {
    int ret = ccw(pivot, a, b);
    if (ret == 0)
        return (pivot - a) * (pivot - a) < (pivot - b) * (pivot - b);
    return ret == 1;
}

void GrahamScan() {
    hull.clear();
    int P0 = 0, N = pts.size();
    for (int i = 1; i < N; i++)
        if (pts[i].y < pts[P0].y || pts[i].y == pts[P0].y && pts[i].x < pts[P0].x)
            P0 = i;
    swap(pts[0], pts[P0]);
    pivot = pts[0];
    sort(++pts.begin(), pts.end(), angle_cmp);
    if (N <= 3) {
        hull = pts;
        return;
    }
    hull.pb(pts[0]);
    hull.pb(pts[1]);
    int sz = 2;
    for (int i = 2; i < N; i++) {
        while (sz >= 2 && ccw(hull[sz - 2], hull[sz - 1], pts[i]) <= 0) {
            hull.pop_back();
            sz--;
        }
        hull.pb(pts[i]);
        sz++;
    }
}

int main() {
    point a;
    int n, inst = 1;
    while (scanf("%d", &n) && n) {
        pts.clear();
        rep(i, 0, n) {
            a.read();
            pts.pb(a);
        }
        GrahamScan();

        // rep(i,0,hull.size())	cout<<hull[i]<<"\n";

        circle c = spanning_circle(hull);
        printf("Instancia %d\n%.2lf %.2lf %.2lf\n\n", inst++, c.first.x, c.first.y, c.second);
    }
    return 0;
}
