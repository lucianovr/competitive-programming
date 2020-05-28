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

ll dp[20][2][1 << 20];

vector<int> A;
ll S(int i, int igual, int mask, ll valor) {
    if (i == A.size())
        return valor;

    if (dp[i][igual][mask] != -1)
        return dp[i][igual][mask];

    ll ans = 0;
    int d;
    if (igual == 0) {
        for (d = 9; d >= 0; d--) {
            if ((mask & (1 << d)) == 0)
                ans = max(ans, S(i + 1, 0, mask | (1 << d), valor * 10 + d));
            else if ((mask & (1 << (d + 10))) == 0)
                ans = max(ans, S(i + 1, 0, mask | (1 << (d + 10)), valor * 10 + d));
        }
    } else {
        d = A[i];
        if ((mask & (1 << d)) == 0)
            ans = max(ans, S(i + 1, 1, mask | (1 << d), valor * 10 + d));
        else if ((mask & (1 << (d + 10))) == 0)
            ans = max(ans, S(i + 1, 1, mask | (1 << (d + 10)), valor * 10 + d));

        for (d = A[i] - 1; d >= 0; d--) {
            if ((mask & (1 << d)) == 0)
                ans = max(ans, S(i + 1, 0, mask | (1 << d), valor * 10 + d));
            else if ((mask & (1 << (d + 10))) == 0)
                ans = max(ans, S(i + 1, 0, mask | (1 << (d + 10)), valor * 10 + d));
        }
    }

    return dp[i][igual][mask] = ans;
}

int main() {
    ll X;
    while (scanf("%lld", &X) == 1) {
        A.clear();
        while (X) {
            A.pb(X % 10);
            X /= 10;
        }
        reverse(all(A));

        memset(dp, -1, sizeof dp);

        printf("%lld\n", S(0, 1, 0, 0));
    }
    return 0;
}
