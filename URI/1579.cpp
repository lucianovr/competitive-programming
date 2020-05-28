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

const int INF = 0x3F3F3F3F;

int N, C, F;
int valor[110];
int pd[110][11];

int solve(int i, int c) {
    if (i == N && c == C)
        return 0;
    if (c == C)
        return INF;

    if (pd[i][c] != -1)
        return pd[i][c];

    int peso = 0, ans = INF;
    for (int j = i; j < N; j++) {
        // colocar a caixa i no caminhao c
        peso += valor[j];

        // quebrar a sequencia
        int ret = solve(j + 1, c + 1); // onde peso representa um caminhao

        ans = min(ans, max(peso, ret));
    }

    return pd[i][c] = ans;
}

int main() {

    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d %d", &N, &C, &F);
        rep(i, 0, N) scanf("%d", &valor[i]);

        rep(i, 0, N) rep(j, 0, C + 1) pd[i][j] = -1;
        int ret = solve(0, 0);
        printf("%d $%d\n", ret, ret * C * F);
    }
    return 0;
}
