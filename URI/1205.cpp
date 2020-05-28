#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <string.h>
#include <utility>
#include <vector>
using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define rep(i, n) for (int i = 0; i <= (n); i = i + 1)
#define tr(it, S) for (typeof(S.begin()) it = S.begin(); it != S.end(); it++)
#define all(S) (S).begin(), (S).end()
#define setar(S, x) memset(S, x, sizeof(S))
#define pb push_back
#define sz size()
#define inf 1000000000
int peso[1010];
vi g[1010];

int dijkstra(int n, int s, int e) {
    vi dist(n + 1, inf), vis(n + 1, 0);
    dist[s] = 0;
    while (s != e) {
        vis[s] = 1;
        int u;
        for (int i = 0, j = g[s].sz; i < j; i++) {
            u = g[s][i];
            if (dist[u] > dist[s] + peso[u])
                dist[u] = dist[s] + peso[u];
        }
        int me = inf;
        rep(i, n) {
            if (!vis[i] && me > dist[i]) {
                u = i;
                me = dist[i];
            }
        }
        if (me == inf)
            return -1;
        s = u;
    }
    return dist[e];
}

int main() {
    int n, m, k;
    double p;
    while (cin >> n >> m >> k >> p) {
        int x, y;
        rep(i, n) g[i].clear();
        while (m--) {
            cin >> x >> y;
            g[x].pb(y);
            g[y].pb(x);
        }
        int a;
        cin >> a;
        rep(i, n) peso[i] = 0;
        while (a--) {
            cin >> x;
            peso[x]++;
        }
        cin >> x >> y;
        g[0].pb(x);
        int c = dijkstra(n, 0, y);
        if (c > k || c == -1)
            cout << "0.000\n";
        else {
            double resp = 1;
            while (c--)
                resp *= p;
            cout << fixed << setprecision(3) << resp << endl;
        }
    }
    return 0;
}
