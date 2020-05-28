#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)
#define mk make_pair
#define debug(x) cout << #x << " = " << x << "\n";
#define pb push_back
typedef long long ll;
typedef pair<int, int> ii;

const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;

vector<vector<int>> g;
vector<vector<int>> t;
int N;
vector<int> vis, visT;
int cnt[2];

void dfs(int v) {
    if (vis[v])
        return;
    vis[v] = true;
    cnt[0]++;
    vector<int> adj = g[v];
    rep(i, 0, adj.size()) {
        int u = adj[i];
        dfs(u);
    }
}

void dfsT(int v) {
    if (visT[v])
        return;
    visT[v] = true;
    cnt[1]++;
    vector<int> adj = t[v];
    rep(i, 0, adj.size()) {
        int u = adj[i];
        dfsT(u);
    }
}

int main() {
    cin >> N;
    g.resize(N + 2);
    t.resize(N + 2);

    int u, v;
    rep(i, 0, N) {
        cin >> u >> v;
        g[u].push_back(v);
        t[v].push_back(u);
    }
    cnt[0] = cnt[1] = 0;

    vis.resize(N + 1, false);
    dfs(1);

    visT.resize(N + 1, false);
    dfsT(1);

    cnt[0] == cnt[1] && cnt[0] == N ? printf("S\n") : printf("N\n");
    return 0;
}
