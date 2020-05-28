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

bool cmp(char a, char b) { return a > b; }
LL toInt(char s[]) {
    LL ans = 0;
    int len = strlen(s);
    rep(i, 0, len) { ans = ans * 10LL + s[i] - '0'; }
    return ans;
}

int main() {
    char x[100], y[100];
    LL X, Y, Ymax, Ymin;

    while (scanf(" %s", x) == 1) {
        int xlen = strlen(x);
        X = toInt(x);

        sort(x, x + xlen, cmp);
        Ymax = toInt(x);

        sort(x, x + xlen);
        int id = 0;
        while (id < xlen && x[id] == '0')
            id++;
        if (id < xlen)
            swap(x[0], x[id]);
        Ymin = toInt(x);
        if (id < xlen)
            swap(x[0], x[id]);

        LL Mmin = sqrt(X + Ymin) - 1;
        LL Mmax = sqrt(X + Ymax) + 1;

        int cont = 0;

        VI contX(10), contY(10);
        rep(i, 0, xlen) contX[x[i] - '0']++;

        for (long long M = 1; M <= 1420010; M++) {
            LL Y = M * M - X;
            if (Y < 0)
                continue;
            rep(i, 0, 10) contY[i] = 0;
            while (Y) {
                contY[Y % 10]++;
                Y /= 10;
            }

            if (contX == contY)
                cont++;
        }

        printf("%d\n", cont);
    }
    return 0;
}
