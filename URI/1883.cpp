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

int d[1010][1010];
char grid[1010][1010];
ii q[1010 * 1010];

void bfs(int x, int y) {
    memset(d, -1, sizeof d);
    int inicio, fim;
    inicio = fim = 0;
    q[fim++] = ii(x, y);
    while (inicio < fim) {
        x = q[inicio].fst;
        y = q[inicio].snd;
        inicio++;

        int a, b;
        rep(i, 0, 4) {
            a = x + dx[i];
            b = y + dy[i];
            if (grid[a][b] != '#' && d[a][b] == -1) {
                d[a][b] = d[x][y] + 1;
                q[fim++] = ii(a, b);
            }
        }
    }
}

int main() {
    int t, N, M, ex, ey, sx, sy;
    vector<int> fx, fy;

    scanf("%d", &t);
    while (t--) {
        fx.clear();
        fy.clear();

        scanf("%d %d", &N, &M);

        for (int j = 0; j <= M + 1; j++)
            grid[0][j] = grid[N + 1][j] = '#';
        for (int i = 0; i <= N + 1; i++)
            grid[i][0] = grid[i][M + 1] = '#';

        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= M; j++) {
                scanf(" %c", &grid[i][j]);
                if (grid[i][j] == 'E')
                    ex = i, ey = j;
                if (grid[i][j] == 'S')
                    sx = i, sy = j;
                if (grid[i][j] == 'F')
                    fx.pb(i), fy.pb(j);
            }
        }

        bfs(ex, ey);
        int menor_fogo = INF;
        rep(i, 0, fx.size()) menor_fogo = min(menor_fogo, d[fx[i]][fy[i]]);

        if (menor_fogo <= d[sx][sy] || d[sx][sy] == -1)
            printf("N\n");
        else
            printf("Y\n");
    }
    return 0;
}
