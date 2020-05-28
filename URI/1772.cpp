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
    if (0)                                                                                                             \
        cout << __LINE__ << " " << #x " = " << (x) << endl;
#define D2(x, y)                                                                                                       \
    if (1)                                                                                                             \
        cout << __LINE__ << " " << #x " = " << (x) << ", " << #y " = " << (y) << endl;

typedef pair<int, int> ii;
typedef vector<int> VI;
typedef vector<ii> VII;
typedef long long LL;

int main() {
    unsigned int n, ma, me;
    int k, a, b;
    while (cin >> n >> k) {
        if (n == 0 && k == 0)
            break;
        ma = me = n;
        while (k--) {
            cin >> a >> b;
            int bitA = n & 1 << a;
            int bitB = n & 1 << b;

            if (bitA)
                n |= 1 << b;
            else
                n &= ~(1 << b);

            if (bitB)
                n |= 1 << a;
            else
                n &= ~(1 << a);
            ma = max(ma, n);
            me = min(me, n);
            D(n);
        }
        cout << n << " " << ma << " " << me << "\n";
    }
    return 0;
}
