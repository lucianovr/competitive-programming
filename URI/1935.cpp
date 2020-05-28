#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i(a); i < (b); i++)

#define all(c) c.begin(), c.end()
#define UNIQUE(c)                                                                                                      \
    {                                                                                                                  \
        sort(all(c));                                                                                                  \
        (c).resize(unique(all(c)) - c.begin());                                                                        \
    }
#define pb push_back

#define D(x)                                                                                                           \
    if (0)                                                                                                             \
        cout << __LINE__ << " " << #x " = " << (x) << endl;
#define D2(x, y)                                                                                                       \
    if (0)                                                                                                             \
        cout << #x " = " << x << "  " << #y " = " << y << endl;
#define DVEC(v, n)                                                                                                     \
    if (0) {                                                                                                           \
        cout << #v << "[] ={ ";                                                                                        \
        rep(i, 0, n) cout << v[i] << " ";                                                                              \
        cout << "}\n";                                                                                                 \
    }

#define mp make_pair
#define fst first
#define snd second

#define isONE(mask, bit) ((mask & (1<<bit))>0
#define isZERO(mask, bit) ((mask & (1<<bit))==0
#define setBIT(mask, bit) (mask | (1 << bit))
#define clearBIT(mask, bit) (mask & ~(1 << bit))
#define toogleBIT(mask, bit) (mask ^ (1 << bit))
#define LSOne(mask) (mask & (-mask))

typedef pair<int, int> ii;
typedef long long ll;

const int INF = 0x3f3f3f3f;
const double EPS = 1e-11;

// compara doubles
inline int cmp(double x, double y = 0, double tol = EPS) { return ((x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1); }

// compara inteiros
inline int cmp(int x, int y = 0) { return (x <= y) ? (x < y) ? -1 : 0 : 1; }

// direcoes  N  W  S  E  NW SW SE NE
int dx[] = {-1, 0, 1, 0, -1, 1, 1, -1};
int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

// knight moves
int dkx[] = {-2, -2, -1, 1, 2, 2, 1, -1};
int dky[] = {1, -1, -2, -2, -1, 1, 2, 2};

ll bs(ll lo, ll hi, ll X, ll N) {
    while (lo < hi - 1) {
        ll k = (lo + hi) / 2;
        ll corner = 4 * k * (N - k) + 1;

        if (corner < X) {
            lo = k;
        }
        if (corner > X) {
            hi = k - 1;
        }
        if (corner == X)
            return k;
    }

    for (ll col = lo; col <= hi; col++) {
        ll v = 4 * col * (N - col) + 1;
        if (v > X)
            return col - 1;
    }
    return hi;
}

ll busca(ll lo, ll hi, ll start, ll B) {
    ll tam;
    while (lo <= hi) {
        tam = (lo + hi) / 2;
        ll value = start + tam - 1;
        if (value < B)
            lo = tam + 1;
        if (value > B)
            hi = tam - 1;
        if (value == B)
            return tam;
    }
    return tam;
}

int main() {

    ll N, B;
    ll lo, hi;
    while (cin >> N >> B) {
        if (N % 2 == 0)
            lo = 0, hi = N / 2 - 1;
        else
            lo = 0, hi = N / 2;

        ll k = bs(lo, hi, B, N);
        ll start = 4 * k * (N - k) + 1;

        // left - right
        ll i = k + 1, j = k + 1;
        ll len = (N - k * 2);
        lo = 0, hi = len;

        ll prox = start + len - 1;
        if (B <= prox) {
            // fazer busca no j
            ll tam = busca(lo, hi, start, B);
            cout << i << " " << j + tam - 1 << "\n";
        } else {
            // up - down
            start = prox;
            prox = start + len - 1;
            j = j + len - 1;
            if (B <= prox) {
                ll tam = busca(lo, hi, start, B);
                cout << i + tam - 1 << " " << j << "\n";
            } else {
                // right - left
                start = prox;
                prox = start + len - 1;
                i = i + len - 1;
                if (B <= prox) {
                    ll tam = busca(lo, hi, start, B);
                    cout << i << " " << j - tam + 1 << "\n";
                } else {
                    // down - up
                    start = prox;
                    prox = start + len - 1;
                    j = j - len + 1;
                    ll tam = busca(lo, hi, start, B);
                    cout << i - tam + 1 << " " << j << "\n";
                }
            }
        }
    }
    return 0;
}
