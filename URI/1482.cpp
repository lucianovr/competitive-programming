#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <ctype.h>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <stdio.h>
#include <utility>
#include <vector>

#define INF 0x3F3F3F3F
#define rep(i, a, b) for (int i = int(a); i < int(b); i++)
#define TRvii(c, it) for (vii::iterator it = (c).begin(); it != (c).end(); it++)
#define tr(it, s) for (typeof(s.begin()) it = s.begin(); it != s.end(); it++)
#define pb push_back
#define clr(a) memset((a), 0, sizeof(a))
#define pi 3.1415926535897932384626433832795028841971
#define debug(x) cout << #x << " = " << x << endl;
#define all(S) (S).begin(), (S).end()
#define MAXV 1005
#define F first
#define S second

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int n, temp[22], m[22][22], resp, ans;

int pd[1 << 20];

int back(int i, int t, int vis, int cont) {

    if (pd[vis] != -1)
        return pd[vis];

    int ans = cont;

    rep(j, 0, n) if (!(vis & (1 << j)) && t + temp[j] + m[i][j] <= 420) ans =
        max(ans, back(j, t + temp[j] + m[i][j], (vis | (1 << j)), cont + 1));

    return pd[vis] = ans;
}

int main() {

    while (scanf("%d", &n) && n) {

        rep(i, 0, n) cin >> temp[i];

        rep(i, 0, n) rep(j, 0, n) cin >> m[i][j];

        resp = 0;

        rep(i, 0, n) {
            if (temp[i] <= 420) {
                rep(j, 0, (1 << 20) + 1) pd[j] = -1;
                resp = max(resp, back(i, temp[i], 1 << i, 1));
            }
            if (resp == n) {
                break;
            }
        }

        cout << resp << "\n";
    }

    return 0;
}