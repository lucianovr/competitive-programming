#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i(a); i < (b); i++)

#define all(c) c.begin(), c.end()
#define UNIQUE(c)                                                                                                      \
    { sort(ALL(c); (c).resize( unique(ALL(c))-c.begin() );                                               \
    }
#define pb push_back
#define D(x)                                                                                                           \
    if (1)                                                                                                             \
        cout << __LINE__ << " " << #x " = " << (x) << endl;
#define DVEC(v, n)                                                                                                     \
    {                                                                                                                  \
        cout << #v << "[] ={ ";                                                                                        \
        rep(i, 0, n) cout << v[i] << " ";                                                                              \
        cout << "}\n";                                                                                                 \
    }
#define mp make_pair
#define fst first
#define snd second

typedef pair<int, int> ii;
typedef long long ll;

typedef vector<int> vi;
typedef vector<ii> vii;

const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;

struct edge {
    int v, d, t;
    edge(int _vertice, int _dist, int _tempo) {
        v = _vertice;
        d = _dist;
        t = _tempo;
    }
};

vector<edge> adj[110];

//   Vatual  Tmin
int dist[110][6010];
int vis[110][6010];

ii dijkstra(int s, int destino, int tempo) {
    memset(dist, INF, sizeof dist);
    memset(vis, 0, sizeof vis);
    priority_queue<pair<int, ii>> Q;

    Q.push(make_pair(0, ii(s, 0)));
    dist[s][0] = 0;

    while (!Q.empty()) {
        ii top = Q.top().snd;
        Q.pop();

        int u = top.fst;
        int t = top.snd;
        if (vis[u][t])
            continue;
        vis[u][t] = 1;

        rep(i, 0, adj[u].size()) {
            edge e = adj[u][i];
            int v = e.v;
            int tt = e.t;
            int dd = e.d;

            if (dist[v][t + tt] > dist[u][t] + dd && (t + tt <= tempo)) {
                dist[v][t + tt] = dist[u][t] + dd;
                for (int ttt = t + tt; ttt <= tempo; ttt++)
                    dist[v][ttt] = min(dist[v][ttt], dist[v][t + tt]);

                Q.push(make_pair(-dist[v][t + tt], ii(v, t + tt)));
            }
        }
    }

    int menor_dist = INF, menor_tempo = INF;
    rep(t, 0, min(6001, tempo + 1)) {
        if (dist[destino][t] < menor_dist) {
            menor_dist = dist[destino][t];
            menor_tempo = t;
        }
    }
    return ii(menor_dist, menor_tempo);
}

int main() {

    int N, M, u, v, c, t;
    int inst = 1;
    while (cin >> N >> M) {
        if (N == 0 && M == 0)
            break;
        rep(i, 0, N) adj[i].clear();

        while (M--) {
            scanf("%d %d %d %d", &u, &v, &c, &t);
            u--;
            v--;
            adj[u].pb(edge(v, c, t));
        }
        int k;
        scanf("%d", &k);
        printf("Instancia %d\n", inst++);
        while (k--) {
            scanf("%d %d %d", &u, &v, &t);
            u--;
            v--;
            ii ans = dijkstra(u, v, t);
            if (ans.fst != INF)
                printf("Possivel - %d km, %d min\n", ans.fst, ans.snd);
            else
                printf("Impossivel\n");
        }
        printf("\n");
    }
    return 0;
}
