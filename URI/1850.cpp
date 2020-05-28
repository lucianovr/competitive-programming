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

#define isONE(mask, bit) (mask & (1 << bit)) > 0
#define isZERO(mask, bit) (mask & (1 << bit)) == 0
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

string g[110];

int d[102][102][1 << 7], N, M;
queue<pair<ii, int>> Q; // (pos, chaves)

inline void update(int x, int y, int mask, int dist) {
    if (d[x][y][mask] == -1) {
        d[x][y][mask] = dist;
        Q.push(mp(mp(x, y), mask));
    }
}

inline bool valido(int x, int y) { return x >= 0 && x < N && y >= 0 && y < M && g[x][y] != '#'; }

int bfs(int x, int y, int xs, int ys) {
    int mask, resp = INF;
    memset(d, -1, sizeof d);

    while (!Q.empty())
        Q.pop();

    Q.push(mp(mp(x, y), 0));
    d[x][y][0] = 0;

    while (!Q.empty()) {
        x = Q.front().fst.fst;
        y = Q.front().fst.snd;
        mask = Q.front().snd;
        int dist_atual = d[x][y][mask];

        Q.pop();

        if (x == xs && y == ys)
            resp = min(resp, d[x][y][mask]);

        rep(i, 0, 4) {
            int xx = x + dx[i];
            int yy = y + dy[i];
            if (valido(xx, yy)) {
                if (isalpha(g[xx][yy])) {
                    if (isupper(g[xx][yy])) // eh porta?
                    {
                        if (isONE(mask, g[xx][yy] - 'a')) { // tenho chave?
                            int new_mask = setBIT(mask, g[xx][yy] - 'a');
                            update(xx, yy, new_mask, dist_atual + 1);
                        }
                    } else {
                        int new_mask = setBIT(mask, g[xx][yy] - 'a'); // eh chave
                        update(xx, yy, new_mask, dist_atual + 1);
                    }
                } else {
                    update(xx, yy, mask, dist_atual + 1);
                }
            }
        }
    }
    return resp;
}

int main() {

    int i = 0;
    while (getline(cin, g[i]))
        i++;
    N = i;
    M = g[0].size();

    int xa, ya, xs, ys;
    rep(i, 0, N) rep(j, 0, M) {
        if (g[i][j] == '@')
            xa = i, ya = j;
        else if (g[i][j] == '*')
            xs = i, ys = j;
    }

    int resp = bfs(xa, ya, xs, ys);
    if (resp != INF)
        printf("%d\n", resp);
    else
        printf("--\n");

    return 0;
}
