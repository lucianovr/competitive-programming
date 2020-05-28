#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define rep(i, a, b) for (int i(a); i < (b); i++)
#define debug(x) cout << #x << " = " << x << "\n";

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int dist[1010][1010];
bool vis[1010][1010];

vii adj[1010];
const int INF = 0x3f3f3f3f;

int dijkstra(int N, int K) {
    rep(i, 0, N + 1) rep(j, 0, N + 1) {
        dist[i][j] = INF;
        vis[i][j] = false;
    }

    priority_queue<pair<int, ii>> pq;
    pq.push(make_pair(dist[0][1] = 0, ii(0, 1)));
    while (!pq.empty()) {
        ii top = pq.top().second;
        pq.pop();
        int u = top.first, k = top.second;

        if (vis[u][k] || k > K)
            continue;
        vis[u][k] = true;

        rep(i, 0, adj[u].size()) {
            int v = adj[u][i].first, cost = adj[u][i].second;
            if (dist[v][k + 1] > dist[u][k] + cost) {
                dist[v][k + 1] = dist[u][k] + cost;
                pq.push(make_pair(-dist[v][k + 1], ii(v, k + 1)));
            }
        }
    }
    int ans = INF;
    rep(i, 2, K + 1) ans = min(ans, dist[N - 1][i]);
    return ans;
}

int main() {
    int t, n, m, k, a, b, w;
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d %d", &n, &m, &k);
        rep(i, 0, n) adj[i].clear();
        while (m--) {
            scanf("%d %d %d", &a, &b, &w);
            adj[a].pb(ii(b, w));
        }
        int ret = dijkstra(n, k);
        if (ret == INF)
            ret = -1;
        printf("%d\n", ret);
    }
    return 0;
}
