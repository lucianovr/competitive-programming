#include <bits/stdc++.h>
using namespace std;

#define MAXN 1123
#define INF 0x3f3f3f3f
vector<pair<int, int>> adj[MAXN];

int N, M;

int prim() {
    int mst = 0;
    int vis = 0;
    vector<int> dist(N, INF);
    vector<bool> visited(N, false);
    dist[0] = 0;
    priority_queue<pair<int, int>> pq;
    pq.push(make_pair(0, 0));
    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first * (-1);
        pq.pop();

        if (d > dist[u])
            continue;

        mst += d;
        visited[u] = true;
        vis++;
        for (int i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i].first;
            int w = adj[u][i].second;

            if (dist[v] > w && !visited[v]) {
                dist[v] = w;
                pq.push(make_pair(-w, v));
            }
        }
    }

    if (vis != N)
        return -1;
    else
        return mst;
}

int main() {
    while (scanf("%d %d", &N, &M) == 2) {
        for (int i = 0; i < N; i++)
            adj[i].clear();

        while (M--) {
            int u, v, w;
            scanf("%d %d %d", &u, &v, &w);
            u--, v--;
            adj[u].push_back(make_pair(v, w));
            adj[v].push_back(make_pair(u, w));
        }
        int ret = prim();
        if (ret == -1)
            printf("impossivel\n");
        else
            printf("%d\n", ret);
    }
    return 0;
}