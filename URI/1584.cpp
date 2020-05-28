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

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define rep(i, a, b) for (int i = a; i < b; ++i)
#define pb push_back

const int INF = 0x3F3F3F3F;
const double EPS = 1e-10;

int cmp(double x, double y = 0, double tol = EPS) { return ((x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1); }

inline bool cmp_eq(double x, double y) { return cmp(x, y) == 0; }
inline bool cmp_lt(double x, double y) { return cmp(x, y) < 0; }

ll M = 1000000007;
int V;

int Dx[] = {0, 0, -1, 1, -1, -1, 1, 1};
int Dy[] = {-1, 1, 0, 0, -1, 1, 1, -1};

struct matrix {
    ll mat[25][25];
};

matrix ident;

int vis[5][5];

matrix matMul(matrix A, matrix B);
matrix matExp(matrix A, ll p);

inline bool dentro(int x, int y, int n) { return (x >= 0 && x < n && y >= 0 && y < n); }

int main() {

    matrix ADJ;
    bool vis[6][6];
    queue<ii> Q;

    int u, v, x, y, dx, dy;

    rep(i, 0, 25) rep(j, 0, 25) ident.mat[i][j] = (i == j);

    int N;
    ll K;
    while (scanf("%d %lld", &N, &K) == 2) {

        rep(i, 0, 25) rep(j, 0, 25) ADJ.mat[i][j] = 0;

        V = N * N;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                memset(vis, false, sizeof(vis));
                Q.push(ii(i, j));
                vis[i][j] = true;

                while (!Q.empty()) {
                    ii top = Q.front();
                    Q.pop();
                    x = top.first;
                    y = top.second;
                    if (ADJ.mat[i * N + j][x * N + y] == 0 && (x != i || y != j)) {
                        ADJ.mat[i * N + j][x * N + y] = 1;
                        dx = x - i;
                        dy = y - j;
                        u = x + dx;
                        v = y + dy;
                        while (dentro(u, v, N)) {
                            vis[u][v] = true;
                            u += dx;
                            v += dy;
                        }
                    }

                    rep(h, 0, 8) {
                        u = x + Dx[h];
                        v = y + Dy[h];
                        if (dentro(u, v, N) && !vis[u][v]) {
                            Q.push(ii(u, v));
                            vis[u][v] = true;
                        }
                    }
                }
            }
        }

        matrix EXP = matExp(ADJ, K);

        ll sum = 0;
        rep(i, 0, V) rep(j, 0, V) sum = (sum % M + EXP.mat[i][j] % M) % M;

        printf("%lld\n", sum);
    }

    return 0;
}

matrix matMul(matrix A, matrix B) {
    matrix C;
    rep(i, 0, V) rep(j, 0, V) {
        C.mat[i][j] = 0;
        for (int k = 0; k < V; ++k) {
            C.mat[i][j] = (C.mat[i][j] % M + ((A.mat[i][k] % M) * (B.mat[k][j]) % M) % M) % M;
        }
    }
    return C;
}

matrix matExp(matrix A, ll p) {
    if (p == 0)
        return ident;
    if (p == 1)
        return A;

    matrix B = matExp(A, p / 2);
    B = matMul(B, B);
    if (p & 1)
        B = matMul(B, A);
    return B;
}
