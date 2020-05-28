#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define rep(i, a, b) for (int i(a); i < (b); i++)
#define debug(x) cout << #x << " = " << x << "\n";

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef unsigned long long ll;

int main() {
    ll n, m, mod = 1000000000;
    while (cin >> n >> m) {
        ll ret = 1;
        while (m--) {
            ret *= n;
            n--;
            while (ret % 10 == 0)
                ret /= 10;
            ret = ret % mod;
        }
        cout << ret % 10 << "\n";
    }
    return 0;
}
