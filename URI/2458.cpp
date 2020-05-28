#include <iostream>
using namespace std;
#define pb push_back
#define rep(i, a, b) for (int i(a); i < (b); i++)

int N;

// i =      0 1  2 3
int di[] = {0, 0, -1, 1};
int dj[] = {-1, 1, 0, 0};
char ok[] = {"><VA"};

char grid[510][510];
int vis[510][510];

inline bool dentro(int a, int b) { return a >= 0 && a < N && b >= 0 && b < N; }

void dfs(int x, int y) {
    if (vis[x][y])
        return;
    vis[x][y] = 1;

    int a, b;
    for (int i = 0; i < 4; i++) {
        a = x + di[i];
        b = y + dj[i];

        if (dentro(a, b)) {
            if (grid[a][b] == ok[i])
                dfs(a, b);
        }
    }
}

int main() {
    scanf("%d", &N);
    rep(i, 0, N) rep(j, 0, N) scanf(" %c", &grid[i][j]);

    rep(j, 0, N) if (grid[0][j] == 'A') dfs(0, j);

    rep(j, 0, N) if (grid[N - 1][j] == 'V') dfs(N - 1, j);

    rep(i, 0, N) if (grid[i][0] == '<') dfs(i, 0);

    rep(i, 0, N) if (grid[i][N - 1] == '>') dfs(i, N - 1);

    int cont = 0;
    rep(i, 0, N) rep(j, 0, N) if (vis[i][j] == 0) cont++;

    printf("%d\n", cont);

    return 0;
}
