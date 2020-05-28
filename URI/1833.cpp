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
    if (0)                                                                                                             \
        cout << __LINE__ << " " << #x " = " << (x) << endl;
#define D2(x, y)                                                                                                       \
    if (1)                                                                                                             \
        cout << __LINE__ << " " << #x " = " << (x) << ", " << #y " = " << (y) << endl;

typedef pair<int, int> ii;
typedef vector<int> VI;
typedef vector<ii> VII;
typedef long long LL;

int pd[110][110], X[110], Y[110];
const int delet = 1, insert = 5, subst = 2;

int solve(int i, int j) {
    //	cout << i << " "<< j << "\n";

    if (i == -1)
        return (j + 1) * delet;
    if (j == -1)
        return (i + 1) * insert;

    if (pd[i][j] != -1)
        return pd[i][j];

    int a = 0, b = 0, c = 0;
    a = solve(i - 1, j) + insert;
    b = solve(i, j - 1) + delet;
    c = solve(i - 1, j - 1) + (X[i] == Y[j] ? 0 : subst);

    // cout << a << " " << b << " " << c << "\n";
    return pd[i][j] = min(a, min(b, c));
}

int main() {

    int t, m, n, p;
    cin >> t;
    map<string, int> mp;
    string cor;
    int k;

    rep(i, 0, t) {
        mp.clear();
        k = 1;

        cin >> p;
        cin >> m;
        rep(j, 0, m) {
            cin >> cor;
            D(cor);
            D(mp[cor]);
            if (mp[cor] == 0) {
                mp[cor] = k++;
            }
            Y[j] = mp[cor];
        }

        cin >> n;
        rep(j, 0, n) {
            cin >> cor;
            D(cor);
            D(mp[cor]);
            if (mp[cor] == 0) {
                mp[cor] = k++;
            }
            X[j] = mp[cor];
        }

        memset(pd, -1, sizeof pd);

        D(Y[0]);
        D(X[0]);

        int ans = solve(n - 1, m - 1);
        int tot = p * 50 * ans;
        char buffer[100];

        sprintf(buffer, "%d", tot);
        printf("Caso #%d: R$ ", i + 1);

        if (tot == 0)
            printf("0,00");
        else
            for (int j = 0; j < strlen(buffer); j++) {
                if (j == strlen(buffer) - 2)
                    printf(",");
                printf("%c", buffer[j]);
            }
        printf("\n");
    }
    return 0;
}
