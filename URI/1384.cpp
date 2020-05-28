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
#define setar(S, x) memset(S, x, sizeof(S))
#define pb push_back
#define sz size()
#define contem(s, x) (s.find(x) != s.end())
#define x first
#define y second
#define inf 1000000000

int r, c;
unsigned long long int dist[1001][1001];
bool vis[1001][1001];

int dx[] = {1, -1, 0, 0, 1, -1, 1, -1, 2, -2, 0, 0, 2, 2, -2, -2, 2, 2, -2, -2, 1, 1, -1, -1};
int dy[] = {0, 0, 1, -1, 1, -1, -1, 1, 0, 0, 2, -2, 2, -2, 2, -2, 1, -1, 1, -1, 2, -2, 2, -2};
int W[] = {2, 2, 2, 2, 3, 3, 3, 3, 5, 5, 5, 5, 7, 7, 7, 7, 6, 6, 6, 6, 6, 6, 6, 6};

bool dentro(int a, int b) {
    if (a > 0 && a <= r && b > 0 && b <= c)
        return true;
    return false;
}

int dijkstra(int x1, int y1, int x2, int y2) {
    ii s, v;
    priority_queue<pair<unsigned long long int, ii>> Q;
    Q.push(make_pair(0ULL, ii(x1, y1)));
    dist[x1][y1] = 0ULL;

    while (true) {
        while (!Q.empty()) {
            v = Q.top().second;
            if (vis[v.x][v.y] == 1)
                Q.pop();
            else
                break;
        }
        if (Q.empty())
            break;
        s = Q.top().second;
        Q.pop();

        vis[s.x][s.y] = 1;
        rep(i, 24) {
            v.x = s.x + dx[i];
            v.y = s.y + dy[i];
            if (dentro(v.x, v.y)) {
                if (vis[v.x][v.y] == 0) {
                    if (dist[v.x][v.y] > dist[s.x][s.y] + W[i]) {
                        dist[v.x][v.y] = dist[s.x][s.y] + W[i];
                        Q.push(make_pair(-dist[v.x][v.y], v));
                    }
                }
            }
        }
    }
    return dist[x2][y2];
}

int main() {
    int k, c1, r1, c2, r2;
    int x1, x2, y1, y2;
    while (cin >> c >> r && c + r) {
        rep(i, r + 1) rep(j, c + 1) {
            vis[i][j] = 0;
            dist[i][j] = inf;
        }

        cin >> y1 >> x1 >> y2 >> x2;
        cin >> k;
        while (k--) {
            cin >> c1 >> r1 >> c2 >> r2;
            for (int i = r1; i <= r2; i++)
                for (int j = c1; j <= c2; j++)
                    vis[i][j] = 1;
        }
        int ret = dijkstra(x1, y1, x2, y2);
        if (ret != inf)
            cout << ret << endl;
        else
            cout << "impossible\n";
    }
    return 0;
}
