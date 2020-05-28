#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i(a); i < (b); i++)

#define all(c) c.begin(), c.end()
#define UNIQUE(c)                                                                                                      \
    { sort(ALL(c); (c).resize( unique(ALL(c))-c.begin() );                                               \
    }
#define pb push_back
#define D(x)                                                                                                           \
    if (1)                                                                                                             \
        cout << __LINE__ << " " << #x " = " << (x) << endl;
#define DVEC(v, n)                                                                                                     \
    {                                                                                                                  \
        cout << #v << "[] ={ ";                                                                                        \
        rep(i, 0, n) cout << v[i] << " ";                                                                              \
        cout << "}\n";                                                                                                 \
    }
#define mp make_pair
#define fst first
#define snd second

typedef pair<int, int> ii;
typedef long long ll;

typedef vector<int> vi;
typedef vector<ii> vii;

const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;

int N, A[1010], S;
int dp[2][100010];

int main() {

    while (scanf(" %d", &N) && N) {
        S = 0;
        for (int i = 1; i <= N; i++) {
            scanf(" %d", &A[i]);
            S += A[i];
        }
        memset(dp, -1, sizeof dp);
        dp[0][0] = 0;
        for (int i = 1; i <= N; i++) {
            for (int d = 0; d <= S; d++)
                if (dp[0][d] != -1) {
                    dp[1][d] = max(dp[1][d], dp[0][d]);
                    dp[1][d + A[i]] = max(dp[1][d + A[i]], dp[0][d] + A[i]);
                    dp[1][abs(d - A[i])] = max(dp[1][abs(d - A[i])], dp[0][d] + A[i]);
                }
            for (int d = 0; d <= S; d++)
                dp[0][d] = dp[1][d];
        }

        printf("%d\n", dp[1][0] / 2);
    }
    return 0;
}
