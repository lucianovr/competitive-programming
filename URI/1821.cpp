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

#define WHITE 0
#define GRAY 1
#define MAXN 110

int cor[MAXN], match[MAXN];
VI adj[MAXN], path;

int aug(int u) {
    if (cor[u] == WHITE) {
        cor[u] = GRAY;
        rep(i, 0, adj[u].size()) {
            int v = adj[u][i];
            int w = match[v];
            path.pb(v);

            if (w == -1)
                return 1;
            else {
                if (aug(w))
                    return 1;
                else
                    path.pop_back();
            }
        }
    }
    return 0;
}

int matching(int N) {
    int u, v, w, flow = 0;
    for (int i = 1; i <= N; i++)
        match[i] = -1;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++)
            cor[j] = WHITE;
        path.clear();
        flow += aug(i);

        // update path
        u = i;
        rep(j, 0, path.size()) {
            w = path[j];
            v = match[w];
            match[w] = u;
            u = v;
        }
    }
    return flow;
}

int main() {
    int inst = 1, n, m, mat[110][110], a, b;

    while (scanf("%d %d", &n, &m) == 2) {
        if (n == 0 && m == 0)
            break;

        rep(i, 1, n + 1) rep(j, 1, n + 1) mat[i][j] = 1;
        while (m--) {
            scanf("%d %d", &a, &b);
            mat[a][b] = 0;
        }
        rep(i, 1, n + 1) adj[i].clear();
        rep(i, 1, n + 1) rep(j, 1, n + 1) if (mat[i][j]) adj[i].pb(j);

        printf("Instancia %d\n", inst++);

        int ret = matching(n);

        printf("%s\n\n", ret == n ? "possivel" : "impossivel");
    }
    return 0;
}
