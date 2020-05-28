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

char T[110], P[1010];
int tlen, plen;
int pd[110][1010];

LL solve(int i, int j) {
    if (i == tlen)
        return 1;
    if (j == plen)
        return 0;
    if (pd[i][j] != -1)
        return pd[i][j];

    LL ans = solve(i, j + 1);
    if (T[i] == P[j])
        ans += solve(i + 1, j + 1);
    return pd[i][j] = ans;
}

int main() {
    int inst = 1;
    while (scanf("%d %d\n", &tlen, &plen) == 2) {
        if (tlen == 0 && plen == 0)
            break;
        gets(T);
        gets(P);
        memset(pd, -1, sizeof pd);
        printf("Instancia %d\n%lld\n\n", inst++, solve(0, 0));
    }
    return 0;
}
