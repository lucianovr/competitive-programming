#include <bits/stdc++.h>

#define rep(i, a, b) for (int i = a; i < b; i++)
using namespace std;

const double EPS = 1e-9;
typedef pair<int, int> ii;

#define N 1000
vector<pair<int, ii>> g[N];

int dijkstra(int v, int src, int dest, int t) {
    vector<int> dist(v, 0x3f3f3f3f);
    priority_queue<ii> pq;
    pq.push({dist[src] = 0, src});

    while (!pq.empty()) {
        auto top = pq.top();
        pq.pop();

        auto u = top.second;
        auto d = -top.first;
        if (d > dist[u])
            continue;
        for (auto e : g[u]) {
            int viz = e.first;
            int tipo = e.second.first;
            int cost = e.second.second;
            if (tipo == t) {
                if (dist[viz] > dist[u] + cost) {
                    dist[viz] = dist[u] + cost;
                    pq.push({-dist[viz], viz});
                }
            }
        }
    }
    return dist[dest];
}

int main() {
    int v, a;
    while (cin >> v >> a) {
        for (unsigned int i = 0; i < v; i += 1) {
            g[i].clear();
        }

        while (a--) {
            int x, y, t, r;
            cin >> x >> y >> t >> r;
            x--, y--;
            g[x].push_back({y, {t, r}});
        }
        cout << min(dijkstra(v, 0, v - 1, 0), dijkstra(v, 0, v - 1, 1)) << "\n";
    }
    return 0;
}
