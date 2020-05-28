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

int main() {

    int n, v[110][2], ans;
#define start 0
#define end 1

    while (scanf("%d", &n) && n) {
        rep(i, 0, n) {
            scanf("%d", &v[i][start]);
            v[i][end] = v[i][start] + 10;
        }
        ans = 10;
        rep(i, 1, n) { ans += 10 - (v[i - 1][end] > v[i][start] ? v[i - 1][end] - v[i][start] : 0); }
        printf("%d\n", ans);
    }
    return 0;
}
