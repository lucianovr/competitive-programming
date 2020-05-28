#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(c) (c).begin(), (c).end()
#define F first
#define S second
#define debug(x) cout << __LINE__ << ": " << #x << " = " << x << endl;
#define debug2(x, y) cout << #x << " = " << x << "  " << #y << " = " << y << endl;
#define pb push_back
#define mk make_pair

const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;
typedef long long ll;
typedef pair<int, int> ii;

#define N 1123
vector<int> adj[N];
vector<int> E[N];
bool leaf[N];
const ll mod = 1e9 + 7LL;

ll mult(ll a, ll b) { return ((a % mod) * (b % mod)) % mod; }

ll add(ll a, ll b) { return ((a % mod) + (b % mod)) % mod; }

ll dp[N][2][2][2];
/*
    v = actual vertex
    p = parent node
    k = k-esima edge of v
    cv = is v colored?
    cp = is parent colored?
    filho = algum filho de v ja foi colorido
*/
ll s(int v, int p, int k, int cv, int cp, int esq) {
    if (leaf[v])
        return (cv == 1 || cp == 1);
    if (k == E[v].size()) {
        return (cv == 1 || cp == 1 || esq == 1);
    }
    int x = E[v][k];
    if (x == p)
        return s(v, p, k + 1, cv, cp, esq);
    int cx;

    ll &ways = dp[E[v][k]][cv][cp][esq];
    if (ways > -1)
        return ways;

    // nao colorir x
    cx = 0;
    ways = mult(s(x, v, 0, cx, cv, 0), s(v, p, k + 1, cv, cp, esq));

    // colorir x
    cx = 1;
    ways = add(ways, mult(s(x, v, 0, cx, cv, 0), s(v, p, k + 1, cv, cp, 1)));

    return ways;
}

void dfs(int u, int p) {
    rep(i, 0, adj[u].size()) {
        int viz = adj[u][i];
        if (viz != p) {
            E[u].pb(viz);
            dfs(viz, u);
        }
    }
}
void init(int V) {
    for (int i = 0; i <= V; i++) {
        adj[i].clear();
        E[i].clear();
    }
}
int main() {

    int V;
    while (scanf("%d", &V) == 1) {
        init(V);
        for (int i = 0; i < V - 1; i++) {
            int x, y;
            scanf("%d %d", &x, &y);
            adj[x].pb(y);
            adj[y].pb(x);
        }
        dfs(1, -1);
        for (int v = 1; v <= V; v++) {
            leaf[v] = (E[v].size() == 0);
        }
        memset(dp, -1, sizeof dp);
        cout << add(s(1, -1, 0, 0, 0, 0), s(1, -1, 0, 1, 0, 0)) << "\n";
    }

    return 0;
}
