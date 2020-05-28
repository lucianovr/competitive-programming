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

int readInt() {
    bool minus = false;
    int result = 0;
    char ch;

    ch = getchar();
    while (true) {
        if (ch == '-')
            break;
        if (ch >= '0' && ch <= '9')
            break;
        ch = getchar();
    }
    if (ch == '-')
        minus = true;
    else
        result = ch - '0';
    while (true) {
        ch = getchar();
        if (ch < '0' || ch > '9')
            break;
        result = result * 10 + (ch - '0');
    }
    if (minus)
        return -result;
    else
        return result;
}

int isPrime(int n) {

    if (n < 2)
        return 0;

    if (n == 2)
        return 1;

    if (n % 2 == 0)
        return 0;

    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0)
            return 0;
    }

    return 1;
}

ll pd[60][60];

ll S(int n, int k) {
    if (n == k || k == 0)
        return pd[n][k] = 1;

    if (pd[n][k] == -1) {
        pd[n][k] = S(n - 1, k - 1) + S(n - 1, k);
    }

    return pd[n][k];
}

int main() {
    memset(pd, -1, sizeof pd);
    for (int n = 0; n <= 50; n++) {
        for (int k = 0; k <= n; k++) {
            S(n, k);
        }
    }

    int n, m, k;
    while (scanf("%d %d %d", &n, &m, &k) > 0) {
        if (n == 0 && m == 0 && k == 0)
            break;

        int L[n], C[m];
        memset(L, 0, sizeof L);
        memset(C, 0, sizeof C);

        rep(i, 0, n) {
            rep(j, 0, m) {
                int v = isPrime(i * m + j) == 0;
                L[i] += v;
                C[j] += v;
            }
        }

        ll somaL = 0;
        ll somaC = 0;
        rep(i, 0, n) {
            if (L[i] >= k) {
                somaL += pd[L[i]][k];
            }
        }
        rep(j, 0, m) {
            if (C[j] >= k) {
                somaC += pd[C[j]][k];
            }
        }

        ll ans = somaL + somaC;
        if (k == 1)
            ans -= min(somaL, somaC);

        cout << ans << "\n";
    }
    return 0;
}
