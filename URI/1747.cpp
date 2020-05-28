#include <bits/stdc++.h>

#define INF 0x3F3F3F3F
#define rep(i, a, b) for (int i = int(a); i < int(b); i++)
#define pb push_back
#define pi 3.1415926535897932384626433832795028841971
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x, y) cout << #x << " = " << x << " --- " << #y << " " << y << "\n";
#define all(S) (S).begin(), (S).end()
#define MAXV 1005
#define F first
#define S second
#define EPS 1e-9
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

int mdc(int a, int b) {
    if (!a)
        return b;
    return mdc(b % a, a);
}
int N, E, v[10005];
map<ii, int> pd;
vector<int> adj[10005];
set<int> s;
bool um;

void dfs(int u, int gcd) {

    pd[ii(u, gcd)] = true;
    s.insert(gcd);
    if (gcd == 1)
        return;

    int t = adj[u].size();

    rep(i, 0, t) {
        int vv = adj[u][i];
        int m = v[vv];
        m = mdc(m, gcd);
        if (!pd.count(ii(vv, m)))
            dfs(vv, m);
    }
}

int main() {

    int x, y;

    //   freopen("E_9.in", "r", stdin);
    //   freopen("out.txt", "w", stdout);

    while (cin >> N >> E) {

        rep(i, 0, N + 1) adj[i].clear();

        rep(i, 1, N + 1) scanf("%d", &v[i]);

        rep(i, 0, E) {
            scanf("%d%d", &x, &y);
            adj[x].pb(y);
            adj[y].pb(x);
        }

        rep(i, 1, N + 1) {
            if (!pd.count(ii(i, v[i])))
                dfs(i, v[i]);
        }

        cout << s.size() << "\n";
        s.clear();
        pd.clear();
    }

    return 0;
}
