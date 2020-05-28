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

int mat['z']['z'];
char comb[][4] = {"123", "159", "186", "456", "429", "483", "789", "726", "753",
                  "111", "222", "333", "444", "555", "666", "777", "888", "999"};
int qt[10];
LL ans;

void solve(LL x) {

    // rep(i,1,10) cout << i << " "; cout << "\n";
    // rep(i,1,10) cout << qt[i] << " "; cout << "\n\n";

    ans = max(ans, x);
    int a, b, c;

    rep(k, 0, 9) {
        a = comb[k][0] - '0';
        b = comb[k][1] - '0';
        c = comb[k][2] - '0';

        if (qt[a] > 0 && qt[b] > 0 && qt[c] > 0) {
            qt[a]--;
            qt[b]--;
            qt[c]--;
            solve(x + 1);
            qt[a]++;
            qt[b]++;
            qt[c]++;
        }
    }

    rep(i, 1, 10) {
        if (qt[i] >= 3) {
            qt[i] -= 3;
            solve(x + 1);
            qt[i] += 3;
        }
    }
}

int main() {

    mat['u']['c'] = 1;
    mat['d']['c'] = 2;
    mat['t']['c'] = 3;
    mat['u']['t'] = 4;
    mat['d']['t'] = 5;
    mat['t']['t'] = 6;
    mat['u']['q'] = 7;
    mat['d']['q'] = 8;
    mat['t']['q'] = 9;

    int n;
    char num[20], tipo[20];

    while (scanf("%d", &n) && n) {
        memset(qt, 0, sizeof qt);

        rep(i, 0, n) {
            scanf("%s %s", num, tipo);
            qt[mat[num[0]][tipo[0]]]++;
        }

        ans = 0;

        for (int i = 1; i < 8; i += 3) {
            while (qt[i] > 3 && qt[i + 1] > 3 && qt[i + 2] > 3) {
                qt[i] -= 3;
                qt[i + 1] -= 3;
                qt[i + 2] -= 3;
                ans += 3;
            }
        }

        for (int i = 1; i <= 9; i++) {
            while (qt[i] > 3) {
                qt[i] -= 3;
                ans++;
            }
        }

        solve(ans);

        printf("%lld\n", ans);
    }
    return 0;
}
