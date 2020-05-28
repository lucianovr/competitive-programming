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

#define isOne(mask, bit) (mask & (1LL << bit)) > 0
#define isZero(mask, bit) (mask & (1LL << bit)) == 0
#define stBit(mask, bit) (mask | (1LL << bit))
#define clrBit(mask, bit) (mask & ~(1LL << bit))
#define toogleBit(mask, bit) (mask ^ (1LL << bit))
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

int main() {

    int s[10010];
    int a, b;
    int n;
    int t = 1;

    while (cin >> n && n) {
        rep(i, 0, n) {
            cin >> a >> b;
            s[i] = a - b;
        }

        int soma = 0, maior = -1, ini = -1, fim = -2;

        int cur_i = 0;
        rep(i, 0, n) {
            soma += s[i];
            if (soma > maior) {
                maior = soma;
                ini = cur_i;
                fim = i;
            } else if (soma == maior) {
                if (i - cur_i > fim - ini)
                    ini = cur_i;
                fim = i;
            }
            if (soma < 0) {
                cur_i = i + 1;
                soma = 0;
            }
        }

        printf("Teste %d\n", t++);
        if (ini == -1 || maior <= 0)
            printf("nenhum\n\n");
        else
            printf("%d %d\n\n", ini + 1, fim + 1);
    }

    return 0;
}
