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

#define MAXV 100 * 100 + 100

vector<int> adj[MAXV];
int match[MAXV], V, q1, q2;
bool vis[MAXV];

int aug(int v) {

    if (vis[v])
        return 0;
    vis[v] = true;
    int tam = adj[v].size();

    rep(j, 0, tam) {
        int r = adj[v][j];
        if (match[r] == -1 || aug(match[r])) {
            match[r] = v;
            return 1;
        }
    }
    return 0;
}

int cor[MAXV];
void dfs_color(int v) {
    rep(i, 0, adj[v].size()) {
        int u = adj[v][i];
        if (cor[u] == -1) {
            cor[u] = 1 - cor[v];
            dfs_color(u);
        }
    }
}

int main() {

    int N, M;
    int g[110][110];

    while (scanf("%d %d", &N, &M) == 2) {
        if (N == 0 && M == 0)
            break;

        memset(g, 0, sizeof g);
        for (int i = 0; i <= N + 1; i++)
            g[i][0] = g[i][M + 1] = 1;
        for (int j = 0; j <= M + 1; j++)
            g[0][j] = g[N + 1][j] = 1;

        int e, x, y;
        scanf("%d", &e);

        while (e--) {
            scanf("%d %d", &x, &y);
            g[x][y] = 1;
        }

        V = N * M;
        for (int v = 1; v <= V; v++)
            adj[v].clear();

        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= M; j++) {
                if (!g[i][j]) {
                    rep(k, 0, 4) {
                        x = i + dx[k];
                        y = j + dy[k];
                        if (!g[x][y]) {
                            adj[(i - 1) * N + j].pb((x - 1) * N + y);
                        }
                    }
                }
            }

        memset(cor, -1, sizeof cor);

        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= M; j++)
                if (!g[i][j]) {
                    int v = (i - 1) * N + j;
                    if (cor[v] == -1) {
                        cor[v] = 1;
                        dfs_color(v);
                    }
                }
        vector<int> left;
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= M; j++)
                if (!g[i][j]) {
                    int v = (i - 1) * N + j;
                    if (cor[v] == 1)
                        left.pb(v);
                }

        int mcbm = 0;
        memset(match, -1, sizeof match);
        rep(i, 0, left.size()) {
            rep(j, 0, left.size()) vis[left[j]] = false;
            mcbm += aug(left[i]);
        }

        printf("%d\n", mcbm);
    }

    return 0;
}
