#include <bits/stdc++.h>

using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)
#define pb push_back

int D, P, R, B;
vector<int> adj[200 + 10];
int preco[200 + 10];
int vis[200 + 10];

struct grupo {
    int A, B, CUSTO;
    grupo(int _A = 0, int _B = 0, int _CUSTO = 0) {
        A = _A;
        B = _B;
        CUSTO = _CUSTO;
    }
};

vector<grupo> G;

void init() {
    G.clear();
    rep(i, 0, D + P) adj[i].clear();
    memset(vis, 0, sizeof vis);
}

// DFS
int ESQ, DIR, CUST;
void dfs(int v, int f) {
    vis[v] = 1;
    if (f == 0)
        ESQ++;
    else
        DIR++;

    CUST += preco[v];

    for (int i = 0; i < adj[v].size(); i++) {
        int u = adj[v][i];
        if (vis[u] == 0) {
            dfs(u, 1 - f);
        }
    }
}
//

// Mochila
int pd[200 + 10][10000 + 10];
int solve(int i, int C);
//

int main() {

    int a, b;

    while (scanf("%d %d %d %d", &D, &P, &R, &B) == 4) {
        init();

        for (int i = 0; i < D; i++)
            scanf("%d", &preco[i]);

        for (int i = D; i < D + P; i++)
            scanf("%d", &preco[i]);

        while (R--) {
            scanf("%d %d", &a, &b);
            a--;
            b--;
            adj[a].pb(b + D);
            adj[b + D].pb(a);
        }

        for (int i = 0; i < D; i++)
            if (vis[i] == 0) {
                ESQ = 0;
                DIR = 0;
                CUST = 0;
                dfs(i, 0);
                G.pb(grupo(ESQ, DIR, CUST));
            }

        for (int i = D; i < D + P; i++)
            if (vis[i] == 0)
                G.pb(grupo(0, 1, preco[i]));

        // resolvendo a PD
        int left = 0, right = 0;

        memset(pd, -1, sizeof pd);
        left = solve(G.size() - 1, B);

        rep(i, 0, G.size()) swap(G[i].A, G[i].B);

        memset(pd, -1, sizeof pd);
        right = solve(G.size() - 1, B);

        printf("%d %d\n", left, right);
    }
    return 0;
}

int solve(int i, int C) {
    if (i == -1 || C == 0)
        return 0;
    if (pd[i][C] != -1)
        return pd[i][C];

    int ans = 0;

    // nao_pega

    ans = max(ans, solve(i - 1, C) + G[i].A);

    // pega
    if (C >= G[i].CUSTO)
        ans = max(ans, solve(i - 1, C - G[i].CUSTO) + G[i].B);

    return pd[i][C] = ans;
}
