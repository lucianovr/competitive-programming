#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <queue>
#include <string.h>
#include <string>
#include <utility>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<int, ll> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define rep(i, n) for (int i = 0; i < (n); i = i + 1)
#define tr(it, S) for (typeof(S.begin()) it = S.begin(); it != S.end(); it++)
#define all(S) (S).begin(), (S).end()
#define setar(S, x) memset(S, x, sizeof(S))
#define pb push_back
#define contem(s, x) (s.find(x) != s.end())
#define MAXV 200000
#define inf 1000000000
vii ladj[MAXV];

ll prim(int n) {
    ll ans = 0LL;
    vector<ll> D(n, inf);
    vi vis(n, 0);
    priority_queue<pair<ll, int>> Q;
    D[0] = 0;
    Q.push(make_pair(0, 0));
    int sz;

    while (!Q.empty()) {
        pair<ll, int> top = Q.top();
        Q.pop();
        int u = top.second;
        ll d = -top.first;

        if (!vis[u]) {
            ans += d;
            vis[u] = 1;
            sz = ladj[u].size();
            rep(i, sz) {
                int v = ladj[u][i].first;
                ll cost = ladj[u][i].second;

                if (!vis[v] && D[v] > cost) {
                    D[v] = cost;
                    Q.push(make_pair(-D[v], v));
                }
            }
        }
    }
    return ans;
}

int main() {
    // nos e arestas
    int m, n, x, y;
    ll z;
    while (cin >> m >> n && m + n) {
        ll acc = 0LL;
        rep(i, n) {
            cin >> x >> y >> z;
            ladj[x].pb(ii(y, z));
            ladj[y].pb(ii(x, z));
            acc += z;
        }
        cout << acc - prim(m) << endl;
        rep(i, MAXV) ladj[i].clear();
    }
    return 0;
}