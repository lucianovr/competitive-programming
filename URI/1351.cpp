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

const double INF = 1000000000.00;

int lista[110], prod[100010];
double preco[100010];
int M, N;

double dp[110][100010];
bool ok;

double super(int i, int j) {
    if (i == M) {
        ok = true;
        return 0;
    }
    if (j == N)
        return INF;
    if (dp[i][j] > -0.5)
        return dp[i][j];

    double res;
    res = super(i, j + 1); // nao escolher prod[j]

    if (lista[i] == prod[j])
        res =
            min(res, super(i + 1, j + 1) + preco[j]); // escolher prod[j], mas somente se prod[j] for o produto lista[i]

    return dp[i][j] = res;
}

int main() {
    while (scanf("%d%d", &M, &N) == 2) {
        if (N == M && N == 0)
            break;

        rep(i, 0, M) scanf("%d", &lista[i]);

        rep(j, 0, N) scanf("%d %lf", &prod[j], &preco[j]);

        rep(i, 0, M + 1) rep(j, 0, N + 1) dp[i][j] = -1.0;

        ok = false;
        double ans = super(0, 0);

        if (ok == false)
            printf("Impossible\n");
        else
            printf("%.2lf\n", ans);
    }
    return 0;
}
