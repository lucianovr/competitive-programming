#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i(a); i < (b); i++)
#define all(c) (c).begin(), (c).end()
#define fst first
#define snd second
#define db(x) cerr << __LINE__ << ": " << #x << " = " << x << endl

#define pb push_back
#define mp make_pair

const int INF = 0x3f3f3f3f;
typedef long long ll;
typedef pair<int, int> ii;

ll S, B[250], V[250 * 2 + 10];
int inicio, b;
ll pd[250 * 2 + 10][250];

ll solve(int i, int k) {
    // cout << i << " " << k << "\n";

    if (k == b)
        return 0;
    if (i > S - 2 + inicio)
        return -INF;
    ll ret = pd[i][k];

    if (ret != -INF)
        return ret;

    return pd[i][k] = ret = max(solve(i + 1, k), solve(i + 2, k + 1) + (V[i] + V[i + 1]) * (-1) * B[k]);
}

int main() {
#ifndef ONLINE_JUDGE
    // freopen("_in.txt", "r", stdin);
    // freopen("_out.txt", "w", stdout);
#endif

    while (scanf("%d %d", &S, &b) > 0) {
        if (S == 0 && b == 0)
            break;

        rep(i, 0, S) scanf(" %lld", &V[i]);
        rep(i, S, 2 * S) V[i] = V[i - S];

        rep(i, 0, b) scanf(" %lld", &B[i]);

        ll ans = -INF;
        for (inicio = 0; inicio < S; inicio++) {
            rep(i, 0, 2 * S + 1) rep(j, 0, b + 1) pd[i][j] = -INF;
            ans = max(ans, solve(inicio, 0));
        }
        cout << ans << "\n";
    }
    return 0;
}
