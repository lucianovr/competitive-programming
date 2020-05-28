#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i(a); i < (b); i++)
#define all(c) c.begin(), c.end()
#define pb push_back
#define D(x)                                                                                                           \
    if (1)                                                                                                             \
        cout << __LINE__ << " " << #x " = " << (x) << endl;
#define D2(x, y) cout << #x " = " << x << "  " << #y " = " << y << endl;
#define mp make_pair
#define fst first
#define snd second

typedef pair<int, int> ii;
typedef long long ll;

typedef vector<int> vi;
typedef vector<ii> vii;

vector<vi> E;
vector<vi> W;
int pd[100002][21], poke[100002][21], level[100002];
#define logmax 20

pair<int, int> lca(int a, int b) {
    int ma = -1;
    if (level[a] < level[b])
        swap(a, b);

    if (level[a] != level[b]) {
        for (int i = logmax; i >= 0; i--) {
            if (level[pd[a][i]] >= level[b]) {
                ma = max(ma, poke[a][i]);
                a = pd[a][i];
            }
        }
    }

    if (a != b) {
        for (int i = logmax; i >= 0; i--) {
            if (pd[a][i] != pd[b][i]) {
                ma = max(ma, max(poke[a][i], poke[b][i]));
                a = pd[a][i];
                b = pd[b][i];
            }
        }
        ma = max(ma, max(poke[a][0], poke[b][0]));
        a = pd[a][0];
        b = pd[b][0];
    }
    return ii(a, ma);
}

void dfs(int v, int p, int w) {
    level[v] = level[p] + 1;
    pd[v][0] = p;
    poke[v][0] = w;
    for (int i = 1; i <= logmax; i++) {
        pd[v][i] = pd[pd[v][i - 1]][i - 1]; // pai de v subindo 2^i arestas
        poke[v][i] = max(poke[pd[v][i - 1]][i - 1], poke[v][i - 1]);
    }
    for (int i = 0; i < E[v].size(); i++) {
        int u = E[v][i];
        if (u == p)
            continue;
        dfs(u, v, W[v][i]);
    }
}

void doit(int root, int pai) {
    level[root] = 0;
    for (int i = 0; i <= logmax; i++) {
        pd[root][i] = pai, poke[root][i] = 0;
    }
    for (int i = 0; i < E[root].size(); i++) {
        int v = E[root][i];
        dfs(v, root, W[root][i]);
    }
}

int main() {

    int N, K;
    while (cin >> N >> K) {
        E.resize(N + 1, vi());
        W.resize(N + 1, vi());
        int u, v, w;
        rep(i, 0, N - 1) {
            cin >> u >> v >> w;
            E[u].push_back(v);
            W[u].push_back(w);
            E[v].push_back(u);
            W[v].push_back(w);
        }
        doit(1, 1);

        int Q;
        cin >> Q;
        vii items(Q + 1);
        rep(i, 1, Q + 1) {
            cin >> u >> v;
            ii ret = lca(u, v);
            // cout << ret.first << " --- " << ret.second << "\n";
            items[i].first = ret.second;
            items[i].second = level[u] + level[v] - 2 * level[ret.first] + 1;
        }

        vector<vector<int>> pd(items.size(), vector<int>(K + 1, 0));
        for (int n = 1; n <= Q; n++) {
            for (int c = 1; c <= K; c++) {
                pd[n][c] = pd[n - 1][c];
                if (c - items[n].second >= 0) {
                    pd[n][c] = max(pd[n][c], pd[n - 1][c - items[n].second] + items[n].first);
                }
            }
        }
        pd[Q][K] ? printf("%d\n", pd[Q][K]) : printf("-1\n");
    }
    return 0;
}
