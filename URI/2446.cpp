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

int dp[100010];
int coin[1010];
int main() {
    int T, N;

    while (scanf("%d %d", &T, &N) == 2) {
        int sum = 0;
        f(i, 0, N) {
            scanf("%d", &coin[i]);
            sum += coin[i];
        }
        f(i, 0, T + 1) dp[i] = 0;

        f(i, 0, T + 1) dp[i] = 0;
        dp[0] = 1;
        int r = 0; // rightmost
        f(c, 0, N) for (int t = r; t >= 0; t--) {
            if (dp[t] && t + coin[c] <= T) {
                dp[t + coin[c]] = 1;
                r = max(r, t + coin[c]);
            }
        }
        dp[T] ? printf("S\n") : printf("N\n");
    }
    return 0;
}