#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i(a); i < (b); i++)

#define all(c) c.begin(), c.end()
#define UNIQUE(c)                                                                                                      \
    { sort(ALL(c); (c).resize( unique(ALL(c))-c.begin() );                                               \
    }
#define pb push_back
#define D(x)                                                                                                           \
    if (1)                                                                                                             \
        cout << __LINE__ << " " << #x " = " << (x) << endl;
#define D2(x, y) cout << #x " = " << x << "  " << #y " = " << y << endl;
#define DVEC(v, n)                                                                                                     \
    {                                                                                                                  \
        cout << #v << "[] ={ ";                                                                                        \
        rep(i, 0, n) cout << v[i] << " ";                                                                              \
        cout << "}\n";                                                                                                 \
    }
#define mp make_pair
#define fst first
#define snd second

typedef pair<int, int> ii;
typedef long long ll;

typedef vector<int> vi;
typedef vector<ii> vii;

const int INF = 0x3f3f3f3f;
const double EPS = 1e-11;

inline int cmp(double x, double y = 0, double tol = EPS) { return ((x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1); }

double r, h, g, v;

double X(double t, double phi) { return v * cos(phi) * t; }

double Y(double phi) {
    double a = -g / 2.0;
    double b = v * sin(phi);
    double c = h;
    double delta = b * b - 4 * a * c;
    double sqrdelta = sqrt(delta);

    double t1 = (-b + sqrdelta) / (2 * a);
    double t2 = (-b - sqrdelta) / (2 * a);

    return max(t1, t2);
}

const double my_pi = 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034;

bool solve() {
    double lo = 0, hi = my_pi, tam, a, b;

    while (cmp(lo, hi, EPS) != 0) {
        tam = fabs(hi - lo) / 3;
        a = lo + tam;
        b = lo + 2 * tam;
        double Xa = X(Y(a), a);
        double Xb = X(Y(b), b);

        if (cmp(Xa, r, 0.01) >= 0 || cmp(Xb, r, 0.01) >= 0)
            return true;

        if (cmp(Xa, Xb, EPS) >= 0)
            hi = b;
        else
            lo = a;
    }

    lo = (lo + hi) / 2.0;
    double Xmax = X(Y(lo), lo);
    return cmp(Xmax, r, 0.01) >= 0;
}

int main() {
    while (scanf("%lf %lf %lf %lf", &r, &h, &v, &g) == 4) {
        if (solve())
            printf("Y\n");
        else
            printf("N\n");
    }
    return 0;
}
