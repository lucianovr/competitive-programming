#include <bits/stdc++.h>
using namespace std;
#define f(i, a, b) for (int i = (a); i < (b); i++)
#define all(c) (c).begin(), (c).end()
#define F first
#define S second
#define debug(x) cout << __LINE__ << ": " << #x << " = " << x << endl;
#define debug2(x, y) cout << #x << " = " << x << "  " << #y << " = " << y << endl;
#define pb push_back
#define mp make_pair

const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<vector<int>> vvi;

#define MAXV 1123
int dist[MAXV], pi[MAXV]; // dist from s and pointer to parent
vii adj[MAXV];            // edge = {v, dist}

int dijkstra(vector<int> city) {
    priority_queue<pii> pq;
    memset(dist, INF, sizeof dist); // INF eh suficiente?

    f(i, 0, city.size()) {
        int s = city[i];
        pq.push(mp(dist[s] = 0, s));
    }
    int resp = -1;
    while (!pq.empty()) {
        pii top = pq.top();
        pq.pop();
        int u = top.second, d = -top.first;
        if (d != dist[u])
            continue;

        resp = max(resp, dist[u]);
        f(i, 0, (int)adj[u].size()) {
            int v = adj[u][i].F;
            int cost = adj[u][i].S;
            if (dist[v] > dist[u] + cost) {
                dist[v] = dist[u] + cost;
                pq.push(mp(-dist[v], v));
            }
        }
    }
    return resp;
}

int main() {

    int N, M, Q;
    while (scanf("%d %d %d", &N, &M, &Q) == 3) {
        int a, b, w;
        f(i, 0, N + 1) adj[i].clear();
        while (M--) {
            scanf("%d %d %d", &a, &b, &w);
            a--, b--;
            adj[a].pb(mp(b, w));
            adj[b].pb(mp(a, w));
        }
        vi city(Q);
        f(i, 0, Q) {
            scanf("%d", &city[i]);
            city[i]--;
        }
        printf("%d\n", dijkstra(city));
    }

    return 0;
}