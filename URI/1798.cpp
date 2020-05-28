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

const int INF = 0x3f3f3f3f;
int pd[2010][1010], tam[1010], valor[1010], n, MIN;

int solve(int t, int i) {
    if (i == n)
        return 0;
    if (pd[t][i] != -1)
        return pd[t][i];

    int ret = solve(t, i + 1);
    if (t - tam[i] >= 0)
        ret = max(ret, solve(t - tam[i], i) + valor[i]);

    return pd[t][i] = ret;
}

int main() {
    int t;
    while (cin >> n >> t) {
        MIN = 2010;
        memset(pd, -1, sizeof pd);
        rep(i, 0, n) { scanf("%d %d", &tam[i], &valor[i]); }
        printf("%d\n", solve(t, 0));
    }
    return 0;
}
