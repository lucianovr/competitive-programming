#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <queue>
#include <string.h>
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
struct TRES {
    double x, y, r;
};

TRES v[110];
double g[110][110];

double quad(double x) { return (x) * (x); }

double dist2d(int i, int j) { return sqrt(quad(v[i].x - v[j].x) + quad(v[i].y - v[j].y)); }

double dijkstra(int n, int a, int b) {
    vector<double> dist(n, -1.0);
    vi vis(n, 0);
    priority_queue<pair<int, int>> Q;
    dist[a] = 0.0;
    Q.push(make_pair(0.0, a));
    while (!Q.empty()) {
        a = Q.top().second;
        Q.pop();
        if (!vis[a]) {
            vis[a] = 1;
            if (a == b)
                break;
            rep(i, n) {
                if (!vis[i] && g[a][i]) {
                    if (dist[i] == -1.0 || dist[i] > dist[a] + g[a][i]) {
                        dist[i] = dist[a] + g[a][i];
                        Q.push(make_pair(-dist[i], i));
                    }
                }
            }
        }
    }
    return dist[b];
}

int main() {
    int n, t;

    while (cin >> n && n) {
        rep(i, n) cin >> v[i].x >> v[i].y >> v[i].r;

        double ret;

        rep(i, n) {
            rep(j, n) {
                if (i != j) {
                    ret = dist2d(i, j);
                    if (ret <= v[i].r) {
                        g[i][j] = ret;
                    } else
                        g[i][j] = 0.0;
                } else
                    g[i][j] = 0.0;
            }
        }

        cin >> t;
        int a, b;
        rep(i, t) {
            cin >> a >> b;
            if (a == b)
                cout << 0 << endl;
            else {
                ret = dijkstra(n, a - 1, b - 1);
                if (ret != -1.0)
                    cout << (int)ret << endl;
                else
                    cout << -1 << endl;
            }
        }
    }
    return 0;
}
