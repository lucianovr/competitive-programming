#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <map>
#include <queue>
#include <string.h>
#include <utility>
#include <vector>
using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define rep(i, n) for (int i = 0; i < (n); i = i + 1)
#define tr(it, S) for (typeof(S.begin()) it = S.begin(); it != S.end(); it++)
#define all(S) (S).begin(), (S).end()
#define setar(S, x) memset(S, x, sizeof(S))
#define pb push_back
#define sz size()
#define contem(s, x) (s.find(x) != s.end())
#define inf 1000000000
map<int, bool> mp;
int madj[300][300];
int rota[300];

void calcRota(int x) {
    rota[x] = 0;
    for (int i = x - 1; i >= 0; i--)
        rota[i] = rota[i + 1] + madj[i][i + 1];
}
int dijkstra(int n, int c, int s) {
    vi caminho(c, inf);
    vi dist(n, inf), vis(n, 0);
    priority_queue<ii> Q;

    dist[s] = 0;
    Q.push(ii(0, s));

    while (!Q.empty()) {
        s = Q.top().second;
        Q.pop();
        if (!vis[s]) {
            vis[s] = 1;
            if (s == c - 1)
                break;
            for (int v = 0; v < n; v++) {
                if (!vis[v] && madj[s][v] != -1) {

                    int custo = madj[s][v];
                    if (mp[v]) {
                        if (caminho[v] > rota[v] + custo + dist[s]) {
                            caminho[v] = rota[v] + custo + dist[s];
                        }
                    } else {
                        if (dist[v] > dist[s] + custo) {
                            dist[v] = dist[s] + custo;
                            Q.push(ii(-dist[v], v));
                        }
                    }
                }
            }
        }
    }

    int MIN = inf;
    rep(i, c) if (MIN > caminho[i]) MIN = caminho[i];
    return min(MIN, dist[c - 1]);
}

int main() {
    int n, m, c, k;
    int x, y, w;
    while (cin >> n >> m >> c >> k && n + m + c + k) {
        mp.clear();
        rep(i, n) rep(j, n) madj[i][j] = -1;

        for (int i = 0; i < c - 1; i++)
            mp[i] = true;

        rep(i, m) {
            cin >> x >> y >> w;
            madj[x][y] = madj[y][x] = w;
        }
        calcRota(c - 1);
        cout << dijkstra(n, c, k) << endl;
    }
    return 0;
}
