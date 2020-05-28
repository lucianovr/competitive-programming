#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(c) (c).begin(), (c).end()
#define F first
#define S second
#define debug(x) cout << __LINE__ << ": " << #x << " = " << x << endl;
#define debug2(x, y) cout << #x << " = " << x << "  " << #y << " = " << y << endl;
#define pb push_back
#define mk make_pair

const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;
typedef long long ll;
typedef pair<int, int> ii;

deque<pair<int, int>> dq;
vector<int> g[2][11234];

int main() {
    int N, E, A, B, u, v;
    while (scanf("%d %d %d %d", &N, &E, &A, &B) == 4) {
        rep(i, 0, N + 1) g[0][i].clear(), g[1][i].clear();

        rep(i, 0, E) {
            scanf("%d %d", &u, &v);
            g[0][u].pb(v);
            g[1][v].pb(u);
        }
        int dist[N + 2];

        memset(dist, INF, sizeof dist);
        dist[A] = 0;
        dq.push_front(ii(A, 0));

        while (!dq.empty()) {
            u = dq.front().first;
            dq.pop_front();
            for (int i = 0; i < g[0][u].size(); i++) {
                v = g[0][u][i];
                if (dist[v] > dist[u]) {
                    dist[v] = dist[u];
                    dq.push_front(ii(v, 0));
                }
            }
            for (int i = 0; i < g[1][u].size(); i++) {
                v = g[1][u][i];
                if (dist[v] > dist[u]) {
                    dist[v] = dist[u] + 1;
                    dq.push_front(ii(v, 1));
                }
            }
        }
        int AA = dist[B];

        memset(dist, INF, sizeof dist);
        dist[B] = 0;
        dq.push_front(ii(B, 0));

        while (!dq.empty()) {
            u = dq.front().first;
            dq.pop_front();
            for (int i = 0; i < g[0][u].size(); i++) {
                v = g[0][u][i];
                if (dist[v] > dist[u]) {
                    dist[v] = dist[u];
                    dq.push_front(ii(v, 0));
                }
            }
            for (int i = 0; i < g[1][u].size(); i++) {
                v = g[1][u][i];
                if (dist[v] > dist[u]) {
                    dist[v] = dist[u] + 1;
                    dq.push_front(ii(v, 1));
                }
            }
        }
        int BB = dist[A];

        if (AA < BB) {
            printf("Bibi: %d\n", AA);
        } else if (AA > BB) {
            printf("Bibika: %d\n", BB);
        } else {
            printf("Bibibibika\n");
        }
    }
    return 0;
}
