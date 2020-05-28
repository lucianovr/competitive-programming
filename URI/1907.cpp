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

int R, C;
bool dentro(int x, int y) { return x >= 0 && y >= 0 && x < R && y < C; }
int m[1025][1025];

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

pair<int, int> fila[1025 * 1025];

void bfs(int x, int y) {
    int inicio, fim, a, b;

    inicio = fim = 0;
    fila[fim++] = mp(x, y);

    while (inicio != fim) {
        x = fila[inicio].fst;
        y = fila[inicio].snd;
        inicio++;

        if (m[x][y] != 0)
            continue;
        m[x][y] = 1;
        rep(i, 0, 4) {
            a = x + dx[i];
            b = y + dy[i];
            if (dentro(a, b) && m[a][b] == 0) {
                fila[fim++] = mp(a, b);
            }
        }
        m[x][y] = 2;
    }
}

int main() {
    int ans;

    while (scanf("%d %d", &R, &C) == 2) {
        char c;
        rep(i, 0, R) {
            rep(j, 0, C) {
                scanf(" %c", &c);
                if (c == '.')
                    m[i][j] = 0;
                else
                    m[i][j] = 2;
            }
        }

        ans = 0;
        rep(i, 0, R) {
            rep(j, 0, C) {
                if (m[i][j] == false) {
                    ans++;
                    bfs(i, j);
                }
            }
        }

        printf("%d\n", ans);
    }

    return 0;
}
