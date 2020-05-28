#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(c) (c).begin(), (c).end()
#define F first
#define S second
#define debug(x) cout << __LINE__ << ": " << #x << " = " << x << endl;
#define debug2(x, y) cout << #x << " = " << x << "  " << #y << " = " << y << endl;
#define pb push_back
#define mk make_pair

const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;
typedef long long ll;
typedef pair<int, int> ii;

int N, P;
vector<pair<int, int>> F;

int dp[1010][2010];

int sol(int n, int p) {
    if (p <= 0)
        return 0;
    if (n < 0)
        return INF;
    int &r = dp[n][p];
    if (r != -1)
        return r;

    return r = min(sol(n - 1, p), sol(n - 1, p - F[n].first) + F[n].second);
}

int main() {
    while (cin >> N >> P) {
        F.resize(N);
        rep(i, 0, N) { cin >> F[i].first >> F[i].second; }
        memset(dp, -1, sizeof dp);
        int ret = sol(N - 1, P);
        if (ret >= INF)
            ret = -1;
        cout << ret << "\n";
    }
    return 0;
}
