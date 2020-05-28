#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a, c = b; i < c; ++i)
#define debug(x) cout << #x << " = " << x << "\n";
#define all(v) v.begin(), v.end()

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

typedef pair<int, double> vert;
vector<vert> adj[110];

double dijkstra(int n) {
    int s;
    vector<double> prob(n + 1, -1.0);
    vector<int> vis(n + 1, 0);
    prob[1] = 1;
    priority_queue<pair<double, int>> Q;
    Q.push(make_pair(1, 1));

    while (!Q.empty()) {
        pair<double, int> top = Q.top();
        Q.pop();
        s = top.second;
        if (vis[s])
            continue;
        vis[s] = 1;

        if (s == n)
            return prob[s];

        int sz = adj[s].size();
        rep(i, 0, sz) {
            int v = adj[s][i].first;
            double p = adj[s][i].second;
            if (prob[v] < prob[s] * p) {
                prob[v] = prob[s] * p;
                Q.push(make_pair(prob[v], v));
            }
        }
    }
}

int main() {

    int n, m, a, b;
    double p;

    while (scanf("%d", &n) && n) {
        rep(i, 1, n + 1) adj[i].clear();
        scanf("%d", &m);
        while (m--) {
            scanf(" %d %d %lf", &a, &b, &p);
            adj[a].push_back(vert(b, p / 100));
            adj[b].push_back(vert(a, p / 100));
        }
        double ret = dijkstra(n) * 100;
        printf("%.6lf percent\n", ret);
    }
    return 0;
}