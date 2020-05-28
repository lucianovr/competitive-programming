#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define rep(i, a, b) for (int i(a); i < (b); i++)
#define debug(x) cout << #x << " = " << x << "\n";

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int main() {
    int x[5], y[5];

    rep(i, 0, 5) cin >> x[i];
    rep(i, 0, 5) cin >> y[i];

    bool ok = true;
    rep(i, 0, 5) if (x[i] == y[i]) ok = false;

    cout << (ok ? "Y" : "N") << "\n";

    return 0;
}
