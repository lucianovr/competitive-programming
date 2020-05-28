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

#define MAX 10000
int n, pai[MAX], cont, keys[MAX];
VI adj[MAX], sala[MAX];

int find(int x) {
    if (x != pai[x])
        pai[x] = find(pai[x]);
    return pai[x];
}

void join(int a, int b) {
    a = find(a);
    b = find(b);
    pai[b] = a;
}

bool same(int a, int b) { return find(a) == find(b); }

void dfs(int u) {
    keys[u] = 0; // usei a chave que abre a sala U

    cont++;
    if (cont == n)
        return;

    rep(i, 0, adj[u].size()) join(u, adj[u][i]); // os corredores estao conectados
    rep(i, 0, sala[u].size()) keys[sala[u][i]] = 1;

    rep(i, 1, n + 1) if (keys[i] == 1 && same(i, u)) dfs(i);
}

int main() {
    int m, a, b;
    while (scanf("%d %d", &n, &m) == 2) {
        rep(i, 1, n + 1) adj[i].clear(), sala[i].clear(), pai[i] = i;

        while (m--) {
            scanf("%d %d", &a, &b);
            adj[a].pb(b);
            adj[b].pb(a);
        }

        for (int i = 2; i <= n; i++) {
            scanf("%d", &a);
            sala[a].pb(i);
        }
        memset(keys, 0, sizeof keys);
        cont = 0;
        dfs(1);

        printf("%s\n", cont == n ? "sim" : "nao");
    }
    return 0;
}
