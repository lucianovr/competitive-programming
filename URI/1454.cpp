#include <iostream>
#include <queue>
#include <string.h>
#include <utility>
#include <vector>
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
#define rep(i, n) for (int i = 0, leng = n; i < leng; i++)
#define pb push_back
#define inf 1000000000
int grafo[500][500];

int dijkstra(int n, int s, int d) {
    vi dist(n, inf), vis(n, 0);
    priority_queue<ii> fila;

    dist[s] = -inf;
    fila.push(ii(-inf, s));

    while (!fila.empty()) {
        s = fila.top().second;
        fila.pop();
        if (!vis[s]) {
            vis[s] = 1;
            rep(i, n) {
                if (grafo[s][i] != inf) {
                    if (dist[i] > max(dist[s], grafo[s][i])) {
                        dist[i] = max(dist[s], grafo[s][i]);
                        fila.push(ii(-dist[i], i));
                    }
                }
            }
        }
    }
    return dist[d];
}

int main() {
    int n, m, inst = 1;
    while (cin >> n >> m && n + m) {
        int x, y, w;
        rep(i, n) rep(j, m) grafo[i][j] = inf;
        while (m--) {
            cin >> x >> y >> w;
            grafo[x - 1][y - 1] = w;
            grafo[y - 1][x - 1] = w;
        }
        int k;
        cin >> k;
        cout << "Instancia " << inst++ << endl;
        while (k--) {
            cin >> x >> y;
            if (x == y)
                cout << 0 << endl;
            else
                cout << dijkstra(n, x - 1, y - 1) << endl;
        }
        cout << endl;
    }
}