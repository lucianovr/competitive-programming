#include <bits/stdc++.h>
using namespace std;

int N;
double X[20], Y[20];
int t;

double dp[1 << 16];
int seen[1 << 16];

#define dist(i, j) (hypot(X[i] - X[j], Y[i] - Y[j]))

double sol(int mask) {
    if (mask == (1 << N) - 1)
        return 0;

    if (seen[mask] == t)
        return dp[mask];
    seen[mask] = t;

    int a, b;
    double best = 2000000;
    for (a = 0; a < N; a++)
        if ((mask & (1 << a)) == 0)
            break;

    for (b = 0; b < N; b++)
        if ((mask & (1 << b)) == 0 && b != a) {
            best = min(best, dist(a, b) + sol(mask | (1 << a) | (1 << b)));
        }
    return dp[mask] = best;
}

int main() {

    int T;
    scanf("%d", &T);
    for (t = 1; t <= T; t++) {
        scanf("%d", &N);
        for (int i = 0; i < N; i++) {
            scanf("%lf %lf", X + i, Y + i);
        }
        printf("%.2lf\n", sol(0));
    }
    return 0;
}