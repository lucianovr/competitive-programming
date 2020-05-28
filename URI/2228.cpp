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

    //	freopen("caca.txt", "r", stdin);
    //	freopen("cacaOUT.txt", "w", stdout);

    int A, B, N, M, tt = 1, x[110], metade;
    bool v[10100], ok;
    vector<int> vec, aux;

    while (scanf("%d %d %d", &A, &B, &N) > 0) {

        ok = false;
        vec.clear();
        aux.clear();

        if (A <= 0 && B <= 0 && N <= 0)
            break;

        M = 0;
        rep(i, 0, N) {
            scanf("%d", &x[i]);
            M += x[i];
        }

        printf("Teste %d\n", tt++);

        metade = (M + A + B);
        if ((metade) % 2 == 1) {
            printf("N\n\n");
            continue;
        }
        metade = metade / 2 - A;

        for (int i = 0; i <= M; i++)
            v[i] = false;
        v[0] = true;
        vec.pb(0);

        rep(i, 0, N) {
            aux.clear();
            rep(j, 0, vec.size()) {
                if (v[vec[j] + x[i]] == false)
                    aux.pb(vec[j] + x[i]);
                aux.pb(vec[j]);
                v[vec[j] + x[i]] = true;
            }
            if (v[metade]) {
                printf("S\n\n");
                ok = true;
                break;
            }
            vec = aux;
        }

        if (!ok)
            printf("N\n\n");
    }
    return 0;
}
