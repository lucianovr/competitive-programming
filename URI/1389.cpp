#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(c) (c).begin(), (c).end()
#define F first
#define S second
#define debug(x) cout << __LINE__ << ": " << #x << " = " << x << endl;
#define debug2(x, y) cout << #x << " = " << x << "  " << #y << " = " << y << endl;
#define pb push_back
#define mp make_pair

#define MAX 1000
int N, C, V;
int adj[MAX][MAX];
int g[MAX][MAX];
int grau[MAX];

bool conexo() {
    vector<int> vis(V, 0);
    queue<int> fila;

    fila.push(C + 0); // primeira cidade
    vis[C + 0] = 1;

    while (!fila.empty()) {
        int u = fila.front();
        fila.pop();
        for (int v = 0; v < V; v++)
            if (adj[u][v] != 0) {
                if (!vis[v]) {
                    vis[v] = 1;
                    fila.push(v);
                }
            }
    }

    for (int i = 0; i < N; i++) // para cada cidade
        if (!vis[C + i])
            return false;
    return true;
}

void dfs(int v, vector<int> &path) {
    for (int i = 0; i < V; ++i) {
        if (g[v][i] != 0) {
            g[v][i]--;
            g[i][v]--; // -> caso o grafo seja nao-direcionado!
            dfs(i, path);
        }
    }
    path.push_back(v);
}

int eulerian_circuit(int v, int ultimo) {
    vector<int> path, aux;
    int menor = 1000000000;

    for (int u = 0; u < V; u++) // para cada vizinho de v
    {
        if (g[v][u] != 0) {
            g[v][u]--;
            g[u][v]--;

            aux.clear();
            dfs(u, aux);
            aux.pb(v);
            reverse(all(aux));

            set<int> st;
            for (auto w : aux) {
                // cout << w << "->";
                if (w >= C)
                    st.insert(w);
            } // cout<< "\n";
            if (st.size() == N)
                return aux[1];
            // cout << st.size() << " sz\n";

            if (aux[1] < menor && aux.back() != ultimo)
                menor = aux[1];
        }
    }
    return menor;
}
int solve() {
    if (!conexo()) {
        // cout << "nao conexo\n";
        return -1;
    }

    vector<int> impar;
    for (int u = 0; u < N + C; ++u)
        if (grau[u] % 2 == 1)
            impar.pb(u);

    if (impar.size() == 0)
        return 0;
    if (impar.size() != 2) {
        // cout << "nao atravessavel\n";
        return -1;
    }

    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            g[i][j] = adj[i][j];
    int a1 = eulerian_circuit(impar[0], impar[1]);

    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            g[i][j] = adj[i][j];
    int b1 = eulerian_circuit(impar[1], impar[0]);
    return min(a1, b1) - C;
}

void init() {
    V = N + C;
    memset(adj, 0, sizeof adj);
    memset(grau, 0, sizeof grau);
}

int main() {
    while (scanf("%d %d", &N, &C) && N + C) {
        init();

        for (int u = 0, v, k; u < C; u++) {
            scanf("%d", &k);
            while (k--) {
                scanf("%d", &v);
                v += C;
                adj[u][v]++;
                adj[v][u]++;
                grau[u]++;
                grau[v]++;
            }
        }

        for (int v = C; v < C + N; ++v) {
            if (grau[v] == 1) {
                for (int u = 0; u < C; u++) {
                    if (adj[u][v]) {
                        adj[u][v]++;
                        adj[v][u]++;
                        grau[u]++;
                        grau[v]++;
                    }
                }
            }
        }
        cout << solve() << "\n";
    }
    return 0;
}