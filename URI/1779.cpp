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
        cout << "|" << __LINE__ << " " << #x " = " << (x) << ", " << #y " = " << (y) << endl;

typedef pair<int, int> ii;
typedef vector<int> VI;
typedef vector<ii> VII;
typedef long long LL;

int main() {

    int t, n;
    scanf("%d", &t);
    rep(k, 0, t) {
        scanf("%d", &n);
        int v[n + 1];

        int ma = -1;
        rep(i, 0, n) {
            scanf("%d", &v[i]);
            if (v[i] > ma)
                ma = v[i];
        }

        int cont = 0, ans = 0;

        for (int i = 0; i < n; i++) {
            if (v[i] == ma) {
                cont = 1;
                int j = i + 1;
                while (j < n && v[j] == ma) {
                    cont++;
                    j++;
                }
                i = j;
                ans = max(ans, cont);
            }
        }
        printf("Caso #%d: %d\n", k + 1, ans);
    }
    return 0;
}
