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
#define pb push_back
#define x first
#define y second

int N;
pair<int, int> V[1010];
int pd[1010][1010][2];

int lis(int i, int j, int k) {

    if (i > N)
        return 0;
    if (pd[i][j][k] != -1)
        return pd[i][j][k];

    int res = 0;

    res = lis(i + 1, j, k); // nao escolher i
    if (j == 0)             // nao escolhi ngm antes
    {
        // escolher i
        res = max(res, 1 + lis(i + 1, i, 1)); // escolhi i e o proximo deve estar cima
        res = max(res, 1 + lis(i + 1, i, 0)); // 	\\		             deve estar abaixo
    }

    else if (k == 1) {
        if (V[i].y == V[j].y + 2 && V[i].x != V[j].x) {
            res = max(res, 1 + lis(i + 1, i, 0)); // o proximo deve estar abaixo
        }
    }

    else if (k == 0) {
        if (V[i].y == V[j].y - 2 && V[i].x != V[j].x) {
            res = max(res, 1 + lis(i + 1, i, 1)); // o proximo deve estar acima
        }
    }

    pd[i][j][k] = res;

    return res;
}

int main() {

    while (scanf("%d", &N) == 1) {
        V[0].x = V[0].y = -1000000000;

        for (int i = 1; i <= N; i++)
            scanf("%d%d", &V[i].x, &V[i].y);

        sort(V + 1, V + N + 1);

        for (int i = 0; i <= N + 1; i++)
            for (int j = 0; j <= N + 1; j++)
                pd[i][j][0] = pd[i][j][1] = -1;

        int ret = lis(1, 0, 0);

        printf("%d\n", ret);
    }

    return 0;
}
