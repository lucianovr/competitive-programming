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

#define MAXV 10 + 5

vector<ii> adj[MAXV];
int preco[MAXV], vis[MAXV], N, T, M, resp;

void back_track(int u, int t, int custo) {
    if (custo > resp)
        return;
    if (u == N - 1) {
        if (custo < resp)
            resp = custo;
    }

    for (int i = 0; i < adj[u].sz; i++) {
        int v = adj[u][i].first;
        int gasta = adj[u][i].second;

        if (!vis[v]) {
            vis[v] = 1;
            for (int l = 0; l <= T - t; l++) {
                if (t + l - gasta >= 0) {
                    back_track(v, t + l - gasta, custo + l * preco[u]);
                }
            }
            vis[v] = 0;
        }
    }
}

int main() {
    int a, b, c;

    while (scanf("%d %d %d", &N, &M, &T) == 3) {
        if (N == 0 && M == 0 && T == 0)
            break;

        rep(i, 0, N) adj[i].clear();

        rep(i, 0, M) {
            scanf("%d %d %d", &a, &b, &c);
            a--;
            b--;
            adj[a].pb(ii(b, c));
            adj[b].pb(ii(a, c));
        }
        rep(i, 0, N) scanf("%d", &preco[i]);

        resp = 0x3f3f3f3f;
        vis[0] = 1;
        back_track(0, T, 0);
        printf("%d\n", resp == 0x3f3f3f3f ? -1 : resp);
    }
    return 0;
}
