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

int dist[4010];
map<string, int> mp;

VI adj[4010];

void bfs(int u, int n) {
    int v;
    for (int i = 1; i <= n; i++)
        dist[i] = -1;
    dist[u] = 0;

    queue<int> q;
    q.push(u);

    while (!q.empty()) {
        u = q.front();
        q.pop();
        for (int i = 0; i < adj[u].sz; i++) {
            v = adj[u][i];
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
}

int main() {
    char a[1000], b[1000];
    int n, m;
    while (scanf("%d %d", &n, &m) == 2) {
        rep(i, 0, 4010) adj[i].clear();

        int k = 0;
        mp.clear();

        while (m--) {
            scanf(" %s %s", a, b);
            if (!mp[a])
                mp[a] = ++k;
            if (!mp[b])
                mp[b] = ++k;

            adj[mp[a]].pb(mp[b]);
            adj[mp[b]].pb(mp[a]);
        }
        bfs(mp["*"], k);

        printf("%d\n", dist[mp["Entrada"]] + dist[mp["Saida"]]);
    }

    return 0;
}
