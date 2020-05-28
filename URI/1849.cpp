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

int main() {
    int a, b, L, C;
    int ans, x, y;
    while (cin >> a >> b >> L >> C) {
        ans = 0;

        // 1
        x = b + C;
        y = min(a, L);
        ans = min(x, y) * min(x, y);

        // 2
        x = b + L;
        y = min(a, C);
        ans = max(ans, min(x, y) * min(x, y));

        // 3
        x = min(b, C);
        y = a + L;
        ans = max(ans, min(x, y) * min(x, y));

        // 4
        x = min(b, L);
        y = a + C;
        ans = max(ans, min(x, y) * min(x, y));

        cout << ans << "\n";
    }

    return 0;
}