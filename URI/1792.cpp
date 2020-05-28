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
#define MAX 10010
int ini[MAX], refens[MAX], grau_in[MAX];
VI adj[MAX];

bool bfs(int n, int soldiers) {
    //       (inimigos, local)
    priority_queue<ii> Q;

    rep(v, 0, n) if (grau_in[v] == 0) Q.push(ii(-ini[v], -v));
    int cont = 0;

    while (!Q.empty()) {
        ii top = Q.top();
        Q.pop();
        int u = -top.second;

        if (soldiers <= ini[u])
            break; // nao consegui

        cont++;
        soldiers += refens[u];
        rep(i, 0, adj[u].sz) {
            grau_in[adj[u][i]]--;
            if (grau_in[adj[u][i]] == 0)
                Q.push(ii(-ini[adj[u][i]], -adj[u][i]));
        }
    }
    return (cont == n);
}

int main() {
    int n, m, s;
    while (cin >> n >> m >> s) {
        if (n == 0 && m == 0 && s == 0) {
            break;
        }

        rep(i, 0, n) {
            scanf("%d", &ini[i]);
            adj[i].clear();
        }
        rep(i, 0, n) {
            scanf("%d", &refens[i]);
            grau_in[i] = 0;
        }

        int a, b;
        while (m--) {
            scanf("%d %d", &a, &b);
            a--;
            b--;
            adj[a].pb(b);
            grau_in[b]++;
        }
        if (bfs(n, s))
            printf("possivel\n");
        else
            printf("impossivel\n");
    }
    return 0;
}
