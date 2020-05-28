#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

#define pb push_back
#define rep(i, a, b) for (int i(a); i < (b); i++)
#define debug(x, y) cout << #x << " = " << x << "  " << #y << " " << y << "\n";

const int dx[] = {0, 0, -1, 1, 1, 1, -1, -1};
const int dy[] = {1, -1, 0, 0, -1, 1, -1, 1};

char m[110][110];
int g[110][110], vis[110][110];
int N, M;

int cont;

inline bool dentro(int x, int y) { return x >= 0 && x < N && y >= 0 && y < M; }

int V, C;

bool dfs(int x, int y) {
    vis[x][y] = 1;

    int a, b;
    rep(i, 0, 8) {
        a = x + dx[i];
        b = y + dy[i];
        if (dentro(a, b) && !vis[a][b] && m[a][b] != '.') {
            V++;
            if (m[a][b] == '*')
                C++;
            dfs(a, b);
        }
    }
}

int main() {
    scanf("%d %d", &N, &M);
    rep(i, 0, N) rep(j, 0, M) scanf(" %c", &m[i][j]);

    int K, x, y;
    scanf("%d", &K);

    while (K--) {
        scanf("%d %d", &x, &y);
        x--;
        y--;
        if (m[x][y] == '#')
            m[x][y] = '*';
    }

    cont = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            if (!vis[i][j] && m[i][j] == '*') {
                V = C = 0;
                dfs(i, j);
                if (V == C)
                    cont++;
            }

    printf("%d\n", cont);

    //  cout << "\n";
    //  for (int i=0; i < N; i++){
    //      for (int j=0; j < M; j++)
    //          cout << vis[i][j] << " ";
    //      cout << "\n";
    //  }

    return 0;
}
