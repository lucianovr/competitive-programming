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
#define rep(i, n) for (int i = 1; i <= (n); i = i + 1)
#define tr(it, S) for (typeof(S.begin()) it = S.begin(); it != S.end(); it++)
#define all(S) (S).begin(), (S).end()
#define pb push_back
#define sz size()
#define inf 1000000
#define MAX 501
int g[MAX][MAX];

int main() {

    int n, e, u, v, w, ret;
    while (cin >> n >> e && n + e) {
        rep(i, n) rep(j, n) {
            if (i ^ j)
                g[i][j] = inf;
            else
                g[i][j] = 0;
        }
        rep(i, e) {
            cin >> u >> v >> w;
            g[u][v] = w;
            if (g[v][u] != inf)
                g[u][v] = g[v][u] = 0;
        }

        rep(k, n) rep(i, n) rep(j, n) if (g[i][j] > g[i][k] + g[k][j]) g[i][j] = g[i][k] + g[k][j];
        int k;
        cin >> k;
        rep(i, k) {
            cin >> u >> v;
            if (g[u][v] == inf)
                cout << "Nao e possivel entregar a carta\n";
            else
                cout << g[u][v] << endl;
        }
        cout << endl;
    }
    return 0;
}
