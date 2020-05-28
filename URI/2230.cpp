#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;
typedef long long int ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define rep(i, a, b) for (int _i = a, __i = b, i = _i; i < __i; i++)
#define Rep(i, a) rep(i, 0, a)
#define tr(it, S) for (typeof(S.begin()) it = S.begin(); it != S.end(); it++)
#define all(S) S.begin(), S.end()
#define pb push_back

int main() {

    int n, m, ini, p, u, v, caso = 1;
    int madj[55][55], dist[55];

    while (scanf("%d%d%d%d", &n, &m, &ini, &p) && n + m + p + ini) {
        memset(madj, 0, sizeof(madj));
        while (m--) {
            scanf("%d%d", &u, &v);
            madj[u][v] = madj[v][u] = 1;
        }
        memset(dist, -1, sizeof(dist));

        queue<int> fila;
        fila.push(ini);
        dist[ini] = 0;

        while (!fila.empty()) {
            u = fila.front();
            fila.pop();
            for (int i = 1; i <= n; i++)
                if (madj[u][i] && dist[i] == -1) {
                    dist[i] = dist[u] + 1;
                    fila.push(i);
                }
        }

        vector<int> ans;
        rep(i, 1, n + 1) {
            if (dist[i] <= p && dist[i] > 0) {
                ans.push_back(i);
            }
        }
        cout << "Teste " << caso++ << "\n";
        rep(i, 0, ans.size()) { cout << ans[i] << " "; }
        cout << "\n\n";
    }
}
