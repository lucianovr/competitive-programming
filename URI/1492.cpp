#include <bits/stdc++.h>
using namespace std;

#define f(i, a, b) for (int i(a); i < (b); i++)

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
typedef unsigned long long ll;

const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;

string A;
int szA;
ll dp[100][2][100];

ll solve(int pos, int prefix, ll uns) {
    if (pos == szA)
        return uns;
    if (dp[pos][prefix][uns] != -1)
        return dp[pos][prefix][uns];

    ll ret = 0;
    if (prefix == 0) {
        ret += solve(pos + 1, 0, uns) + solve(pos + 1, 0, uns + 1);
    } else {
        if (A[pos] == '0')
            ret += solve(pos + 1, 1, uns);
        else {
            ret += solve(pos + 1, 0, uns) + solve(pos + 1, 1, uns + 1);
        }
    }

    return dp[pos][prefix][uns] = ret;
}

string toBase2(ll x) {
    string ret;
    while (x) {
        ret += char(x % 2 + '0');
        x /= 2;
    }
    reverse(ALL(ret));
    return ret;
}

int main() {
    ll a, b;
    while (scanf("%lld %lld", &a, &b) == 2) {
        a--;
        A = toBase2(b);
        szA = A.size();
        memset(dp, -1, sizeof dp);
        ll sup = solve(0, 1, 0);

        A = toBase2(a);
        szA = A.size();
        memset(dp, -1, sizeof dp);
        ll inf = solve(0, 1, 0);

        printf("%lld\n", sup - inf);
    }
    return 0;
}
