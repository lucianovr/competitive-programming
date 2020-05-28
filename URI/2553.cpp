#include <bits/stdc++.h>
using namespace std;

int G[40], Y[40], N;
int dp[40][40 * 20 + 10][40 * 20 + 10];

int mabs(int x) {
    if (x < 0)
        return -x;
    return x;
}

int mmax(int a, int b) {
    if (a > b)
        return a;
    else
        return b;
}

int S(int n, int g, int y) {
    if (n == N)
        return 0;

    int &r = dp[n][g][y];
    if (r > -1)
        return r;

    r = S(n + 1, g, y);
    if (G[n] < 0 && g >= mabs(G[n])) {
        r = mmax(r, 1 + S(n + 1, g - mabs(G[n]), y + mabs(Y[n])));
    }
    if (Y[n] < 0 && y >= mabs(Y[n])) {
        r = mmax(r, 1 + S(n + 1, g + mabs(G[n]), y - mabs(Y[n])));
    }
    return r;
}

int main() {

    while (scanf("%d", &N) == 1) {
        int gg, yy;
        scanf("%d %d", &gg, &yy);

        for (int i = 0; i < N; i++)
            scanf("%d %d", &G[i], &Y[i]);

        memset(dp, -1, sizeof dp);
        cout << S(0, gg, yy) << "\n";
    }
    return 0;
}