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

#define MIN -1000000000
const double EPS = 1e-9;
ll v[10010], pd[10010][3];

ll solve(int n) {
    for (int j = 0; j < 2; j++) {
        for (int i = n - 1; i >= 0; i--) {
            if (i == j)
                pd[i][j] = v[i];
            else if (i > j)
                pd[i][j] = 0;
            else {
                ll a = 0, b = 0, x = 0, y = 0;
                if (i + 2 < n)
                    x = pd[i + 2][j];
                if (i + 1 < n && j - 1 >= 0)
                    y = pd[i + 1][j - 1];

                a = v[i] + max(x, y);

                x = 0;
                y = 0;
                if (j - 2 >= 0)
                    x = pd[i][j - 2];
                if (i + 1 < n && j - 1 >= 0)
                    y = pd[i + 1][j - 1];
                b = v[j] + max(x, y);

                pd[i][j] = max(a, b);
            }
        }
    }
    int col2 = 0, col1 = 1, col = 2;

    for (int j = 2; j < n; j++) {
        for (int i = n - 1; i >= 0; i--) {
            // cout << "("<< i << "," << j << ")\n";
            if (i == j)
                pd[i][col] = v[i];
            else if (i > j)
                pd[i][col] = 0;
            else {
                ll a = 0, b = 0, x = 0, y = 0;
                if (i + 2 < n)
                    x = pd[i + 2][col];
                if (i + 1 < n && j - 1 >= 0)
                    y = pd[i + 1][col1];

                a = v[i] + max(x, y);

                x = 0;
                y = 0;
                if (j - 2 >= 0)
                    x = pd[i][col2];
                if (i + 1 < n && j - 1 >= 0)
                    y = pd[i + 1][col1];
                b = v[j] + max(x, y);

                pd[i][col] = max(a, b);
            }
        }
        for (int i = 0; i < n; ++i) {
            pd[i][col2] = pd[i][col1];
            pd[i][col1] = pd[i][col];
        }
    }

    return pd[0][2];
}

int main() {

    int n;
    ll ret;
    while (scanf("%d", &n) == 1) {
        for (int i = 0; i < n; ++i)
            scanf("%lld", &v[i]);
        if (n == 2)
            ret = max(v[0], v[1]);
        else
            ret = solve(n);
        printf("%lld\n", ret);
    }
    return 0;
}
