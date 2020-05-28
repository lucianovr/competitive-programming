#include <algorithm>
#include <cmath> // atan2(dy,dx) :retorna angulo polar
#include <cstdlib>
#include <iostream>
#include <string.h>
#include <string>
#include <utility> // #define x first , y second  quando trabalhar com pontos
#include <vector>  // #include <map> , <set> , <stack> , <queue> , <deque>
using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define rep(i, n) for (int i = 0; i < (n); i = i + 1)
#define tr(it, S) for (typeof(S.begin()) it = S.begin(); it != S.end(); it++)
#define all(S) (S).begin(), (S).end()
#define pb push_back
#define sz size()
vi g[30];
int cont, vis[30];
vi resp;

void dfs_visit(int u) {
    int size;
    vis[u] = 1;
    resp.pb(u);
    size = g[u].sz;
    rep(i, size) if (!vis[g[u][i]]) dfs_visit(g[u][i]);
}

void dfs(int n) {
    memset(vis, 0, sizeof(vis));
    int size;
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            resp.clear();
            cont++;
            dfs_visit(i);
            sort(all(resp));
            size = resp.sz;
            rep(j, size) cout << char(resp[j] + 'a') << ",";
            cout << endl;
        }
    }
    cout << cont << " connected components\n";
}
int main() {
    int casos, n, m;
    char x, y;
    cin >> casos;
    rep(t, casos) {
        cin >> n >> m;
        rep(i, n) g[i].clear();
        rep(i, m) {
            cin >> x >> y;
            g[x - 'a'].pb(y - 'a');
            g[y - 'a'].pb(x - 'a');
        }
        cout << "Case #" << t + 1 << ":\n";
        cont = 0;
        dfs(n);
        cout << endl;
    }
    return 0;
}