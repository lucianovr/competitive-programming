#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <stack>
#include <utility>
#include <vector>

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define rep(i, a, b) for (int i = a; i < b; ++i)
#define pb push_back
#define debug(x) cout << #x << " = " << x << endl;

#define printMatriz(M, r, c)                                                                                           \
    rep(i, 0, r) {                                                                                                     \
        printVetor(M[i], c);                                                                                           \
        cout << endl;                                                                                                  \
    }
#define printVetor(V, n) rep(j, 0, n) cout << V[j] << " ";

const double EPS = 1e-10, tol = 1e-3;
inline int cmp(double x, double y = 0, double tol = EPS) { return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1; }

struct point {
    double x, y;
    point(double _x = 0, double _y = 0) {
        x = _x;
        y = _y;
    }
    point operator+(point q) { return point(x + q.x, y + q.y); }
    point operator-(point q) { return point(x - q.x, y - q.y); }
    point operator*(double m) { return point(x * m, y * m); }
    point operator/(double m) { return point(x / m, y / m); }

    double operator%(point q) { return x * q.y - y * q.x; } // prod vetorial
    double operator*(point q) { return x * q.x + y * q.y; } // prod escalar

    int cmp(point q) const {
        if (int t = ::cmp(x, q.x))
            return t;
        return ::cmp(y, q.y);
    }
};

double abs(point p) { return hypot(p.x, p.y); }

int dentro(point p, double a, double b) {
    double dist = pow(p.x, 2) / pow(a, 2) + pow(p.y, 2) / pow(b, 2);

    return cmp(dist - 1.0);
}

double busca(point p, point vec, double a, double b) {
    double lo = 0, hi = 1, m;
    int d;
    point aux = p;
    while (dentro(aux, a, b) != 1) {
        aux = aux + vec * hi;
        hi = hi * 2;
    }
    if (dentro(aux, a, b) == 0)
        hi = hi * 2;

    while (lo < hi) {
        m = (lo + hi) / 2.0;
        point P = p + vec * m;
        d = dentro(P, a, b);
        if (d == -1)
            lo = m;
        else if (d == 1)
            hi = m;
        else
            break;
    }
    return m;
}

void print(point p) {
    cout << fixed << setprecision(3);
    if (cmp(p.x, 0, tol) == 0)
        cout << "0.000 ";
    else
        cout << p.x << " ";

    if (cmp(p.y, 0, tol) == 0)
        cout << "0.000\n";
    else
        cout << p.y << "\n";
}

int main() {
    point p, vec, tang;
    double px, py, dx, dy, a, b, scale;

    while (scanf("%lf %lf %lf %lf %lf %lf", &px, &py, &dx, &dy, &a, &b) == 6) {
        p = point(px, py);
        vec = point(dx, dy);
        vec = vec / abs(vec); // normalizando vector

        scale = busca(p, vec, a, b);
        p = p + vec * scale; // ponto inicial que toca a elipse

        print(p);

        tang = point(pow(a, 2) * p.y, -pow(b, 2) * p.x); // vector tangente a elipse
        double ang = atan(tang % vec / (tang * vec));    // angulo entre o vetor direcao e o vetor tangente

        ang = -2 * ang; // angulo no qual vec devera ser rotacionado

        vec = point(vec.x * cos(ang) - vec.y * sin(ang),
                    vec.x * sin(ang) + vec.y * cos(ang)); // rotacao do vetor direcao vec
        vec = vec / abs(vec);                             // normalizando vector

        scale = busca(p, vec, a, b);
        p = p + vec * scale; // novo ponto de interseccao

        print(p);
    }
    return 0;
}