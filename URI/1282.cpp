#include <bits/stdc++.h>
using namespace std;
#define f(i, a, b) for (int i = (a); i < (b); i++)
#define all(c) (c).begin(), (c).end()
#define F first
#define S second
#define debug(x) cout << __LINE__ << ": " << #x << " = " << x << endl;
#define debug2(x, y) cout << #x << " = " << x << "  " << #y << " = " << y << endl;
#define pb push_back
#define mp make_pair

const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<vector<int>> vvi;

#define MAXN 1010
ll W[MAXN], X[MAXN];
ll C[MAXN][MAXN];
ll dp[MAXN][MAXN];
int L[MAXN][MAXN];
int N, K;

/*
ll S(int n, int k){
        if (k == 1) return C[1][n];
        if (n == 0) return 0;
        
        ll& r = dp[n][k];
        if (r != -1) return r;
        r = ((1LL)<<58);
        for (int i = 1; i < n; i++)
                r = min(r, S(i,k-1) + C[i+1][n]);
        return r;
}
*/

ll solve() {
    for (int n = 1; n <= N; n++)
        dp[n][1] = C[1][n];
    for (int k = 0; k <= K; k++)
        dp[0][k] = 0;

    for (int i = 0; i <= N + 2; i++)
        for (int j = 0; j <= K + 2; j++)
            L[i][j] = -1;

    for (int k = 2; k <= K; k++) {
        for (int n = N; n >= 1; n--) {
            int inf = L[n][k - 1];
            if (inf == -1)
                inf = 1;
            int sup = L[n + 1][k];
            if (sup == -1)
                sup = n - 1;
            ll ans = ((1LL) << 60);
            for (int i = inf; i <= sup; i++) {
                ll tmp = dp[i][k - 1] + C[i + 1][n];
                if (tmp < ans) {
                    ans = tmp;
                    L[n][k] = i;
                }
            }
            dp[n][k] = ans;
        }
    }
    return dp[N][K];
}

int main() {
    while (scanf("%d %d", &N, &K) == 2) {
        for (int i = 1; i <= N; i++) {
            scanf("%lld %lld", &X[i], &W[i]);
        }
        for (int j = N; j >= 1; j--) {
            C[j][j] = 0;
            for (int i = j - 1; i >= 1; i--) {
                C[i][j] = W[i] * (X[j] - X[i]) + C[i + 1][j];
            }
        }
        ll ret = solve();
        cout << ret << "\n";
    }

    return 0;
}