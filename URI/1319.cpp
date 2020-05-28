#include <bits/stdc++.h>
using namespace std;

#define MAX 112

typedef long long LL;

int M, N;
int g[MAX][MAX];
int S[MAX], F[MAX];

LL Mod = 100000000;
LL dp[MAX][MAX];

LL sol(int i, int j) {
    if (F[j] >= M)
        return 1;
    LL &r = dp[i][j];
    if (r > -1)
        return r;

    r = 0;
    for (int k = 1; k <= N; k++) {
        if (i != j) {
            if (g[j][k] && !g[i][k])
                r = (r + sol(j, k)) % Mod;
        } else {
            if (g[i][k]) {
                r = (r + sol(j, k)) % Mod;
            }
        }
    }
    return r;
}

int main() {

    while (cin >> M >> N) {
        if (M == 0 && N == 0)
            break;

        for (int i = 1; i <= N; i++) {
            cin >> S[i] >> F[i];
        }

        memset(g, 0, sizeof g);
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (i == j)
                    continue;
                if (S[j] > S[i] && S[j] <= F[i] && F[j] > F[i])
                    g[i][j] = 1;
            }
        }

        memset(dp, -1, sizeof dp);
        long long ans = 0;
        for (int i = 1; i <= N; i++)
            if (S[i] == 0) {
                ans = (ans + sol(i, i)) % Mod;
            }
        cout << ans << "\n";
    }
    return 0;
}