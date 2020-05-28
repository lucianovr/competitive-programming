#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define rep(i, a, b) for (int i(a); i < (b); i++)
#define debug(x) cout << #x << " = " << x << "\n";

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

bool have3(unsigned long long u) {
    while (u) {
        if (u % 10 == 3)
            return true;
        u /= 10;
    }
    return false;
}

int main() {
    vector<unsigned long long int> fib, v;

    fib.pb(1);
    fib.pb(1);
    int cnt = 0, sz = 2;

    while (cnt < 61) {
        fib.pb(fib[sz - 2] + fib[sz - 1]);
        sz++;

        if (fib[sz - 1] % 3 == 0 || have3(fib[sz - 1])) {
            v.pb(fib.back());
            cnt++;
        }
    }
    int n;
    while (cin >> n) {
        cout << v[n - 1] << "\n";
    }

    return 0;
}
