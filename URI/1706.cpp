#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define rep(i, a, b) for (int i(a); i < (b); i++)
#define debug(x) cout << #x << " = " << x << "\n";

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int contB;
char tipo[1010];
int vis[1010];
vector<int> adj[1010];

void dfs(int u) {
    if (vis[u])
        return;
    vis[u] = 1;

    contB += (tipo[u] == 'B');
    rep(i, 0, adj[u].size()) { dfs(adj[u][i]); }
}

int main() {
    int n, m, u, v;
    char c;
    while (scanf("%d %d", &n, &m) == 2) {
        rep(i, 0, n) {
            scanf(" %c", &tipo[i]);
            adj[i].clear();
        }
        while (m--) {
            scanf("%d %d", &u, &v);
            adj[u - 1].pb(v - 1);
            adj[v - 1].pb(u - 1);
        }
        memset(vis, 0, sizeof vis);

        bool ok = true;
        rep(i, 0, n) {
            contB = 0;
            if (!vis[i])
                dfs(i);
            if (contB % 2 == 1) {
                ok = false;
                break;
            }
        }

        printf("%c\n", ok ? 'Y' : 'N');
    }
    return 0;
}
