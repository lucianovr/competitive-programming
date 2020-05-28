#include <bits/stdc++.h>
using namespace std;

int n;
int p[10010];
int dp[10010][15];

int sol(int i, int dif) {
    if (abs(dif) > 5)
        return 0;
    if (i == n)
        return 1;

    int &r = dp[i][dif + 5];
    if (r == -1) {
        r = sol(i + 1, dif + p[i]) | sol(i + 1, dif - p[i]);
    }
    return r;
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &p[i]);
        }
        memset(dp, -1, sizeof dp);
        int ret = sol(0, 0);
        if (ret)
            printf("Feliz Natal!\n");
        else
            printf("Ho Ho Ho!\n");
    }
    return 0;
}