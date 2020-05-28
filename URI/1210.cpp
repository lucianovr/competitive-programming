#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define rep(i, a, b) for (int i(a); i < (b); i++)
#define debug(x) cout << #x << " = " << x << "\n";

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define MI 2000 + 10
int custo[MI], venda[MI];
bool memo[MI][MI];
int N, I, M, P;
int pd[MI][MI];

const int INF = 0x3f3f3f3f;

int solve(int i, int idade) {
    if (i == N)
        return 0;
    if (pd[i][idade] != -1)
        return pd[i][idade];

    int ret1, ret2;

    ret1 = ret2 = INF;

    ret1 = solve(i + 1, 1) + P - venda[idade] + custo[0]; // vender e comprar
    if (idade < M)
        ret2 = solve(i + 1, idade + 1) + custo[idade]; // manter

    if (ret1 <= ret2)
        memo[i][idade] = true;
    return pd[i][idade] = min(ret1, ret2);
}

vector<int> v;
void back(int i, int id) {
    if (i == N)
        return;
    if (memo[i][id]) {
        v.push_back(i + 1);
        back(i + 1, 1);
    } else
        back(i + 1, id + 1);
}

int main() {
    while (scanf("%d %d %d %d", &N, &I, &M, &P) == 4) {
        for (int m = 0; m < M; m++)
            scanf("%d", &custo[m]);
        for (int m = 1; m <= M; m++)
            scanf("%d", &venda[m]);

        for (int i = 0; i <= N + 1; i++)
            for (int j = 0; j <= M + 1; j++) {
                pd[i][j] = -1;
                memo[i][j] = false;
            }

        printf("%d\n", solve(0, I));
        v.clear();
        back(0, I);
        if (v.size() == 0)
            printf("0\n");
        else {
            rep(i, 0, v.size()) {
                if (i)
                    printf(" ");
                printf("%d", v[i]);
            }
            printf("\n");
        }
    }
    return 0;
}
