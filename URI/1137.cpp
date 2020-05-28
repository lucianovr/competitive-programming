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

inline int cmp(double x, double y = 0, double tol = EPS) { return ((x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1); }

/*
        Estrutura da dados para pontos
*/
struct ponto {
    double x, y;
    ponto() {}
    ponto(double x, double y) : x(x), y(y) {}
    ponto(ponto a, ponto b) {
        x = (b.x - a.x);
        y = (b.y - a.y);
    }
    ponto operator+(ponto q) { return ponto(x + q.x, y + q.y); }
    ponto operator-(ponto q) { return ponto(x - q.x, y - q.y); }
    ponto operator*(double t) { return ponto(x * t, y * t); }
    ponto operator/(double t) { return ponto(x / t, y / t); }

    int cmp(ponto q) const {
        if (int t = ::cmp(x, q.x))
            return t;
        return ::cmp(y, q.y);
    }
    bool operator==(ponto q) const { return cmp(q) == 0; };
    bool operator!=(ponto q) const { return cmp(q) != 0; };
    bool operator<(ponto q) const { return cmp(q) < 0; };
};
typedef ponto vec;
double dot(vec u, vec v) { return u.x * v.x + u.y * v.y; }
double cross(vec u, vec v) { return u.x * v.y - u.y * v.x; }
double norma(vec u) { return sqrt(dot(u, u)); }

struct circulo {
    double r;
    ponto p;
    circulo(){};
    circulo(ponto p, double r) : p(p), r(r){};
    bool igual(circulo c) {
        if (norma(c.p - p) <= EPS && fabs(r - c.r) <= EPS)
            return true;
        else
            return false;
    }
};

bool cmp_circles(circulo a, circulo b) {
    if (cmp(a.r, b.r))
        return cmp(a.r, b.r) < 0;
    return a.p < b.p;
}

circulo circumcenter(ponto p, ponto q, ponto r) {
    ponto a = p - r, b = q - r, c = ponto(dot(a, (p + r) / 2), dot(b, (q + r) / 2));
    ponto centro = ponto(cross(c, vec(a.y, b.y)), cross(vec(a.x, b.x), c)) / cross(a, b);
    return circulo(centro, norma(centro - p));
}
void cir(circulo c) { printf("( (%.5lf , %.5lf), %.5lf)", c.p.x, c.p.y, c.r); }

int main() {
    int n, u, v, ans;
    ponto P[110];

    while (cin >> n && n) {
        rep(i, 0, n) { scanf("%lf %lf", &P[i].x, &P[i].y); }

        if (n <= 2) {
            printf("%d\n", n);
            continue;
        }

        ans = 0;

        rep(i, 0, n) rep(j, i + 1, n) {
            vector<circulo> C;
            rep(k, 0, n) {
                if (k == i || k == j)
                    continue;
                if (cmp(cross(P[i] - P[j], P[i] - P[k])))
                    C.push_back(circumcenter(P[i], P[j], P[k]));
            }
            sort(ALL(C), cmp_circles);
            u = v = 0;
            while (v < C.sz) {
                if (C[v].igual(C[u]))
                    v++;
                else {
                    ans = max(ans, v - u);
                    u = v;
                }
            }
        }
        printf("%d\n", ans + 2);
    }
    return 0;
}
