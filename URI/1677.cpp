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

#define MAX 5010
VI adj[MAX];
int in[MAX], out[MAX], dissipador[MAX], vis[MAX];

void propagate(int u) {
    if (vis[u])
        return;
    vis[u] = 1;
    for (int i = 0; i < adj[u].sz; i++) {
        int v = adj[u][i];
        dissipador[v] = 0;
        propagate(v);
    }
}

int main() {
    int n, m, x, y;
    while (cin >> n && n) {
        cin >> m;
        rep(i, 0, n) adj[i].clear(), in[i] = out[i] = 0, dissipador[i] = 1;

        while (m--) {
            scanf("%d %d", &x, &y);
            x--;
            y--; // x->y

            adj[y].pb(x);
            in[y]++;
            out[x]++;
        }

        VI ans;
        memset(vis, 0, sizeof vis);
        rep(i, 0, n) {
            if (out[i] == 0) {
                propagate(i);
            }
        }

        rep(i, 0, n) {
            if (in[i] == 0 && out[i] != 0)
                dissipador[i] = 0;
            if (dissipador[i])
                ans.pb(i);
        }

        if (ans.size() == 0)
            printf("\n");
        else
            rep(i, 0, ans.sz) {
                if (i)
                    printf(" ");
                printf("%d", ans[i] + 1);
            }
        cout << "\n";
    }
    return 0;
}
