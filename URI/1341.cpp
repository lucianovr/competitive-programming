#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define rep(i, n) for (int i = 0; i < (n); i = i + 1)
#define tr(it, S) for (typeof(S.begin()) it = S.begin(); it != S.end(); it++)
#define all(S) (S).begin(), (S).end()
#define pb push_back
#define sz size()
string q[30];

int LCS(string X, int m, string Y, int n) {
    int i, j, k;
    char c[3][n + 1];
    for (i = 0; i <= 2; i++)
        c[i][0] = 0;
    for (j = 0; j <= n; j++)
        c[0][j] = 0;

    for (i = 1; i <= m; i++) {
        for (j = 1; j <= n; j++) {
            if (X[i - 1] == Y[j - 1])
                c[1][j] = c[0][j - 1] + 1;
            else if (c[0][j] >= c[1][j - 1])
                c[1][j] = c[0][j];
            else
                c[1][j] = c[1][j - 1];
        }
        if (i != m) {
            for (k = 0; k <= n; k++)
                c[0][k] = c[1][k];
        }
    }
    return c[1][n];
}

string getstring(int x, int y, string c, int n) {
    string ret;
    ret += q[x][y];
    if (!n)
        return ret;
    rep(i, n) {
        if (c[i] == 'N')
            x--;
        else if (c[i] == 'S')
            x++;
        else if (c[i] == 'E')
            y++;
        else if (c[i] == 'W')
            y--;
        ret += q[x][y];
    }
    return ret;
}

int main() {

    string c, sa, sb;
    int T, H, W, n, x, y, asz, bsz, ret;
    cin >> T;
    rep(t, T) {
        cin >> H >> W;
        rep(i, H) rep(j, W) cin >> q[i][j];

        cin >> n >> x >> y;
        if (n)
            cin >> c;
        asz = n + 1;
        sa = getstring(x - 1, y - 1, c, n);

        cin >> n >> x >> y;
        if (n)
            cin >> c;
        bsz = n + 1;
        sb = getstring(x - 1, y - 1, c, n);

        ret = LCS(sa, asz, sb, bsz);
        cout << "Case " << t + 1 << ": " << asz - ret << " " << bsz - ret << endl;
    }
    return 0;
}
