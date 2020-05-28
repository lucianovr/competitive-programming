#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i(a); i < (b); i++)
#define debug(x) cout << #x << " = " << x << "\n";

#define ALL(c) c.begin(), c.end()
#define SORT(c) sort(ALL(c))
#define UNIQUE(c)                                                                                                      \
    {                                                                                                                  \
        SORT(c);                                                                                                       \
        (c).resize(unique(ALL(c)) - c.begin());                                                                        \
    }
#define pb push_back
#define sz size()
#define D(x)                                                                                                           \
    if (1)                                                                                                             \
        cout << __LINE__ << " " << #x " = " << (x) << endl;
#define D2(x, y)                                                                                                       \
    if (1)                                                                                                             \
        cout << __LINE__ << " " << #x " = " << (x) << ", " << #y " = " << (y) << endl;

typedef pair<int, int> ii;
typedef vector<int> VI;
typedef vector<ii> VII;
typedef long long LL;

const double EPS = 1e-9;
const int INF = 0x3f3f3f3f;

inline int cmp(double x, double y = 0, double tol = EPS) { return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1; }

struct point {
    double x, y;
    point(double x = 0, double y = 0) : x(x), y(y) {}
    point operator+(point q) { return point(x + q.x, y + q.y); }
    point operator-(point q) { return point(x - q.x, y - q.y); }
    point operator*(double t) { return point(x * t, y * t); }
    point operator/(double t) { return point(x / t, y / t); }
    double operator*(point q) { return x * q.x + y * q.y; }
    double operator%(point q) { return x * q.y - y * q.x; }
    int cmp(point q) const {
        if (int t = ::cmp(x, q.x))
            return t;
        return ::cmp(y, q.y);
    }
    bool operator==(point q) const { return cmp(q) == 0; }
    bool operator!=(point q) const { return cmp(q) != 0; }
    bool operator<(point q) const { return cmp(q) < 0; }
    bool operator<=(point q) const { return cmp(q) <= 0; }
    friend ostream &operator<<(ostream &o, point p) { return o << "(" << p.x << ", " << p.y << ")"; }
    static point pivot;
};

double dist(point a, point b) { return sqrt((a - b) * (a - b)); }

bool compy(point a, point b) { return cmp(a.y, b.y) ? cmp(a.y, b.y) < 0 : cmp(a.x, b.x) < 0; }

pair<point, point> closest_points_rec(vector<point> &px, vector<point> &py) {
    pair<point, point> ret;

    double d;

    if (px.size() <= 3) {
        double best = 1e10;

        for (int i = 0; i < px.size(); ++i) {
            for (int j = i + 1; j < px.size(); ++j) {
                if (dist(px[i], px[j]) < best) {
                    ret = make_pair(px[i], px[j]);
                    best = dist(px[i], px[j]);
                }
            }
        }

        return ret;
    }

    point split = px[(px.size() - 1) / 2];

    vector<point> qx, qy, rx, ry;

    for (int i = 0; i < px.size(); ++i) {
        if (px[i] <= split)
            qx.push_back(px[i]);
        else
            rx.push_back(px[i]);
    }

    for (int i = 0; i < py.size(); ++i) {
        if (py[i] <= split)
            qy.push_back(py[i]);
        else
            ry.push_back(py[i]);
    }

    ret = closest_points_rec(qx, qy);

    pair<point, point> rans = closest_points_rec(rx, ry);

    double delta = dist(ret.first, ret.second);

    if ((d = dist(rans.first, rans.second)) < delta) {
        delta = d;
        ret = rans;
    }

    vector<point> s;

    for (int i = 0; i < py.size(); ++i) {
        if (cmp(abs(py[i].x - split.x), delta) <= 0)
            s.push_back(py[i]);
    }

    for (int i = 0; i < s.size(); ++i) {
        for (int j = 1; j <= 7 && i + j < s.size(); ++j) {
            if ((d = dist(s[i], s[i + j])) < delta) {
                delta = d;
                ret = make_pair(s[i], s[i + j]);
            }
        }
    }

    return ret;
}

pair<point, point> closest_points(vector<point> pts) {
    if (pts.size() == 1)
        return make_pair(point(-INF, -INF), point(INF, INF));

    sort(pts.begin(), pts.end());

    for (int i = 0; i + 1 < pts.size(); ++i)
        if (pts[i] == pts[i + 1])
            return make_pair(pts[i], pts[i + 1]);

    vector<point> py = pts;

    sort(py.begin(), py.end(), compy);

    return closest_points_rec(pts, py);
}

int main() {
    int n;
    double x, y;
    vector<point> pts;

    while (cin >> n && n) {
        pts.clear();
        rep(i, 0, n) {
            cin >> x >> y;
            pts.pb(point(x, y));
        }

        pair<point, point> pp = closest_points(pts);
        double ans = dist(pp.first, pp.second);
        if (cmp(ans, 10000) < 0)
            printf("%.4lf\n", ans);
        else
            printf("INFINITY\n");
    }
    return 0;
}
