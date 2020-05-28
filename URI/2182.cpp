#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

#define MAXN 11234
int N, M;
vector<pair<int, int>> adj[MAXN];
int vis[MAXN];

void dfs(int u, int &buracos, int &tam, int &maior) {
    maior = max(maior, u);
    vis[u] = 1;
    for (auto e : adj[u]) {
        buracos += e.second;
        tam++;
        if (!vis[e.first]) {
            dfs(e.first, buracos, tam, maior);
        }
    }
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int u, v, b;
        cin >> u >> v >> b;
        adj[u].push_back({v, b});
        adj[v].push_back({u, b});
    }
    memset(vis, 0, sizeof vis);
    int maior, buracos, tam;
    vector<pair<double, int>> bairros;
    for (int u = 1; u <= N; u++) {
        if (!vis[u]) {
            maior = -1, buracos = 0, tam = 0;
            dfs(u, buracos, tam, maior);
            buracos /= 2;
            tam /= 2;
            double media = buracos;
            if (buracos != 0)
                media /= tam;
            bairros.push_back({media, -maior});
        }
    }
    sort(bairros.begin(), bairros.end());
    cout << -bairros[0].second << endl;

    system("PAUSE");
    return 0;
}
