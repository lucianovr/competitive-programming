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
    int n, v[4], inst = 1;

    while (scanf("%d", &n) && n) {

        vector<VI> m;
        int x, y, z;
        m.resize(n);

        rep(i, 0, n) {
            scanf(" %d %d %d", &x, &y, &z);
            m[i].pb(x);
            m[i].pb(y);
            m[i].pb(z);
            SORT(m[i]);
        }
        UNIQUE(m);
        n = m.size();

        set<int> s;
        vector<VI> ans;

        rep(i, 0, n) rep(j, i + 1, n) rep(k, j + 1, n) rep(l, k + 1, n) {
            s.clear();
            rep(u, 0, 3) s.insert(m[i][u]);
            rep(u, 0, 3) s.insert(m[j][u]);
            if (s.size() > 4)
                continue;
            rep(u, 0, 3) s.insert(m[k][u]);
            if (s.size() > 4)
                continue;
            rep(u, 0, 3) s.insert(m[l][u]);
            if (s.size() == 4)
                ans.pb(VI(ALL(s)));
        }

        printf("Instancia %d\n", inst++);
        if (ans.size() == 0)
            printf("ok\n\n");
        else {
            UNIQUE(ans);
            rep(i, 0, ans.size()) {
                rep(j, 0, 4) {
                    if (j)
                        printf(" ");
                    printf("%d", ans[i][j]);
                }
                printf("\n");
            }
            printf("\n");
        }
    }
    return 0;
}