#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i(a); i < (b); i++)

#define all(c) c.begin(), c.end()
#define UNIQUE(c)                                                                                                      \
    { sort(ALL(c); (c).resize( unique(ALL(c))-c.begin() );                                               \
    }
#define pb push_back
#define D(x)                                                                                                           \
    if (1)                                                                                                             \
        cout << __LINE__ << " " << #x " = " << (x) << endl;
#define DVEC(v, n)                                                                                                     \
    {                                                                                                                  \
        cout << #v << "[] ={ ";                                                                                        \
        rep(i, 0, n) cout << v[i] << " ";                                                                              \
        cout << "}\n";                                                                                                 \
    }
#define mp make_pair
#define fst first
#define snd second

typedef pair<int, int> ii;
typedef long long ll;

typedef vector<int> vi;
typedef vector<ii> vii;

const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int R, C;
char grid[510][510];
int dist[510][510];

bool dentro(int i, int j) { return i >= 0 && i < R && j >= 0 && j < C; }

int dijkstra(int x, int y) {
    memset(dist, INF, sizeof dist);

    priority_queue<pair<int, ii>> pq;
    dist[x][y] = 0;
    pq.push(make_pair(0, ii(x, y)));

    while (!pq.empty()) {
        pair<int, ii> top = pq.top();
        pq.pop();
        x = top.snd.fst;
        y = top.snd.snd;

        if (dist[x][y] == -top.fst) {
            if (grid[x][y] == 'E')
                return -top.fst;

            rep(i, 0, 4) {
                int a = x + dx[i];
                int b = y + dy[i];
                if (dentro(a, b) && grid[a][b] != '#') {
                    if (grid[a][b] == '.' || grid[a][b] == 'E') {
                        if (dist[a][b] > dist[x][y] + 0) {
                            dist[a][b] = dist[x][y] + 0;
                            pq.push(make_pair(-dist[a][b], ii(a, b)));
                        }
                    } else {
                        if (dist[a][b] > dist[x][y] + (grid[a][b] - '0')) {
                            dist[a][b] = dist[x][y] + (grid[a][b] - '0');
                            pq.push(make_pair(-dist[a][b], ii(a, b)));
                        }
                    }
                }
            }
        }
    }
    return -1;
}

int main() {
    while (scanf("%d %d\n", &R, &C) == 2) {
        int x, y;
        rep(i, 0, R) rep(j, 0, C) {
            scanf(" %c", &grid[i][j]);
            if (grid[i][j] == 'H') {
                x = i, y = j;
            }
        }
        int ret = dijkstra(x, y);
        if (ret == -1)
            printf("ARTSKJID\n");
        else
            printf("%d\n", ret);
    }
    return 0;
}
