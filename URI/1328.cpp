#include <bits/stdc++.h>

#define INF 0x3F3F3F3F
#define rep(i, a, b) for (int i = int(a); i < int(b); i++)
#define pb push_back
#define pi 3.1415926535897932384626433832795028841971
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x, y) cout << #x << " = " << x << " --- " << #y << " " << y << "\n";
#define debugM(x, l, c)                                                                                                \
    {                                                                                                                  \
        rep(i, 0, l) {                                                                                                 \
            rep(j, 0, c) printf("%d ", x[i][j]);                                                                       \
            printf("\n");                                                                                              \
        }                                                                                                              \
    }
#define all(S) (S).begin(), (S).end()
#define MAXV 1010000
#define MAXN 110
#define F first
#define S second
#define EPS 1e-9
#define mk make_pair

using namespace std;

typedef pair<int, int> ii;
typedef long long int ll;

ll readInt();

vector<ii> adj[110];

int dijkstra(int ini, int fim) {

    priority_queue<ii> pq;
    vector<int> dist(110, INF);
    vector<bool> vis(110, 0);
    pq.push(ii(0, ini));
    dist[ini] = 0;

    while (!pq.empty()) {
        int u = pq.top().S;
        pq.pop();
        if (vis[u])
            continue;
        vis[u] = 1;
        if (u == fim)
            return dist[u];
        rep(i, 0, adj[u].size()) {
            int v = adj[u][i].F;
            int d_u_v = adj[u][i].S;
            if (dist[v] > dist[u] + d_u_v) {
                dist[v] = dist[u] + d_u_v;
                pq.push(ii(-dist[v], v));
            }
        }
    }

    return -1;
}

int main() {

    int z, s, k, u, Z[110], t, b, v[110], x, y;

    while (scanf("%d%d", &z, &s) != EOF) {
        if (!z && !s)
            break;
        rep(i, 0, s + 1) adj[i].clear();
        rep(i, 0, z) {
            scanf("%d", &k);
            rep(j, 0, k) {
                scanf("%d", &u);
                Z[u] = i;
            }
        }
        scanf("%d%d", &t, &b);
        rep(i, 0, t) {
            scanf("%d", &k);
            rep(j, 0, k) { scanf("%d", &v[j]); }
            rep(j, 0, k) {
                int cost = 0;
                rep(l, j + 1, k) {
                    if (Z[v[l]] != Z[v[l - 1]])
                        cost += 4;
                    adj[v[j]].pb(ii(v[l], cost));
                    adj[v[l]].pb(ii(v[j], cost));
                }
            }
        }
        rep(i, 0, b) {
            scanf("%d", &k);
            rep(j, 0, k) { scanf("%d", &v[j]); }
            rep(j, 0, k) {
                int cost = 1;
                rep(l, j + 1, k) {
                    adj[v[j]].pb(ii(v[l], cost));
                    adj[v[l]].pb(ii(v[j], cost));
                }
            }
        }
        scanf("%d%d", &x, &y);
        printf("%d\n", dijkstra(x, y) + 2);
    }
}
