#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)
#define BIT(num, b) (num & 1 << b)
const int dx[] = {0, 0, -1, 1};
const int dy[] = {-1, 1, 0, 0};
const int INF = 0x3f3f3f3f;

typedef pair<int, int> ii;

char grid[110][110];
int dist[110][110];
queue<ii> Q;
int N;

inline bool dentro(int r, int s) { return r >= 0 && r < N && s >= 0 && s < N; }

int bfs(int mask) {
    ii aux;
    int x, y, a, b, bit;
    char u;
    u = grid[0][0];
    if ((isupper(u) && (mask & 1 << (u - 'A')) == 0) || (islower(u) && (mask & 1 << (u - 'a')))) {
        return INF;
    }

    //
    //	for(int i=5; i >= 0; i--)
    //		printf("%c", i+'A');
    //	printf("\n");
    //
    //	for(int i=5; i >= 0; i--)
    //		printf("%c", (mask & 1<<i)? '1' : '0');
    //	printf("\n");

    memset(dist, -1, sizeof dist);

    while (!Q.empty())
        Q.pop();
    Q.push(ii(0, 0));
    dist[0][0] = 0;

    while (!Q.empty()) {
        aux = Q.front();
        Q.pop();
        x = aux.first;
        y = aux.second;
        rep(k, 0, 4) {
            a = x + dx[k];
            b = y + dy[k];
            if (dentro(a, b) && dist[a][b] == -1) {
                u = grid[a][b];
                //				cout << "("<<a<<","<<b<<") - " << u << " \n";
                //				cout << (mask & 1 << (u-'A')) <<  "  " << (mask & 1<<(u-'a')) << "\n";

                if ((isupper(u) && (mask & 1 << (u - 'A'))) || (islower(u) && (mask & 1 << (u - 'a')) == 0)) {
                    dist[a][b] = dist[x][y] + 1;
                    Q.push(ii(a, b));
                }
            }
        }
    }

    //	rep(i,0,N){
    //		rep(j,0,N)
    //			cout << dist[i][j] << " ";
    //		cout << "\n";
    //		printf("\n");
    //	}

    return (dist[N - 1][N - 1] == -1 ? 0x3f3f3f3f : dist[N - 1][N - 1]);
}

int main() {
    scanf("%d\n", &N);
    rep(i, 0, N) { gets(grid[i]); }

    //	rep(i,0,N){
    //		rep(j,0,N) cout << grid[i][j]; cout << "\n";
    //	}

    int ans = 0x3f3f3f3f;
    for (int mask = 0; mask < (1 << 10); mask++) {
        ans = min(ans, bfs(mask));
    }

    printf("%d\n", (ans == 0x3f3f3f3f ? -1 : ans + 1));

    return 0;
}
