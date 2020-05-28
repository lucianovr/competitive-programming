#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i(a); i < (b); i++)

#define all(c) c.begin(), c.end()
#define UNIQUE(c)                                                                                                      \
    { sort(ALL(c); (c).resize( unique(ALL(c))-c.begin() );                                               \
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

typedef pair<int, int> ii;
typedef long long ll;

typedef vector<int> vi;
typedef vector<ii> vii;

const int INF = 0x3f3f3f3f;
const double EPS = 1e-11;

inline int cmp(double x, double y = 0, double tol = EPS) { return ((x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1); }

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

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

#define MAXN 1000000 + 10
int pos[MAXN];
int prox[110];
int N;

int main() {
    int t, O, rodadas;

    t = readInt();
    while (t--) {
        N = readInt();
        O = readInt();
        rodadas = readInt();

        for (int i = 0; i < 110; i++)
            prox[i] = i;
        for (int i = 0; i < N; i++)
            pos[i] = 1;
        while (O--) {
            int origem, destino;
            origem = readInt();
            destino = readInt();
            prox[origem] = destino;
        }

        vector<int> dado(rodadas);
        rep(i, 0, rodadas) dado[i] = readInt();

        int j = 0; // jogador
        rep(i, 0, dado.size()) {
            pos[j] += +dado[i];
            if (pos[j] > 100)
                pos[j] = 100;

            while (prox[pos[j]] != pos[j])
                pos[j] = prox[pos[j]];

            if (pos[j] == 100)
                break;

            j = (j + 1) % N;
        }

        for (int i = 0; i < N; i++) {
            printf("Position of player %d is %d.\n", i + 1, pos[i]);
        }
    }

    return 0;
}
