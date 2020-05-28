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

vector<ii> adj[10000 + 10];

int dist[10000 + 10];
void dijkstra(int s, int N) {
    rep(i, 1, N + 1) dist[i] = INF;
    priority_queue<ii> pq;
    pq.push(ii(dist[s] = 0, s));

    while (!pq.empty()) {
        ii top = pq.top();
        pq.pop();

        s = top.second;
        if (-top.first != dist[s])
            continue;

        int t = adj[s].size();
        rep(i, 0, t) {
            int v = adj[s][i].first;
            int cost = adj[s][i].second;
            if (dist[v] > dist[s] + cost) {
                dist[v] = dist[s] + cost;
                pq.push(ii(-dist[v], v));
            }
        }
    }
}

void addEdges(const vector<pair<ii, int>> &E) {
    int t = E.size(), a, b, c;
    rep(i, 0, t) {
        a = E[i].first.first;
        b = E[i].first.second;
        c = E[i].second;
        adj[a].pb(ii(b, c));
        adj[b].pb(ii(a, c));
    }
}

int main() {
    int N, C, S, B, K, F;
    vector<pair<ii, int>> E1, E2;
    vector<int> b;
    int u, v, c;
    while (scanf("%d %d %d %d", &N, &C, &S, &B) == 4) {
        E1.clear();
        E2.clear();
        b.clear();

        rep(i, 0, C) {
            scanf("%d %d %d", &u, &v, &c);
            E1.pb(make_pair(ii(u, v), c));
        }
        rep(i, 0, S) {
            scanf("%d %d %d", &u, &v, &c);
            E2.pb(make_pair(ii(u, v), c));
        }
        rep(i, 0, B) {
            scanf("%d", &v);
            b.pb(v);
        }

        scanf("%d %d", &K, &F);

        rep(i, 1, N + 1) adj[i].clear();
        addEdges(E1);
        dijkstra(F, N);
        int dkf = dist[K];

        addEdges(E2);
        dijkstra(F, N);
        int ans = 0;
        for (int i = 0; i < B; i++) {
            if (dist[b[i]] <= dkf)
                ans++;
        }

        printf("%d\n", ans);
    }
    return 0;
}
