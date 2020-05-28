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

#define MAX 100010
VI adj[MAX];

int topo(int a, int n1, int n2, VI grau) {
    queue<int> q[2];
    rep(i, 0, n1 + n2) {
        if (grau[i] == 0) {
            q[(i < n1 ? 0 : 1)].push(i);
        }
    }
    int trocas = 2;
    while (q[0].size() > 0 || q[1].size() > 0) {
        if (q[a].empty()) {
            a = 1 - a;
            trocas++;
        }

        int u = q[a].front();
        q[a].pop();
        for (int i = 0; i < adj[u].sz; i++) {
            int v = adj[u][i];
            grau[v]--;
            if (grau[v] == 0) {
                q[(v < n1 ? 0 : 1)].push(v);
            }
        }
    }
    return trocas;
}

int main() {
    int n1, n2, d, x, y;

    while (scanf("%d %d %d", &n1, &n2, &d) == 3) {
        VI grau(n1 + n2, 0);

        if (n1 == 0 && n2 == 0 && d == 0)
            break;
        rep(i, 0, n1 + n2) { adj[i].clear(); }
        while (d--) {
            scanf("%d %d", &x, &y);
            x--;
            y--;
            adj[y].pb(x);
            grau[x]++;
        }

        printf("%d\n", min(topo(0, n1, n2, grau), topo(1, n1, n2, grau)));
    }
    return 0;
}
