#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i(a); i < (b); i++)

#define ALL(c) c.begin(), c.end()
#define UNIQUE(c)                                                                                                      \
    { sort(ALL(c); (c).resize( unique(ALL(c))-c.begin() );                                               \
    }
#define pb push_back
#define sz size()
#define D(x)                                                                                                           \
    if (1)                                                                                                             \
        cout << __LINE__ << " " << #x " = " << (x) << endl;

typedef pair<int, int> ii;
typedef long long ll;

const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;

#define MAX 200100

vector<ii> adj[MAX];
int dist[MAX];
bool vis[MAX];

void dijkstra(int s, int N) {

    rep(u, 0, N + 2) {
        dist[u] = INF;
        vis[u] = false;
    }
    priority_queue<pair<int, int>> pq;

    dist[s] = 0;
    pq.push(make_pair(0, s));

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        //	D(u);
        if (vis[u])
            continue;
        vis[u] = true;

        for (int i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i].first;
            int duv = adj[u][i].second;

            if (dist[v] > dist[u] + duv) {
                dist[v] = dist[u] + duv;
                pq.push(make_pair(-dist[v], v));
            }
        }
    }
}

#define left(x) x * 2 - 1
#define right(x) x * 2

int main() {
    int n, m;
    int u, v, w;

    while (scanf("%d %d", &n, &m) == 2) {

        rep(i, 0, 2 * n + 2) adj[i].clear();

        while (m--) {
            scanf("%d %d %d", &u, &v, &w);

            adj[left(u)].pb(ii(right(v), w));
            adj[right(u)].pb(ii(left(v), w));

            adj[left(v)].pb(ii(right(u), w));
            adj[right(v)].pb(ii(left(u), w));
        }

        dijkstra(right(1), right(n));
        int ret = dist[right(n)];

        if (ret == INF)
            ret = -1;

        printf("%d\n", ret);
    }
    return 0;
}
