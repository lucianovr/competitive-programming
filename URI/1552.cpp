#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <queue>
#include <string.h>
#include <string>
#include <utility>
#include <vector>
using namespace std;
typedef pair<double, int> topo;
typedef pair<double, double> dd;
#define rep(i, n) for (int i = 0; i < (n); i = i + 1)
#define tr(it, S) for (typeof(S.begin()) it = S.begin(); it != S.end(); it++)
#define all(S) (S).begin(), (S).end()
#define setar(S, x) memset(S, x, sizeof(S))
#define pb push_back
#define sz size()
#define contem(s, x) (s.find(x) != s.end())
#define x first
#define y second

const double INF = 1000000000.0;

double madj[500][500];

double quad(double valor) { return valor * valor; }

double dist_2d(dd a, dd b) { return sqrt(quad(a.x - b.x) + quad(a.y - b.y)); }

double prim(int n) {
    double ans = 0.0;
    vector<double> D(n, INF);
    vector<int> vis(n, 0);

    priority_queue<topo> Q;
    D[0] = 0.0;
    Q.push(topo(0.0, 0));

    topo s;
    while (!Q.empty()) {
        s = Q.top();
        Q.pop();
        double d = -s.first;
        int u = s.second;

        if (!vis[u]) {
            ans += d;
            vis[u] = 1;
            for (int i = 0; i < n; i++) {
                double cost = madj[u][i];
                if (!vis[i] && D[i] > cost) {
                    D[i] = cost;
                    Q.push(topo(-D[i], i));
                }
            }
        }
    }
    return ans;
}

int main() {
    cout << fixed << setprecision(2);
    int c, p;
    cin >> c;
    while (c--) {
        cin >> p;
        vector<dd> v(p);
        rep(i, p) cin >> v[i].x >> v[i].y;

        for (int i = 0; i < p; i++) {
            for (int j = i; j < p; j++) {
                if (j == i) {
                    madj[j][j] = 0.00;
                    continue;
                }
                double dist = dist_2d(v[i], v[j]);
                dist = dist / 100.00;
                madj[i][j] = dist;
                madj[j][i] = dist;
            }
        }

        double ret = prim(p);
        cout << ret << endl;
    }
    return 0;
}
