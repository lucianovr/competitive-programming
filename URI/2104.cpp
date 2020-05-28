#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)
#define pb push_back

const double EPS = 1e-9;
inline int cmp(double x, double y = 0, double tol = EPS) { return ((x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1); }
int sgn(double x) { return (x > EPS) - (x < -EPS); }

#define LINE 0
#define SEGMENT 1
#define RAY 2
#define vec(ini, fim) (fim - ini)
struct PT {
    double x, y, z;
    PT() { x = y = z = 0; }
    PT(double x, double y, double z) : x(x), y(y), z(z) {}
    PT operator+(PT q) { return PT(x + q.x, y + q.y, z + q.z); }
    PT operator-(PT q) { return PT(x - q.x, y - q.y, z - q.z); }
    PT operator*(double d) { return PT(x * d, y * d, z * d); }
    PT operator/(double d) { return PT(x / d, y / d, z / d); }
    double dist2() { return x * x + y * y + z * z; }
    double dist() { return sqrt(dist2()); }
    bool operator==(PT a) { return fabs(x - a.x) < EPS && fabs(y - a.y) < EPS && fabs(z - a.z) < EPS; }
};
double dot(PT A, PT B) { // produto escalar
    return A.x * B.x + A.y * B.y + A.z * B.z;
}
PT cross(PT A, PT B) { // produto vetorial
    return PT(A.y * B.z - A.z * B.y, A.z * B.x - A.x * B.z, A.x * B.y - A.y * B.x);
}
inline double det(double a, double b, double c, double d) { return a * d - b * c; }
inline double det(double a11, double a12, double a13, double a21, double a22, double a23, double a31, double a32,
                  double a33) {
    return a11 * det(a22, a23, a32, a33) - a12 * det(a21, a23, a31, a33) + a13 * det(a21, a22, a31, a32);
}
inline double det(const PT &a, const PT &b, const PT &c) { return det(a.x, a.y, a.z, b.x, b.y, b.z, c.x, c.y, c.z); }
double norma(PT A) { return sqrt(dot(A, A)); }
double distSq(PT a, PT b) { return dot(a - b, a - b); }

// reta e plano
struct line { // reta definida por um ponto p e direcao v
    PT p, v;
    line(){};
    line(PT p, PT v) : p(p), v(v) { assert(!(v == PT())); }
    bool on(PT pt) { return cross(pt - p, v) == PT(); }
};
struct plane {
    PT n;
    double d;
    plane() : d(0) {}
    plane(PT p1, PT p2, PT p3) {
        n = cross(p2 - p1, p3 - p1);
        d = -dot(n, p1);
        assert(side(p1) == 0);
        assert(side(p2) == 0);
        assert(side(p3) == 0);
    }
    int side(PT p) { return sgn(dot(n, p) + d); }
};

// retorna a intersecao de reta com plano [retorna 1 se intersecao for pt]
int crossLinePlane(line l, plane pl, PT &res) {
    double d = dot(pl.n, l.v);
    if (sgn(d) == 0) {
        return (pl.side(l.p) == 0) ? 2 : 0;
    }
    double t = (-dot(pl.n, l.p) - pl.d) / d;
    res = l.p + l.v * t;
#ifdef DEBUG
    assert(pl.side(res) == 0);
#endif
    return 1;
}

// pt 2D
struct point {
    double x, y;
    point(double x = 0, double y = 0) : x(x), y(y) {}
    point operator+(point q) { return point(x + q.x, y + q.y); }
    point operator-(point q) { return point(x - q.x, y - q.y); }
    point operator*(double t) { return point(x * t, y * t); }
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
typedef vector<point> polygon;

int ccw(point p, point q, point r) { return cmp(vec(p, q) % (vec(p, r))); }

point pivot;
bool radial_lt(point a, point b) {
    int R = ccw(pivot, a, b); // verifica se A esta antes de B
    if (R == 0)               // pivot,a,b sao colineares
        return (pivot - a) * (pivot - a) < (pivot - b) * (pivot - b);
    else
        return (R == 1); // 1 se A vem antes de B, sentido ccw
}
vector<point> convexhull(vector<point> &T) {
    int tam = 0, k, n = T.size();
    vector<point> U; // convex hull

    int P0 = min_element(T.begin(), T.end()) - T.begin();
    pivot = T[P0];
    swap(T[0], T[P0]);
    sort(++T.begin(), T.end(), radial_lt);
    for (int i = 0; i < n; i++) {
        while (tam > 1 && ccw(U[tam - 2], U[tam - 1], T[i]) <= 0)
            U.pop_back(), tam--;
        U.pb(T[i]);
        tam++;
    }
    return U;
}

double signedArea(polygon &T) {
    double area = 0;
    int n = T.size();
    if (n < 3)
        return 0;
    rep(i, 0, n) area += T[i] % T[(i + 1) % n];
    return (area / 2.0);
}
/* Retorna a area de um poligono T
   (pode ser concavo ou convexo) em O(N)*/
double poly_area(polygon &T) { return fabs(signedArea(T)); }

int main() {
    plane Earth(PT(0, 0, 0), PT(1, 1, 0), PT(0, 1, 0));
    vector<point> P; // 2d points
    PT laser;
    PT base;
    int N;
    while (scanf("%d", &N) && N) {
        P.clear();
        scanf("%lf %lf %lf", &laser.x, &laser.y, &laser.z);
        for (int i = 0; i < N; i++) {
            scanf("%lf %lf %lf", &base.x, &base.y, &base.z);
            line L(base, vec(laser, base));
            PT inter;
            if (crossLinePlane(L, Earth, inter) == 1)
                P.push_back(point(inter.x, inter.y));
        }
        P = convexhull(P);
        printf("%.2lf\n", poly_area(P));
    }
    return 0;
}