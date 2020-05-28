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

#define MAX 2000 + 10
ii pd[MAX][MAX];
int e[MAX];
char s[MAX];

ii soma(ii a, ii b) { return ii(a.first + b.first, a.second + b.second); }
ii sol(int i, int j) {
    if (i > j)
        return ii(0, 0);
    if (i == j)
        return ii(e[i], 1);
    if (pd[i][j] != ii(-1, -1))
        return pd[i][j];

    ii a = ii(0, 0), b, c;

    if (s[i] == s[j])
        a = soma(ii(e[i] + e[j], 2), sol(i + 1, j - 1));

    b = sol(i + 1, j);
    c = sol(i, j - 1);

    return pd[i][j] = max(a, max(b, c));
}

int main() {
    while (scanf("%s", s) == 1) {
        int slen = strlen(s);
        for (int i = 0; i <= slen; i++) {
            e[i] = 0;
            for (int j = 0; j <= slen; j++)
                pd[i][j] = ii(-1, -1);
        }
        int t, p;
        scanf("%d", &t);
        while (t--) {
            scanf("%d", &p);
            e[p - 1] = 1;
        }

        ii ret = sol(0, slen - 1);
        printf("%d\n", ret.second);
    }
    return 0;
}
