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
#define Rep(i, a) rep(i, 0, a)
#define tr(it, S) for (typeof(S.begin()) it = S.begin(); it != S.end(); it++)
#define all(S) S.begin(), S.end()
#define pb push_back
#define MAX 1000

const int INF = 0x3F3F3F3F;
const double EPS = 1e-10;
int cmp(double x, double y = 0, double tol = EPS) { return ((x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1); }
bool cmp_eq(double x, double y) { return cmp(x, y) == 0; }
bool cmp_lt(double x, double y) { return cmp(x, y) < 0; }

//          lef Rig Up Dow
int di[] = {0, 0, -1, 1, -1, -1, 1, 1};
int dj[] = {-1, 1, 0, 0, -1, 1, 1, -1};

//      X   Y    T
int PD[21][21][2001];
int maca[21][21][2001];
int N, M, K, TMAX;

int solve(int X, int Y, int T) {
    if (T > TMAX)
        return 0;
    if (PD[X][Y][T] != -1)
        return PD[X][Y][T];

    int res = 0;

    res = max(res, solve(X, Y, T + 1) + maca[X][Y][T]);
    rep(i, 0, 8) {
        int a = X + di[i];
        int b = Y + dj[i];
        if (a >= 0 && a < N && b >= 0 && b < M)
            res = max(res, solve(a, b, T + 1) + maca[X][Y][T]);
    }

    return PD[X][Y][T] = res;
}
int main() {

    int x, y, t;
    while (scanf("%d%d%d", &N, &M, &K) && N + M + K) {
        TMAX = 2 * K + 1;

        for (int i = 0; i < N + 1; i++)
            for (int j = 0; j < M + 1; j++)
                for (t = 0; t <= TMAX; t++) {
                    PD[i][j][t] = -1;
                    maca[i][j][t] = 0;
                }
        TMAX = 0;
        rep(i, 0, K) {
            scanf("%d%d%d", &x, &y, &t);
            x--;
            y--;
            maca[x][y][t] = 1;
            if (t > TMAX)
                TMAX = t;
        }
        scanf("%d%d", &x, &y);
        x--;
        y--;

        int ret = solve(x, y, 0);
        printf("%d\n", ret);
    }
    return 0;
}