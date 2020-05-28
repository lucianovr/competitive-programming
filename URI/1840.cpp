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

typedef pair<int, int> carta;

map<char, int> mapa;
int manilha;
string nome[4];
int faz[4];

int main() {
    char valores[] = {'4', '5', '6', '7', 'Q', 'J', 'K', 'A', '2', '3'};
    char naipes[] = {'D', 'S', 'H', 'C'};

    for (int i = 0; i < 10; i++) {
        mapa[valores[i]] = i;
    }
    for (int i = 0; i < 4; i++) {
        mapa[naipes[i]] = 1000 + i;
    }

    int N;
    char viraV, viraN;
    char x, y;

    while (scanf("%d %c%c", &N, &viraV, &viraN) == 3) {
        manilha = (mapa[viraV] + 1) % 10;
        rep(i, 0, 4) cin >> nome[i] >> faz[i];

        vector<int> R(4);
        while (N--) {
            rep(i, 0, 4) {
                scanf(" %c%c", &x, &y);
                if (mapa[x] != manilha)
                    R[i] = mapa[x];
                else
                    R[i] = mapa[y];
            }
            int idx = 0;
            rep(i, 1, 4) if (R[i] > R[idx]) idx = i;
            faz[idx]--;
        }

        int idx = 0;
        faz[0] = abs(faz[0]);

        rep(i, 1, 4) {
            faz[i] = abs(faz[i]);
            if (faz[i] < faz[idx])
                idx = i;
        }
        int cont = 0;
        rep(i, 0, 4) if (faz[i] == faz[idx]) cont++;

        if (cont == 1)
            printf("%s\n", nome[idx].c_str());
        else
            printf("*\n");
    }

    return 0;
}
