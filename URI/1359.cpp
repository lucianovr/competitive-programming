#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i(a); i < (b); i++)

#define ALL(c) c.begin(), c.end()
#define UNIQUE(c)                                                                                                      \
    { sort(ALL(c); (c).resize( unique(ALL(c))-c.begin() );                                               \
    }
#define pb push_back
#define sz size()
#define D(x)                                                                                                           \
    if (1)                                                                                                             \
        cout << __LINE__ << " " << #x " = " << (x) << endl;

typedef pair<int, int> ii;
typedef long long ll;

const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;

#define MAX_N 1000

int sum[MAX_N * 2];
int dp[MAX_N * 2][MAX_N * 2];

#define soma(i, j) (sum[j] - sum[i - 1])

int sol(int i, int j) {
    if (i >= j)
        return dp[i][j] = 0;
    if (dp[i][j] == -1) {
        dp[i][j] = INF;
        for (int k = i; k < j; k++) {
            dp[i][j] = min(dp[i][j], sol(i, k) + sol(k + 1, j) + max(soma(i, k), soma(k + 1, j)));
        }
    }
    return dp[i][j];
}

int main() {
    int n;
    double f;
    vector<int> v;
    int x, best;
    while (scanf("%d %lf", &n, &f) == 2) {
        if (n == 0)
            break;

        v.clear();
        v.push_back(0);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &x);
            v.push_back(x);
        }

        for (int i = 1; i < n; i++)
            v.push_back(v[i]);

        sum[0] = 0;
        for (int i = 1; i < v.size(); i++)
            sum[i] = sum[i - 1] + v[i];

        memset(dp, -1, sizeof dp);

        best = INF;
        sol(1, v.size());
        for (int i = 1; i <= n; i++)
            best = min(best, dp[i][i + n - 1]);

        printf("%.2lf\n", ((double)best) * f);
    }
    return 0;
}
