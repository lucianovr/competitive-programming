#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i(a); i < (b); i++)
#define D(x)                                                                                                           \
    if (1)                                                                                                             \
        cout << __LINE__ << " " << #x " = " << (x) << endl;
#define ALL(c) c.begin(), c.end()
#define SORT(c) sort(ALL(c))
#define UNIQUE(c)                                                                                                      \
    {                                                                                                                  \
        SORT(c);                                                                                                       \
        (c).resize(unique(ALL(c)) - c.begin());                                                                        \
    }
#define pb push_back
#define sz size()
const double EPS = 1e-9;

inline int cmp(double x, double y = 0, double tol = EPS) { return ((x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1); }
struct point {
    double x, y;
    point() {}
    point(double x, double y) : x(x), y(y) {}
    point(point a, point b) { // vetor a->b
        x = (b.x - a.x);
        y = (b.y - a.y);
    }
    point operator+(point q) { return point(x + q.x, y + q.y); }
    point operator-(point q) { return point(x - q.x, y - q.y); }
    point operator*(double t) { return point(x * t, y * t); }
    point operator/(double t) { return point(x / t, y / t); }

    int cmp(point q) const {
        if (int t = ::cmp(x, q.x))
            return t;
        return ::cmp(y, q.y);
    }
    bool operator==(point q) const { return cmp(q) == 0; };
    bool operator!=(point q) const { return cmp(q) != 0; };
    bool operator<(point q) const { return cmp(q) < 0; };

    double operator*(point q) { return x * q.x + y * q.y; }
    double operator%(point q) { return x * q.y - y * q.x; }
};
typedef vector<point> polygon;
double norma(point u) { return sqrt(u * u); }
int ccw(point p, point q, point r) { return cmp((q - p) % (r - q)); }
point project(point a, point b) { return b * ((a * b) / (b * b)); }
bool between(point p, point q, point r) { return ccw(p, q, r) == 0 && cmp((p - q) * (r - q)) <= 0; }

double poly_area(polygon &T) {
    if (T.size() < 3)
        return 0;
    double s = 0;
    int n = T.size();
    for (int i = 0; i < n; i++)
        s += T[i] % T[(i + 1) % n];
    return s / 2;
}

/*
                P(3)*
        P(4)*           P(2)*

                P(0)*   P(1)*

        fixar P(0) as pivot
        (0,1) choose 2  cross(0,1,2)
        (1,2) choose 3 cross(0,2,3)
        (2,3) choose 4 cross(0,3,4)
        (3,4) choose 0 cross(0,4,0)
        (4,0) return 0
*/

point pivot;
bool radial_lt(point a, point b) {
    int R = ccw(pivot, a, b);
    if (R == 1)
        return true;
    if (R == -1)
        return false;

    if (a.x > pivot.x)
        return norma(pivot - a) < norma(pivot - b);
    return norma(pivot - a) > norma(pivot - b);
}

int N;
double A;
double pd[110][110];
int memo[110][110];
polygon p;

double S(int i, int j) {
    if (j == 0)
        return 0;

    if (pd[i][j] > -1)
        return pd[i][j];

    double asw = 0, s;
    for (int k = j + 1; k <= N; k++)
        if (ccw(p[i], p[j], p[k]) >= 0) {
            s = (p[j] - p[0]) % (p[k % N] - p[0]) + S(j, k % N);
            if (s <= A)
                asw = max(asw, s);
        }
    return pd[i][j] = asw;
}

int main() {
    while (scanf("%d %lf", &N, &A) == 2) {
        A *= 2;
        ++N;
        p.resize(N);
        rep(i, 0, N) scanf("%lf %lf", &p[i].x, &p[i].y);

        pivot = p[0];
        sort(++p.begin(), p.end(), radial_lt);
        double asw = 0, s;
        for (int i = 0; i < 110; i++)
            for (int j = 0; j < 110; j++)
                pd[i][j] = -2.0;

        for (int j = 1; j < N; j++) {
            s = S(0, j);
            if (s <= A)
                asw = max(asw, s);
        }
        cout << asw / 2 << "\n";
    }
    return 0;
}
