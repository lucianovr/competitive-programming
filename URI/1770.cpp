#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define rep(i, a, b) for (int i(a); i < (b); i++)
#define debug(x) cout << #x << " = " << x << "\n";

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int n, k, ans, t[11000], vis[11000], seq[11000], x, cont;

int main() {

    while (cin >> n >> k) {
        rep(i, 1, n + 1) cin >> t[i];
        for (int i = 0; i <= n; i++)
            vis[i] = 1;
        for (int i = 0; i < k; i++)
            cin >> seq[i];
        ans = cont = 0;
        for (int i = 0; i < k; i++) {
            cont += vis[seq[i]];
            vis[seq[i]] = 0;
            ans += t[seq[i]];
            if (cont == n)
                break;
        }
        if (cont == n)
            cout << ans << "\n";
        else
            cout << -1 << "\n";
    }
    return 0;
}
