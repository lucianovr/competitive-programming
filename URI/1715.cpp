#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define debug(x) cout << #x << " = " << x << "\n";
#define all(v) v.begin(), v.end()
#define pb push_back

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int main() {

    int N, M, x;
    int v, ans;
    while (cin >> N >> M) {
        ans = 0;
        rep(i, 0, N) {
            v = 1;
            rep(j, 0, M) {
                cin >> x;
                v &= (x > 0);
            }
            if (v)
                ans++;
        }

        cout << ans << "\n";
    }

    return 0;
}
