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
    int n, v[100010], pos[100010];
    while (scanf("%d", &n) && n) {
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &v[i]);
            pos[v[i]] = i;
        }
        bool ok = true;
        for (int i = 1; ok && i <= n; ++i) {
            if (v[i] != pos[i])
                ok = false;
        }

        if (ok)
            printf("ambiguous\n");
        else
            printf("not ambiguous\n");
    }
    return 0;
}
