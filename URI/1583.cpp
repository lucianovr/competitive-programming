#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <utility>
#include <vector>

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define rep(i, a, b) for (int i = a; i < b; ++i)
#define pb push_back
#define debug(x) cout << #x << " = " << x << endl;

#define printMatriz(M, r, c)                                                                                           \
    rep(i, 0, r) {                                                                                                     \
        printVetor(M[i], c);                                                                                           \
        cout << endl;                                                                                                  \
    }
#define printVetor(V, n) rep(j, 0, n) cout << V[j] << " ";

const int INF = 0x3f3f3f3f;
const int NULO = -1;
const double pi = acos(-1);
const int dx[] = {0, -1, 0, 1}, dy[] = {-1, 0, 1, 0};

int N, M;
char grid[60][60];
int vis[60][60];

void dfs(int x, int y) {
    vis[x][y] = 1;
    int a, b;
    rep(i, 0, 4) {
        a = x + dx[i];
        b = y + dy[i];
        if (a >= 0 && a < N && b >= 0 && b < M) {
            if (!vis[a][b] && grid[a][b] == 'A') {
                grid[a][b] = 'T';
                dfs(a, b);
            }
        }
    }
}

int main() {
    while (scanf("%d%d", &N, &M) && N + M) {
        rep(i, 0, N) rep(j, 0, M) {
            scanf(" %c", &grid[i][j]);
            vis[i][j] = 0;
        }
        rep(i, 0, N) rep(j, 0, M) if (!vis[i][j] && grid[i][j] == 'T') dfs(i, j);

        rep(i, 0, N) {
            rep(j, 0, M) printf("%c", grid[i][j]);
            printf("\n");
        }

        printf("\n");
    }
    return 0;
}
