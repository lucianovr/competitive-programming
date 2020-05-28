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
    int n, k, picos, vales, v[1010];
    while (scanf("%d %d", &n, &k) == 2) {
        picos = 0;
        vales = 0;
        rep(i, 0, n) scanf("%d", &v[i]);

        for (int i = 1; i < n - 1; ++i) {
            if (v[i - 1] < v[i] && v[i] > v[i + 1])
                picos++;
            else if (v[i - 1] > v[i] && v[i] < v[i + 1])
                vales++;
        }

        if (picos == k && vales == k - 1)
            printf("beautiful\n");
        else
            printf("ugly\n");
    }
    return 0;
}
