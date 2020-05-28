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

int G, A, M, C;
ll m1[610][110], m2[110][2010], m3[2010][110];
ll r1[110][110];
ll ans[610][110];

void mult1() {
    for (int i = 0; i < A; i++)
        for (int j = 0; j < C; j++) {
            r1[i][j] = 0;
            for (int k = 0; k < M; k++)
                r1[i][j] += m2[i][k] * m3[k][j];
        }
}

void mult2() {
    for (int i = 0; i < G; i++)
        for (int j = 0; j < C; j++) {
            ans[i][j] = 0;
            for (int k = 0; k < A; k++)
                ans[i][j] += m1[i][k] * r1[k][j];
        }
}

int main() {
    while (scanf("%ld %ld %ld %ld", &G, &A, &M, &C) > 0) {
        rep(i, 0, G) rep(j, 0, A) scanf("%lld", &m1[i][j]);
        rep(i, 0, A) rep(j, 0, M) scanf("%lld", &m2[i][j]);
        rep(i, 0, M) rep(j, 0, C) scanf("%lld", &m3[i][j]);
        mult1();
        mult2();

        int tam[C + 1];
        memset(tam, 0, sizeof tam);
        rep(i, 0, G) {
            rep(j, 0, C) { tam[j] = max(tam[j], ans[i][j] == 0 ? 1 : 1 + (int)log10((double)(ans[i][j]))); }
        }

        rep(i, 0, G) {
            rep(j, 0, C) {
                if (j)
                    printf(" ");
                int len = 1;
                if (ans[i][j])
                    len = 1 + (int)log10((double)(ans[i][j]));

                len = tam[j] - len;
                while (len--)
                    printf(" ");
                printf("%lld", ans[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}
