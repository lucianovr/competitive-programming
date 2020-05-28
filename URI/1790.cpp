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
#define isONE(mask, bit) ((mask & (1 << bit))) > 0
#define isZERO(mask, bit) ((mask & (1 << bit))) == 0
#define setBIT(mask, bit) (mask | (1 << bit))

typedef pair<int, int> ii;
typedef long long ll;

typedef vector<int> vi;
typedef vector<ii> vii;

const int INF = 0x3f3f3f3f;
const double EPS = 1e-11;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

// pontes
#define MAXV 100
vector<int> adj[MAXV];
int dfs_num[MAXV], dfs_low[MAXV], dfs_parent[MAXV];
int dfscounter, V, dfsRoot, rootChildren, ans;
int articulation[MAXV], articulations;
vector<ii> bridges;

void articulationPointAndBridge(int u) {
    dfs_low[u] = dfs_num[u] = dfscounter++;
    rep(i, 0, adj[u].size()) {
        int v = adj[u][i];
        if (dfs_num[v] == -1) {
            dfs_parent[v] = u;
            if (u == dfsRoot)
                rootChildren++;

            articulationPointAndBridge(v);
            if (dfs_low[v] >= dfs_num[u])
                articulation[u] = true;
            if (dfs_low[v] > dfs_num[u])
                bridges.pb(ii(u, v));

            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
        } else if (v != dfs_parent[u])
            dfs_low[u] = min(dfs_low[u], dfs_num[v]);
    }
}

void pontes(int V) {
    // read graph
    dfscounter = 0;
    rep(i, 0, V) {
        dfs_low[i] = dfs_parent[i] = articulation[i] = 0;
        dfs_num[i] = -1;
    }
    articulations = 0;
    bridges.clear();
    rep(i, 0, V) if (dfs_num[i] == -1) {
        dfsRoot = i;
        rootChildren = 0;
        articulationPointAndBridge(i);
        articulation[dfsRoot] = (rootChildren > 1);
    }
}

int main() {
    int N, M;
    while (cin >> N >> M) {
        rep(i, 0, N) adj[i].clear();
        while (M--) {
            int x, y;
            cin >> x >> y;
            x--, y--;
            adj[x].pb(y);
            adj[y].pb(x);
        }
        pontes(N);
        printf("%d\n", bridges.size());
    }

    return 0;
}
