#include <bits/stdc++.h>

#define INF 0x3F3F3F3F
#define rep(i, a, b) for (int i = int(a); i < int(b); i++)
#define pb push_back
#define clr(a) memset((a), 0, sizeof(a))
#define pi 3.1415926535897932384626433832795028841971
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x, y) cout << #x << " = " << x << " --- " << #y << " " << y << "\n";
#define all(S) (S).begin(), (S).end()
#define MAXV 1005
#define F first
#define S second
#define EPS 1e-9
#define mp make_pair

// freopen("in.txt", "r", stdin);
// freopen("out.txt", "w", stdout);

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int N, M, F, P;
int peso[1002];
vector<int> adj[1002];
int dist[1002];
bool vis[1002];

void dijkstra(int ini) {

    priority_queue<ii> pq;

    memset(vis, false, sizeof(vis));
    memset(dist, INF, sizeof dist);

    dist[ini] = 0;
    pq.push(ii(0, ini));

    while (!pq.empty()) {

        int u = pq.top().second;
        pq.pop();

        if (vis[u])
            continue;
        vis[u] = true;

        for (int i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i];
            if (dist[v] > dist[u] + peso[v]) {
                dist[v] = dist[u] + peso[v];
                pq.push(ii(-dist[v], v));
            }
        }
    }
}

void dfs(int u, int atk, int c, bool f) {
    if (c < 0 || u == F)
        return;
    vis[u] = true;
    peso[u] += atk;

    //	if(f)
    //	printf("vis - %d\n",u);

    for (int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        if (!vis[v]) {
            dfs(v, atk, c - 1, f);
        }
    }
}

int main() {

    int T, x, y;
    int V, A, C, H, Q;

    scanf("%d", &T);

    for (int t = 1; t <= T; t++) {

        scanf("%d%d%d", &N, &M, &F);
        rep(i, 1, N + 1) adj[i].clear();

        while (M--) {
            scanf("%d%d", &x, &y);
            adj[x].pb(y);
            adj[y].pb(x);
        }

        scanf("%d", &P); // P torres
        memset(peso, 0, sizeof peso);

        rep(i, 0, P) {
            scanf("%d%d%d", &V, &A, &C); // vertice, ataque, comprimento
            memset(vis, false, sizeof vis);
            int xx = 0;
            if (V == 6)
                xx = 1;
            dfs(V, A, C, xx);
        }
        dijkstra(F);

        scanf("%d", &Q);

        int count = 0;
        rep(i, 0, Q) {
            scanf(" %d %d", &V, &H);
            if (dist[V] < H)
                count++;
        }
        printf("Caso #%d: %d\n", t, count);
    }

    return 0;
}
