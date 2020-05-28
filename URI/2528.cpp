#include <bits/stdc++.h>
using namespace std;

vector<int> adj[1123];
int dist[1123];
int fila[1123], ini, fim;
int N;

int bfs(int s, int d, int e) {
    dist[s] = 0;
    fila[ini = fim = 0] = s;
    fim++;
    while (ini <= fim) {
        int v = fila[ini++];
        if (v == d)
            break;
        for (int i = 0; i < adj[v].size(); i++) {
            int u = adj[v][i];
            if (u == e || dist[u] != -1)
                continue;
            dist[u] = dist[v] + 1;
            fila[fim++] = u;
        }
    }
    return dist[d];
}

int main() {
    int A;
    while (cin >> N >> A) {
        for (int i = 0; i < N; i++) {
            adj[i].clear();
            dist[i] = -1;
        }
        int x, y, z;
        while (A--) {
            scanf("%d %d", &x, &y);
            x--;
            y--;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        scanf("%d %d %d", &x, &y, &z);
        x--, y--, z--;
        printf("%d\n", bfs(x, y, z));
    }
    return 0;
}