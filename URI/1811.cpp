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

int main() {

    int N, M, v[110];

    // #bat, dif, maior, menor indice

    vector<pair<ii, ii>> vec;
    int inst = 0;
    while (scanf("%d", &N) && N != 0) {
        scanf("%d", &M);
        vec.clear();

        rep(i, 0, N) {
            rep(j, 0, M) { scanf("%d", &v[j]); }

            int j = 0, k = 0;
            int batidas = 0, dif, maior = -10;
            while (j < M) {
                k = j + 1;
                while (k < M && v[k] > v[k - 1])
                    k++;
                k--; // ultima valida

                if (k - j + 1 > batidas)
                    batidas = k - j + 1, dif = v[k] - v[j], maior = v[k];
                else if (k - j + 1 == batidas) {
                    if (v[k] - v[j] > dif)
                        dif = v[k] - v[j];
                    else if (v[k] - v[j] == dif)
                        maior = max(maior, v[k]);
                }
                // cout <<"("<<j<<" "<<k<<") "<< k-j+1 << " " << v[k]-v[j] << " " << v[k] << "\n";

                j = k + 1;
            }
            // cout << batidas << " " << dif << " " << maior << "\n";

            vec.pb(mp(mp(-batidas, -dif), mp(-maior, i + 1)));
        }
        sort(vec.begin(), vec.end());

        printf("Instancia #%d\n", ++inst);
        printf("%d\n", vec[0].second.second);
        printf("\n");
    }

    return 0;
}
