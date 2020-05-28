#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define rep(i, n) for (int i = 0; i < (n); i = i + 1)
#define tr(it, S) for (typeof(S.begin()) it = S.begin(); it != S.end(); it++)
#define all(S) (S).begin(), (S).end()
#define pb push_back
#define sz size()

vi g[100];
int vis[100];

void DFS(int u, int spc) {
    int k = g[u].sz, size;
    vis[u] = 1;
    if (k) {
        sort(all(g[u]));
        size = g[u].size();
        rep(i, size) {
            rep(j, spc) cout << " ";
            cout << u << "-" << g[u][i];
            if (vis[g[u][i]] == -1 || vis[g[u][i]] == -2) {
                cout << " pathR(G," << g[u][i] << ")\n";
                DFS(g[u][i], spc + 2);
            } else
                cout << "\n";
        }
    }
}
int main() {
    int t, n, m, u, v;

    cin >> t;
    rep(tst, t) {
        cin >> n >> m;
        rep(i, n) {
            g[i].clear();
            vis[i] = -2;
        }
        rep(i, m) {
            cin >> u >> v;
            vis[u] = -1;
            g[u].pb(v);
        }
        cout << "Caso " << tst + 1 << ":\n";
        rep(i, n) {
            if (vis[i] == -1) {
                DFS(i, 2);
                cout << endl;
            }
        }
    }
    return 0;
}