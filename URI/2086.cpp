#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i(a); i < (b); i++)

#define all(c) c.begin(), c.end()
#define SORT(c) sort(all(c))
#define UNIQUE(c)                                                                                                      \
    {                                                                                                                  \
        SORT(c);                                                                                                       \
        (c).resize(unique(all(c)) - c.begin());                                                                        \
    }
#define pb push_back
#define sz(c) ((int)(c.size()))
#define fst first
#define snd second
#define clr(x) memset(x, 0, sizeof x)
#define nulo(x) memset(x, -1, sizeof x)
#define debug(x) cout << #x << " = " << x << "\n";
#define debug2(x, y) cout << #x << " = " << x << "  " << #y << " = " << y << "\n";
#define debugV(v)                                                                                                      \
    {                                                                                                                  \
        cout << #v << "[] = ";                                                                                         \
        rep(i, 0, sz(v)) cout << v[i] << " ";                                                                          \
        cout << "\n";                                                                                                  \
    }

typedef pair<int, int> ii;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef map<string, int> msi;
typedef map<string, string> mss;

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

int main() {
    int n, m, u, v, w, g[110][110];
    while (scanf("%d%d", &n, &m) > 0) {
        if (n == 0 && m == 0)
            break;

        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                g[i][j] = 0x3f3f3f3;
        for (int i = 1; i <= n; i++)
            g[i][i] = 0;

        while (m--) {
            scanf(" %d %d %d", &u, &v, &w);
            g[u][v] = w;
            g[v][u] = w;
        }

        for (int k = 1; k <= n; k++)
            for (int i = 1; i <= n; i++)
                if (g[i][k])
                    for (int j = 1; j <= n; j++)
                        g[i][j] = min(g[i][j], max(g[i][k], g[k][j]));

        int q;
        scanf(" %d", &q);
        while (q--) {
            scanf(" %d %d", &u, &v);
            printf("%d\n", g[u][v]);
        }
    }
    return 0;
}
