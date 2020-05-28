#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < b; i++)
#define mp make_pair
#define pb push_back

const int INF = 0x3f3f3f3f;
typedef pair<int, int> ii;

const double EPS = 1e-9;
inline int cmp(double x, double y = 0, double tol = EPS) { return ((x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1); }

struct point {
    double x, y;
    point(double x = 0, double y = 0) : x(x), y(y) {}
    point operator+(point q) { return point(x + q.x, y + q.y); }
    point operator-(point q) { return point(x - q.x, y - q.y); }
    point operator*(double t) { return point(x * t, y * t); }
    point operator/(double t) { return point(x / t, y / t); }
    point operator/(point q) { // divisao de num complexos
        return point(x * q.x + y * q.y, y * q.x - x * q.y) / q.norma2();
    }
    double norma2() { return (*this) * (*this); } // |u|^2
    double operator*(point q) { return x * q.x + y * q.y; }
    double operator%(point q) { return x * q.y - y * q.x; }
    int cmp(point q) const {
        if (int t = ::cmp(x, q.x))
            return t;
        return ::cmp(y, q.y);
    }
    bool operator==(point q) const { return cmp(q) == 0; };
    bool operator!=(point q) const { return cmp(q) != 0; };
    bool operator<(point q) const { return cmp(q) < 0; };
};

ostream &operator<<(ostream &os, const point &p) { os << "(" << p.x << "," << p.y << ")"; }

#define vec(a, b) (b - a)
typedef vector<point> polygon;

int ccw(point p, point q, point r) { return cmp(vec(p, q) % (vec(q, r))); }

double poly_area(polygon &T) {
    if (T.size() < 3)
        return 0;
    double s = 0;
    int n = T.size();
    rep(i, 0, n) s += T[i] % T[(i + 1) % n];
    return s / 2;
}

point pivot;
bool radial_lt(point a, point b) {
    int R = ccw(pivot, a, b);
    if (R == 0)
        return (pivot - a) * (pivot - a) < (pivot - b) * (pivot - b);
    else
        return (R == 1);
}

polygon convexhull(vector<point> &T) {
    // Remove pontos duplicadados
    sort(T.begin(), T.end());
    T.resize(unique(T.begin(), T.end()) - T.begin());
    int j = 0, k, n = T.size();
    polygon U;
    int P0 = min_element(T.begin(), T.end()) - T.begin();

    // pivot = menor x, menor y
    pivot = T[P0];
    swap(T[0], T[P0]);

    sort(++T.begin(), T.end(), radial_lt);
    for (k = n - 2; k >= 0 && ccw(T[0], T[n - 1], T[k]) == 0; k--)
        ;
    reverse((k + 1) + T.begin(), T.end());
    // troque <= por < para manter pontos colineares
    for (int i = 0; i < n; i++) {
        while (j > 1 && ccw(U[j - 2], U[j - 1], T[i]) < 0)
            U.pop_back(), j--;
        U.pb(T[i]);
        j++;
    }
    return U;
}

int main() {
    int N;
    while (scanf("%d", &N) == 1) {
        polygon P(N);
        for (int i = 0; i < N; i += 1) {
            cin >> P[i].x >> P[i].y;
        }

        polygon H = convexhull(P);
        printf("%.2lf\n", poly_area(H));
    }
    return 0;
}