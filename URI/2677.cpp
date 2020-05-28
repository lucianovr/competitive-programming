#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define pb push_back
#define mk make_pair
#define debug(x) cout << __LINE__ << ": " << #x << " = " << x << endl;
#define all(c) (c).begin(), (c).end()
#define F first
#define S second
#define UNIQUE(c)                                                                                                      \
    sort(all(c));                                                                                                      \
    (c).resize(unique(all(c)) - c.begin());
#define PI 3.1415926535897932384626433832795028841971

typedef long long ll;
typedef pair<int, int> ii;
const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;
//(-1: x<y) (0: x==y) (1: x>y)
inline int cmp(double x, double y = 0, double tol = EPS) { return ((x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1); }

#define MAXN 1000 + 10
ll dp[MAXN][MAXN];
ll v[MAXN];

ll S(int i, int j) {
    if (i > j)
        return 0;
    if (i == j)
        return !(v[i] & 1);
    if (i + 1 == j)
        return (!(v[i] & 1) || !(v[j] & 1));

    ll &r = dp[i][j];
    if (r > -1)
        return r;

    // escolher i (i,j) -> (i+1,j) = (i+2,j) || (i+1,j-1)
    ll a, b;
    a = !(v[i] & 1) + min(S(i + 2, j), S(i + 1, j - 1));

    // escolher j (i,j) -> (i,j-1) = (i,j-2) || (i+1,j-1)
    b = !(v[j] & 1) + min(S(i, j - 2), S(i + 1, j - 1));
    return r = max(a, b);
}

ll iter(int N) {
    /*
            (i, j)
                    (i+1,j-1)
                    (i+2,j)
                    (i,j-2)
    */
    int a, b, c, op1, op2;
    for (int i = 2 * N - 1; i >= 0; i--) {
        for (int j = 0; j < 2 * N; j++) {
            if (i >= j)
                dp[i][j] = 0;
            else if (i == j)
                dp[i][j] = !(v[i] & 1);
            else if (i + 1 == j)
                dp[i][j] = (!(v[i] & 1) || !(v[j] & 1));
            else {
                a = dp[i + 2][j];
                b = dp[i + 1][j - 1];
                c = dp[i][j - 2];
                op1 = !(v[i] & 1) + min(a, b);
                op2 = !(v[j] & 1) + min(b, c);
                dp[i][j] = max(op1, op2);
            }
        }
    }
    return dp[0][2 * N - 1];
}

int main() {
    int N;
    while (scanf("%d", &N) && N) {
        rep(i, 0, 2 * N) scanf("%lld", &v[i]);
        printf("%lld\n", iter(N));
    }
    return 0;
}