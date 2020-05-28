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
    char mat[5][100];

    rep(i, 0, 4) gets(mat[i]);

    int F = 0, L = 0;

    int len = strlen(mat[0]);
    rep(i, 0, 4) {
        F = F * 10 + mat[i][0] - '0';
        L = L * 10 + mat[i][len - 1] - '0';
    }

    string s;
    rep(i, 1, len - 1) {
        int M = 0;
        rep(j, 0, 4) M = M * 10 + mat[j][i] - '0';
        s += (char)((F * M + L) % 257);
    }
    cout << s << "\n";

    return 0;
}
