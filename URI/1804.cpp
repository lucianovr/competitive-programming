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

const int M = 100010;
LL N, BIT[M];

void update(int i, LL v) {
    while (i <= N) {
        BIT[i] += v;
        i += i & -i;
    }
}

LL query(int i) {
    LL ans = 0;
    while (i > 0) {
        ans += BIT[i];
        i -= i & -i;
    }
    return ans;
}

int main() {
    while (scanf("%d", &N) == 1) {
        vector<LL> v(N + 1);

        rep(i, 1, N + 1) {
            scanf("%lld", &v[i]);
            update(i, v[i]);
        }

        char op;
        int i;
        while (scanf(" %c", &op) == 1) {
            scanf("%d", &i);
            if (op == 'a')
                update(i, -v[i]);
            else
                printf("%lld\n", query(i - 1));
        }
    }
    return 0;
}
