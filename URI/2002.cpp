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

long long XOR(ll a, ll b) {
    if (a > b)
        swap(a, b);

    ll gb = ((b >> 1) & 1) ^ (b & 1 ? 1 : b);
    ll ga = (((a - 1) >> 1) & 1) ^ ((a - 1) & 1 ? 1 : (a - 1));
    return (long long)(gb ^ ga);
}

long long g[110][110];
int N, M;

long long dist[110][110];
bool vis[110][110];

long long dijkstra() {
    int x, y, a, b;
    priority_queue<pair<long long, ii>> Q;

    memset(dist, -1, sizeof dist);
    memset(vis, false, sizeof vis);
    Q.push(mp(dist[1][1] = 0, ii(1, 1)));

    while (!Q.empty()) {
        ii s = Q.top().snd;
        Q.pop();

        x = s.fst;
        y = s.snd;

        if (vis[x][y])
            continue;
        if (x == N && y == M)
            break;
        vis[x][y] = true;

        rep(i, 0, 4) {
            a = x + dx[i];
            b = y + dy[i];
            if (g[a][b] != -1) {
                ll custo = XOR(g[x][y], g[a][b]);
                if (dist[a][b] == -1 || dist[a][b] > dist[x][y] + custo) {
                    dist[a][b] = dist[x][y] + custo;
                    Q.push(mp(-dist[a][b], ii(a, b)));
                }
            }
        }
    }
    return dist[N][M];
}

int main() {

    while (scanf("%d %d", &N, &M) == 2) {

        memset(g, -1, sizeof g);
        rep(i, 1, N + 1) {
            rep(j, 1, M + 1) { cin >> g[i][j]; }
        }

        long long ret = dijkstra();
        printf("%lld\n", ret);
    }
    return 0;
}