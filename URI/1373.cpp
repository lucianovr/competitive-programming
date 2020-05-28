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

int k;
int pd[1001][1001][2], xlen, ylen;
char x[1010], y[1010];

int lcs(int i, int j, int f) {
    if (i == xlen || j == ylen)
        return 0;
    if (pd[i][j][f] != -1)
        return pd[i][j][f];

    int A = 0, B = 0, C = 0, D = 0;

    A = lcs(i + 1, j, 1);
    B = lcs(i, j + 1, 1);

    if (f == 0) {
        if (x[i] == y[j])
            C = 1 + lcs(i + 1, j + 1, 0);
    }

    if (f == 1) {
        if (i + k <= xlen && j + k <= ylen) {
            bool ok = true;
            for (int l = 0; l < k && ok; l++) {
                if (x[i + l] != y[j + l])
                    ok = false;
            }
            if (ok)
                D = lcs(i + k, j + k, 0) + k;
        }
    }

    return pd[i][j][f] = max(max(A, B), max(C, D));
}

int main() {
    while (scanf("%d", &k) && k) {
        scanf(" %s %s", x, y);
        xlen = strlen(x);
        ylen = strlen(y);

        rep(i, 0, 1 + xlen) rep(j, 0, 1 + ylen) pd[i][j][0] = pd[i][j][1] = -1;

        printf("%d\n", lcs(0, 0, 1));
    }
    return 0;
}
