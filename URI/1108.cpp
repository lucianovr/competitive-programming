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

const int INF = 0x3f3f3f3f;

const double EPS = 1e-9;

inline int cmp(double x, double y = 0, double tol = EPS) { return ((x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1); }

struct ponto {
    double x, y;
    void read() { scanf("%lf %lf", &x, &y); }
    ponto(double _x = 0, double _y = 0) : x(_x), y(_y){};

    ponto operator+(ponto q) { return ponto(x + q.x, y + q.y); }
    ponto operator-(ponto q) { return ponto(x - q.x, y - q.y); }
    ponto operator*(double t) { return ponto(x * t, y * t); }
    ponto operator/(double t) { return ponto(x / t, y / t); }

    double operator*(ponto q) { return x * q.x + y * q.y; }
    double operator%(ponto q) { return x * q.y - y * q.x; }

    friend ostream &operator<<(ostream &o, ponto p) { return o << "(" << p.x << ", " << p.y << ")"; }
};
vector<ponto> P, T;

double norma(ponto u) { return hypot(u.x, u.y); }
typedef pair<ponto, double> circle;

bool in_circle(ponto c, ponto p, double r) { return cmp(norma(p - c), r) <= 0; }

ponto circumcenter(ponto p, ponto q, ponto r) {
    ponto a = p - r, b = q - r, c = ponto(a * (p + r) / 2, b * (q + r) / 2);
    return ponto(c % ponto(a.y, b.y), ponto(a.x, b.x) % c) / (a % b);
}

double spanning_circle() {
    double r;
    ponto c;

    random_shuffle(ALL(T));
    int t = T.size();

    if (t < 2)
        return 0;
    if (t == 2)
        return norma(T[0] - T[1]) / 2;

    for (int i = 0; i < t; i++)
        if (!in_circle(c, T[i], r)) {
            c = T[i];
            r = 0;
            for (int j = 0; j < i; j++)
                if (!in_circle(c, T[j], r)) {
                    c = (T[i] + T[j]) / 2;
                    r = norma(T[i] - T[j]) / 2;
                    for (int k = 0; k < j; k++)
                        if (!in_circle(c, T[k], r)) {
                            c = circumcenter(T[i], T[j], T[k]);
                            r = norma(c - T[i]);
                        }
                }
        }
    return r;
}

double solve() {
    double ans = 0x3f3f3f3f;
    ponto c;
    double r;
    int p = P.size();

    rep(i, 0, p) rep(j, i + 1, p) {
        c = (P[i] + P[j]) / 2;
        r = norma(P[i] - P[j]) / 2;

        if (cmp(r, ans) == 1)
            continue;

        T.clear();
        rep(u, 0, p) if (!in_circle(c, P[u], r)) T.pb(P[u]);

        ans = min(ans, max(r, spanning_circle()));
    }

    rep(i, 0, p) rep(j, i + 1, p) rep(k, j + 1, p) if (cmp((P[i] - P[j]) % (P[k] - P[j])) != 0) {
        c = circumcenter(P[i], P[j], P[k]);
        r = norma(c - P[i]);

        if (cmp(r, ans) == 1)
            continue;

        T.clear();
        rep(u, 0, p) if (!in_circle(c, P[u], r)) T.pb(P[u]);
        ans = min(ans, max(r, spanning_circle()));
    }
    return ans;
}

int main() {
    //	freopen("cel.txt", "r", stdin);
    //	freopen("torre.txt", "w", stdout);
    int p;

    while (scanf("%d", &p) && p) {
        P.resize(p);

        rep(i, 0, p) scanf("%lf %lf", &P[i].x, &P[i].y);
        printf("%.2lf\n", solve());
    }
    return 0;
}
