#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctype.h>
#include <iostream>
#include <map>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define rep(i, a, b) for (int i = a; i < b; ++i)
#define pb push_back

int dx[] = {0, 0, -1, 1, -1, -1, 1, 1};
int dy[] = {-1, 1, 0, 0, -1, 1, 1, -1};

int N, M;

inline bool dentro(int a, int b) { return (a >= 0 && a < N && b >= 0 && b < M); }

char grid[510][510];
int dist[510][510];

pair<ii, int> BFS(int x, int y) {
    int ma = -1;
    ii pos;
    int a, b;
    queue<ii> Q;
    rep(i, 0, N) rep(j, 0, M) dist[i][j] = -1;

    dist[x][y] = 0;
    Q.push(ii(x, y));

    while (!Q.empty()) {
        x = Q.front().first;
        y = Q.front().second;

        if (dist[x][y] > ma) {
            ma = dist[x][y];
            pos = ii(x, y);
        }
        Q.pop();

        rep(i, 0, 4) {
            a = x + dx[i];
            b = y + dy[i];
            if (dentro(a, b) && grid[a][b] == '.' && dist[a][b] == -1) {
                dist[a][b] = dist[x][y] + 1;
                Q.push(ii(a, b));
            }
        }
    }
    return make_pair(pos, ma);
}

int main() {
    int x, y;

    while (scanf("%d%d", &N, &M) == 2) {
        if (N == 0 && M == 0)
            return 0;

        x = -1;
        rep(i, 0, N) rep(j, 0, M) {
            scanf(" %c", &grid[i][j]);
            if (grid[i][j] == '.' && x == -1) {
                x = i;
                y = j;
            }
        }

        pair<ii, int> data = BFS(x, y);

        ii pos = data.first;

        data = BFS(pos.first, pos.second);

        printf("%d\n", data.second);
    }

    return 0;
}
