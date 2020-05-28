#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i(a); i < (b); i++)
#define debug(x) cout << #x << " = " << x << "\n";

#define ALL(c) c.begin(), c.end()
#define SORT(c) sort(ALL(c))
#define UNIQUE(c)                                                                                                      \
    {                                                                                                                  \
        SORT(c);                                                                                                       \
        (c).resize(unique(ALL(c)) - c.begin());                                                                        \
    }
#define pb push_back
#define sz size()
#define D(x)                                                                                                           \
    if (1)                                                                                                             \
        cout << __LINE__ << " " << #x " = " << (x) << endl;
#define D2(x, y)                                                                                                       \
    if (1)                                                                                                             \
        cout << __LINE__ << " " << #x " = " << (x) << ", " << #y " = " << (y) << endl;

typedef pair<int, int> ii;
typedef vector<int> VI;
typedef vector<ii> VII;
typedef long long LL;

LL mod = (LL)(pow(2.0, 31) - 1);

LL exp(LL b, LL p) {
    if (p == 0)
        return 1;
    if (p == 1)
        return b % mod;
    LL ret = exp(b, p / 2);
    ret = ((ret % mod) * (ret % mod)) % mod;
    if (p & 1)
        ret = (ret * (b % mod)) % mod;

    return ret;
}

int main() {
    LL p, ans;
    cin >> p;
    ans = exp(3LL, p);
    printf("%lld\n", ans);

    return 0;
}
