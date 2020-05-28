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
        (c).resize(unique(ALL(c)) - c.begin());
#define sz size()
const double EPS = 1e-9;
typedef pair<int, int> ii;

inline int cmp(double x, double y = 0, double tol = EPS) { return ((x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1); }

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

    double operator*(ponto q) { return x * q.x + y * q.y; }
    double operator%(ponto q) { return x * q.y - y * q.x; }
};
typedef vector<ponto> poligono;

pair<ponto, ponto> seg[1010];
pair<double, ii> edges[1000000];

double norma(ponto u) { return sqrt(u * u); }

int ccw(ponto p, ponto q, ponto r) { return cmp((q - p) % (r - q)); }

ponto projecao(ponto a, ponto b) { return b * ((a * b) / (b * b)); }

bool entre(ponto r, ponto p, ponto s) { return cmp((r - p) % (s - p)) == 0 && cmp((r - p) * (s - p)) <= 0; }

bool intersect_seg(int i, int j) {
    ponto a = seg[i].first;
    ponto b = seg[i].second;
    ponto c = seg[j].first;
    ponto d = seg[j].second;

    int d1, d2, d3, d4;
    d1 = ccw(a, c, d);
    d2 = ccw(b, c, d);
    d3 = ccw(c, a, b);
    d4 = ccw(d, a, b);

    if (d1 * d2 == -1 && d3 * d4 == -1)
        return true;
    if (d1 == 0 && entre(c, a, d))
        return true;
    if (d2 == 0 && entre(c, b, d))
        return true;
    if (d3 == 0 && entre(a, c, b))
        return true;
    if (d4 == 0 && entre(a, d, b))
        return true;

    return false;
}

double dist(ponto p, ponto a, ponto b) {
    ponto pp = a + projecao((p - a), (b - a));
    if (entre(a, pp, b))
        return norma(p - pp);
    else
        return min(norma(a - p), norma(b - p));
}

double dist2(int i, int j) {
    ponto A = seg[i].first;
    ponto B = seg[i].second;
    ponto C = seg[j].first;
    ponto D = seg[j].second;
    return min(min(dist(A, C, D), dist(B, C, D)), min(dist(C, A, B), dist(D, A, B)));
}

// kruskal
double mst;
int cont;
int pai[10000];

int find(int x) {
    if (x != pai[x])
        pai[x] = find(pai[x]);
    return pai[x];
}

void join(int a, int b, double cost) {
    a = find(a);
    b = find(b);
    if (a != b) {
        cont++;
        mst += cost;
        pai[a] = b;
    }
}

int main() {
    int N;
    double x1, x2, y1, y2;
    while (scanf("%d", &N) == 1) {
        rep(i, 0, N) {
            pai[i] = i;

            scanf("%lf %lf %lf %lf", &x1, &y1, &x2, &y2);
            seg[i] = (make_pair(ponto(x1, y1), ponto(x2, y2)));
        }
        int e = 0;
        rep(i, 0, N) {
            rep(j, i + 1, N) {
                if (intersect_seg(i, j)) {
                    edges[e++] = make_pair(0.0, make_pair(i, j));
                } else {
                    edges[e++] = make_pair(dist2(i, j), make_pair(i, j));
                }
            }
        }

        sort(edges, edges + e);
        mst = 0.0;
        cont = 0;
        rep(i, 0, e) {
            join(edges[i].second.first, edges[i].second.second, edges[i].first);
            if (cont == N - 1)
                break;
        }
        cout << ceil(mst) << "\n";
    }
}
