#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(c) (c).begin(), (c).end()
#define F first
#define S second
#define debug(x) cout << __LINE__ << ": " << #x << " = " << x << endl;
#define debug2(x, y) #x << " = " << x << "  " << #y << " = " << y << endl;
#define pb push_back
#define mk make_pair

const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;
typedef long long ll;
typedef pair<int, int> ii;

vector<ll> divisores(ll N) {
    ll div, k;
    vector<ll> divisor;
    divisor.clear();
    for (div = 1; div * div <= N; div++) {
        if (N % div == 0) {
            divisor.pb(div);
            k = N / div;
            if (k != div)
                divisor.pb(k);
        }
    }
    sort(divisor.begin(), divisor.end());
    return divisor;
}

int main() {

    ll A, B, C, D;
    while (cin >> A >> B >> C >> D) {
        vector<ll> div = divisores(C);
        ll ans = -1;
        rep(i, 0, div.size()) {
            ll d = div[i];
            if (d % A == 0 && d % B != 0 && D % d != 0) {
                ans = d;
                break;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
