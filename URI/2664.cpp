#include <stdio.h>
#include <string.h>
#define MOD 1000000007

int T, M, N;
long long dp[51][100001];
long long sol(int t, int ult) {
    if (ult > N || ult < M)
        return 0;
    if (t == T)
        return 1;

    long long &ret = dp[t][ult];
    if (ret == -1)
        ret = (sol(t + 1, ult - 1) + sol(t + 1, ult + 1)) % MOD;
    return ret;
}
int main() {
    scanf("%d %d %d", &T, &M, &N);
    memset(dp, -1, sizeof dp);
    long long resp = 0;
    for (int v = M; v <= N; v++) {
        resp = (resp + sol(1, v)) % MOD;
    }
    printf("%lld\n", resp);

    return 0;
}
