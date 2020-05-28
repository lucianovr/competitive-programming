#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define rep(i, a, b) for (int i(a); i < (b); i++)
#define debug(x) cout << #x << " = " << x << "\n";

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int pd[1010][1010], v[1010];

int solve(int i, int j) {
    if (i >= j)
        return (i == j);
    if (pd[i][j] != -1)
        return pd[i][j];

    if (v[i] == v[j])
        return pd[i][j] = solve(i + 1, j - 1) + 1;
    else
        return pd[i][j] = min(solve(i + 1, j), solve(i, j - 1)) + 1;
}
int main() {
    int t, n, caso = 1;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        rep(i, 0, n) { scanf("%d", &v[i]); }
        memset(pd, -1, sizeof pd);
        printf("Caso #%d: %d\n", caso++, solve(0, n - 1));
    }
    return 0;
}
