#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i(a); i < (b); i++)

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
typedef long long ll;

const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;

int pd[200010][2], n, c, v[200010];

int sol(int i, int d) {
    if (i == n)
        return 0;
    if (pd[i][d] != -INF)
        return pd[i][d];

    if (d == 0) { // nao comprou
        return pd[i][0] = max(sol(i + 1, 0), sol(i + 1, 1) - v[i] - c);
    }
    if (d == 1) {
        return pd[i][1] = max(sol(i + 1, 1), sol(i + 1, 0) + v[i]);
    }
}

int main() {
    while (scanf("%d %d", &n, &c) == 2) {
        for (int i = 0; i < n; i++) {
            scanf("%d", &v[i]);
            pd[i][0] = pd[i][1] = -INF;
        }

        int ret = sol(0, 0);
        printf("%d\n", ret);
    }
    return 0;
}
