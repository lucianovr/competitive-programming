#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i(a); i < (b); i++)
#define debug(x) cout << #x << " = " << x << "\n";

#define ALL(c) c.begin(), c.end()
#define SORT(c) sort(ALL(c))
#define UNIQUE(c)                                                                                                      \
    {                                                                                                                  \
        SORT(c);                                                                                                       \
        (c).resize(unique(ALL(c)) - c.begin());                                                                        \
    }
#define pb push_back
#define sz size()
#define D(x)                                                                                                           \
    if (1)                                                                                                             \
        cout << __LINE__ << " " << #x " = " << (x) << endl;
#define D2(x, y)                                                                                                       \
    if (1)                                                                                                             \
        cout << __LINE__ << " " << #x " = " << (x) << ", " << #y " = " << (y) << endl;

typedef pair<int, int> ii;
typedef vector<int> VI;
typedef vector<ii> VII;
typedef long long LL;

int N, A, B, C;
VI adj[10000];
int dist[10000], dist2[10000], pai[10000];
;
const int INF = 0x3f3f3f3f;

void dfs(int u) {
    int v;
    rep(i, 0, adj[u].sz) {
        v = adj[u][i];
        if (dist[v] == -1) {
            dist[v] = dist[u] + 1;
            pai[v] = u;
            dfs(v);
        }
    }
}
void dfs2(int u) {
    int v;
    rep(i, 0, adj[u].sz) {
        v = adj[u][i];
        if (dist2[v] == -1) {
            dist2[v] = dist2[u] + 1;
            dfs2(v);
        }
    }
}

int main() {
    int x, y;
    while (cin >> N >> A >> B >> C) {

        A--;
        B--;
        C--;
        rep(i, 0, N) adj[i].clear();

        rep(i, 0, N - 1) {
            cin >> x >> y;
            x--;
            y--;
            adj[x].pb(y);
            adj[y].pb(x);
        }

        memset(dist, -1, sizeof dist);
        memset(pai, -1, sizeof pai);
        dist[C] = 0;
        dfs(C);

        VI path;
        int end = B;
        while (end != -1) {
            path.pb(end);
            end = pai[end];
        }
        //	reverse(ALL(path));
        //	rep(i,0,path.sz) cout << path[i] << "->"; cout << "\n";

        memset(dist2, -1, sizeof dist2);
        dist2[A] = 0;
        dfs2(A);

        int u = A, Min = INF;
        rep(i, 0, path.size()) {
            if (dist2[path[i]] < Min) {
                Min = dist2[path[i]];
                u = path[i];
            }
        }

        double Dcu = dist[u];
        double Dcb = dist[B];

        printf("%.6lf\n", Dcu / Dcb);
    }
    return 0;
}
