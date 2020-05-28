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
typedef pair<int, int> ii;
#define rep(i, a, b) for (int i = a; i < b; ++i)

const int INF = 0x3F3F3F3F;
int dx[] = {-1, -2, -2, -1, 1, 2, 2, 1};
int dy[] = {-2, -1, 1, 2, 2, 1, -1, -2};

int n, final, N, M, a, b;
int pd[16][70000], dist[20][20], D[101][101];
char grid[101][110];
queue<ii> fila;
ii top;

int tsp(int u, unsigned int mask, int cont) {
    //  cout << u << "  ";  for(int i=n-1; i>=0; i--)    cout << (mask & (1 << i ) ? 1 : 0 );    cout << "\n";
    if (mask == final) {
        if (u == 0) {
            return 0;
        } else {
            return INF;
        }
    }
    if (pd[u][mask] != -1)
        return pd[u][mask];

    int ret = INF;
    for (int i = 0; i < n; i++)
        if (i != u && !(mask & (1 << i))) {
            if (i != 0)
                ret = min(ret, tsp(i, mask | (1 << i), cont + 1) + dist[u][i]);
            else if (i == 0 && cont == n - 1)
                ret = min(ret, tsp(i, mask | (1 << i), cont + 1) + dist[u][i]);
        }

    return pd[u][mask] = ret;
}

inline bool dentro(int a, int b) { return (a >= 0 && a < N && b >= 0 && b < M); }

int BFS(int x, int y) {
    memset(D, -1, sizeof D);
    D[x][y] = 0;

    while (!fila.empty())
        fila.pop();
    fila.push(ii(x, y));

    while (!fila.empty()) {
        top = fila.front();
        fila.pop();
        x = top.first;
        y = top.second;

        rep(i, 0, 8) {
            a = x + dx[i];
            b = y + dy[i];
            if (dentro(a, b) && D[a][b] == -1 && grid[a][b] != '#') {
                D[a][b] = D[x][y] + 1;
                fila.push(ii(a, b));
            }
        }
    }
}

int main() {
    int X[20], Y[20], k;
    char ch;

    while (scanf("%d%d%d", &N, &M, &n) == 3) {
        if (N == 0 && N == M && N == n)
            return 0;
        n++;
        final = (1 << n) - 1;

        k = 1;
        rep(i, 0, N) rep(j, 0, M) {
            scanf(" %c", &ch);
            if (ch == 'P') {
                X[k] = i;
                Y[k] = j;
                k++;
            }
            if (ch == 'C') {
                X[0] = i;
                Y[0] = j;
            }
            grid[i][j] = ch;
        }

        memset(dist, INF, sizeof dist);
        rep(i, 0, n) {
            BFS(X[i], Y[i]);
            rep(j, 0, n) { dist[i][j] = D[X[j]][Y[j]]; }
        }
        //
        //      rep(i,0,n){
        //          rep(j,0,n)
        //              cout << dist[i][j] << " ";
        //          cout << "\n";
        //      }

        rep(i, 0, n) rep(j, 0, final + 1) pd[i][j] = -1;

        printf("%d\n", tsp(0, 0, 0));
    }
    return 0;
}