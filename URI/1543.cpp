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

int N, M, T;
char padrao[110][110];
int grid[110][110], pd[110][110];
vi adj[110];

bool casa(int i, int j) {
    for (int k = 0; k < M; k++)
        if (padrao[i][k] == padrao[j][k] && padrao[j][k] != '.')
            return false;
    return true;
}

int solve(int i, int t) {

    if (i == N)
        return 0;

    if (pd[i][t] != -INF)
        return pd[i][t];

    int soma = 0; // soma da linha i usando o padrao t

    for (int j = 0; j < M; j++)
        if (padrao[t][j] == '+')
            soma += grid[i][j];
        else if (padrao[t][j] == '-')
            soma -= grid[i][j];

    int ans = -INF;

    rep(j, 0, adj[t].size()) { // para cada um dos padroes que podem vir abaixo do padrao T
        int p = adj[t][j];
        ans = max(ans, soma + solve(i + 1, p));
    }

    return pd[i][t] = ans;
}

int main() {
    char s[1000];
    while (scanf("%d%d", &N, &M) && N + M) {

        rep(i, 0, N) // M*N
            rep(j, 0, M) {
            scanf("%d", &grid[i][j]);
        }

        scanf("%d", &T);

        rep(i, 0, T) adj[i].clear(); // limpando, T

        rep(i, 0, T) scanf("%s", padrao[i]);

        rep(i, 0, T) // M^2
            for (int j = i; j < T; j++) if (casa(i, j)) {
            adj[i].pb(j);
            if (i != j)
                adj[j].pb(i);
        }

        for (int i = 0; i < N; i++)
            for (int j = 0; j < T; j++)
                pd[i][j] = -INF;

        int ans = -INF, ret;
        for (int t = 0; t < T; t++) // para cada um dos padroes para a primeira linha, ela nao tem restricao...
        {
            ret = solve(0, t);
            ans = max(ans, ret);
        }

        printf("%d\n", ans);
    }
    return 0;
}