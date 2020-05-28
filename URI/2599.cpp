#include <bits/stdc++.h>
using namespace std;

int m, n;
long long p[1010];
long long dp[40010];

long long sol(long long t) {
    if (t >= m)
        return 1;

    long long &r = dp[t];
    if (r == -1) {
        r = 0;
        for (int i = 0; i < n; i++) {
            r = (r + sol(t + p[i]));
            if (r > 1000000007LL)
                r %= 1000000007LL;
        }
    }
    return r;
}

long long rec() {
    memset(dp, 0, sizeof dp);
    for (int t = m; t <= 2 * m; t++)
        dp[t] = 1;

    for (int t = m - 1; t >= 0; t--) {
        for (int radar = 0; radar < n; radar++) {
            dp[t] = (dp[t] + dp[t + p[radar]]);
            if (dp[t] > 1000000007LL)
                dp[t] %= 1000000007LL;
        }
    }
    return dp[0];
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &m, &n);
        for (int i = 0; i < n; ++i) {
            scanf("%lld", &p[i]);
        }
        memset(dp, -1, sizeof dp);
        printf("%lld\n", rec());
    }
    return 0;
}