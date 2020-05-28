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
#define clr(c) (memset((c), 0, sizeof(c))
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

int N, M;
map<string, int> dist;
queue<string> Q;
bool vis[6][7];
// dfs(i,j,g[1][1],g[i][j],h);
void dfs(int x, int y, char cor1, char cor2, char h[][7]) {

    h[x][y] = cor2;
    vis[x][y] = true;

    int xx, yy;
    rep(i, 0, 4) {
        xx = x + dx[i];
        yy = y + dy[i];
        if (h[xx][yy] != '$' && !vis[xx][yy]) {
            if (h[xx][yy] == cor1 || h[xx][yy] == cor2) {
                dfs(xx, yy, cor1, cor2, h);
            }
        }
    }
}

void str2grid(char g[][7], string &s) {
    int pos = 0;

    for (int j = 0; j <= M + 1; j++)
        g[0][j] = g[N + 1][j] = '$';
    for (int i = 0; i <= N + 1; i++)
        g[i][0] = g[i][M + 1] = '$';

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
            g[i][j] = s[pos++];
}

void grid2str(char h[][7], string &s) {
    s.clear();
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
            s += h[i][j];
}

int bfs(string state) {
    char g[6][7], h[6][7], prev;
    string new_state;
    int distancia;

    dist.clear();
    while (!Q.empty())
        Q.pop();
    Q.push(state);
    dist[state] = 0;

    while (!Q.empty()) {
        state = Q.front();
        distancia = dist[state];
        Q.pop();

        str2grid(g, state);

        bool igual = true;
        for (int i = 1, tam = N * M; igual && i < tam; i++)
            if (state[i] != state[0])
                igual = false;

        if (igual)
            return distancia;

        rep(i, 1, N + 1) {
            rep(j, 1, M + 1) {
                if (g[i][j] != g[1][1]) {
                    rep(k, 1, N + 1) {
                        rep(l, 1, M + 1) {
                            vis[k][l] = false;
                            h[k][l] = g[k][l];
                        }
                    }
                    dfs(1, 1, g[1][1], g[i][j], h);
                    grid2str(h, new_state);
                    if (!dist.count(new_state)) {
                        dist[new_state] = distancia + 1;
                        Q.push(new_state);
                    }
                }
            }
        }
    }
}

int main() {

    char ch;
    while (scanf("%d %d", &N, &M) != EOF) {
        string s;

        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= M; j++) {
                scanf(" %c", &ch);
                s += ch;
            }

        int ret = bfs(s);
        printf("%d\n", ret);
    }
    return 0;
}
