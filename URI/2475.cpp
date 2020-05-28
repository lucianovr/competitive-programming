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

const long long INF = ((1LL) << 60);
const double EPS = 1e-9;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<vector<int>> vvi;

ll v[10010];
ll dp[10002][502];
int L[10002][502];

inline long long C(int i, int j) { return (v[j] - v[i - 1]) * (j - i + 1); }

ll solve(int N, int K) {
    for (int n = 1; n <= N; n++)
        dp[n][1] = C(1, n);
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
                sup = n;
            ll ans = INF;
            for (int i = inf; i <= sup; i++) {
                ll tmp = dp[i - 1][k - 1] + C(i, n);
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
    int N, K;
    while (scanf("%d %d", &N, &K) == 2) {
        v[0] = 0;
        for (int i = 1; i <= N; i++) {
            scanf(" %lld", &v[i]);
            v[i] += v[i - 1];
        }
        printf("%lld\n", solve(N, K));
    }
    return 0;
}