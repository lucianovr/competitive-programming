#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define NN 20

int B[NN][3];
int N;

ll memo[NN][3][1 << 16];

int X(int n) { return B[n][0]; }
int Y(int n) { return B[n][1]; }
int Z(int n) { return B[n][2]; }
// X<=Y<=Z

ll dp(int i, int W, int L, int pos, int mask) {
    if (mask == ((1 << N) - 1))
        return 0;
    ll &ans = memo[i][pos][mask];
    if (ans != -1)
        return ans;

    ans = 0;
    for (int j = 0; j < N; j++) {
        if (!(mask & (1 << j))) {
            if (X(j) >= W && Y(j) >= L)
                ans = max(ans, Z(j) + dp(j, X(j), Y(j), 0, mask | (1 << j)));
            if (X(j) >= W && Z(j) >= L)
                ans = max(ans, Y(j) + dp(j, X(j), Z(j), 1, mask | (1 << j)));
            if (Y(j) >= W && Z(j) >= L)
                ans = max(ans, X(j) + dp(j, Y(j), Z(j), 2, mask | (1 << j)));
        }
    }
    return ans;
}

int main() {

    int t;
    cin >> t;
    while (t--) {
        cin >> N;
        for (int i = 0; i < N; i++) {
            for (int k = 0; k < 3; k++)
                cin >> B[i][k];   // X, Y, Z
            sort(B[i], B[i] + 3); // X<=Y<=Z
        }
        for (int i = 0; i <= N; i++)
            for (int pos = 0; pos < 3; pos++)
                for (int m = 0; m <= (1 << (N + 1)); m++)
                    memo[i][pos][m] = -1;

        printf("%lld\n", dp(N, 0, 0, 0, 0));
    }
    return 0;
}