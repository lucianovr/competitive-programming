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

#define MAX 1000010
int t, n, k, pos[MAX], lucro[MAX], prox[MAX];
int pd[MAX];

int solve(int i) {
    if (i >= n)
        return 0;
    if (pd[i] != -1)
        return pd[i];
    return pd[i] = max(solve(i + 1), lucro[i] + solve(prox[i]));
}

int main() {

    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &n, &k);
        rep(i, 0, n) scanf("%d", &pos[i]);
        rep(i, 0, n) scanf("%d", &lucro[i]);

        rep(i, 0, n) { prox[i] = lower_bound(pos + i, pos + n, pos[i] + k) - pos; }

        memset(pd, -1, sizeof pd);
        printf("%d\n", solve(0));
    }
    return 0;
}
