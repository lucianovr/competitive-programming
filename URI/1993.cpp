#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for (int i = a; i < b; i++)
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x, y) cout << #x << " = " << x << " --- " << #y << " " << y << "\n";

const double INF = 99999999999999.0;
const double EPS = 1e-9;

typedef pair<int, int> ii;
typedef pair<double, ii> iii;

vector<iii> pts;
vector<pair<int, double>> ladj[1110];

int comp(double x, double y, double tol = EPS) { return ((x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1); }

double getDis(int x1, int y1, int x2, int y2, double c) {
    double ret = hypot(x1 - x2, y1 - y2);
    return fabs(ret - c);
}

double dijkstra(int ini) {
    double dist[110];
    bool vis[110];

    for (int i = 0; i < pts.size(); i++) {
        dist[i] = INF;
        vis[i] = false;
    }

    dist[0] = 0.0;

    priority_queue<pair<double, int>> pq;
    pq.push(make_pair(0.0, 0));

    while (!pq.empty()) {
        double d = -pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (vis[u])
            continue;
        vis[u] = true;

        rep(i, 0, ladj[u].size()) {
            int v = ladj[u][i].first;
            double w = ladj[u][i].second;
            if (comp(dist[v], dist[u] + w) == 1) {
                dist[v] = dist[u] + w;
                pq.push(make_pair(-dist[v], v));
            }
        }
    }

    return dist[1];
}

int main() {
    int u, v, N, x1, x2, y1, y2;
    double w;

    while (scanf("%d %d %d %d %d", &N, &x1, &y1, &x2, &y2)) {
        if (N == -1 && x1 == -1 && y1 == -1 && x2 == -1 && y2 == -1)
            break;

        pts.push_back(make_pair(0.0, ii(x1, y1))); // inicio
        pts.push_back(make_pair(0.0, ii(x2, y2))); // fim

        rep(i, 0, N) {
            scanf("%d %d %lf", &u, &v, &w);
            pts.push_back(make_pair(w, ii(u, v))); // cat
        }

        rep(i, 0, pts.size()) {
            int a1 = pts[i].second.first;
            int b1 = pts[i].second.second;
            double w = pts[i].first;
            rep(j, 0, pts.size()) {
                int a2 = pts[j].second.first;
                int b2 = pts[j].second.second;
                if (i != j) {
                    double dis = getDis(a1, b1, a2, b2, w);
                    ladj[i].push_back(make_pair(j, dis));
                    if (i > 1)
                        ladj[i].push_back(make_pair(j, hypot(a1 - a2, b1 - b2)));
                }
            }
        }

        double ans = dijkstra(0);
        printf("%.2lf\n", ans);

        rep(i, 0, N + 3) ladj[i].clear();
        pts.clear();
    }

    return 0;
}