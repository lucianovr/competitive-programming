#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i(a); i < (b); i++)
#define all(c) (c).begin(), (c).end()
#define fst first
#define snd second
#define db(x) cerr << __LINE__ << ": " << #x << " = " << x << endl

#define pb push_back
#define mp make_pair

const int INF = 0x3f3f3f3f;
typedef long long ll;
typedef pair<int, int> ii;

vector<int> adj[110];
int seen[110];

int dfs(int v, int cor) {
    if (seen[v] == -1) {
        seen[v] = cor;
    } else {
        return seen[v] == cor;
    }

    rep(i, 0, adj[v].size()) {
        int u = adj[v][i];
        if (!dfs(u, 1 - cor))
            return 0;
    }

    return 1;
}

int main() {
#ifndef ONLINE_JUDGE
    // freopen("_in.txt", "r", stdin);
    // freopen("_out.txt", "w", stdout);
#endif

    int n, m, instancia = 1;

    while (scanf("%d %d", &n, &m) > 0) {
        int u, v;
        rep(i, 1, n + 1) adj[i].clear();
        while (m--) {
            scanf("%d %d", &u, &v);
            adj[u].pb(v);
            adj[v].pb(u);
        }

        memset(seen, -1, sizeof seen);
        int bipartido = 1;
        for (int i = 1; i <= n; i++) {
            if (seen[i] == -1)
                bipartido = dfs(i, 0);

            if (!bipartido)
                break;
        }
        printf("Instancia %d\n%s\n\n", instancia++, bipartido ? "sim" : "nao");
    }

    return 0;
}
