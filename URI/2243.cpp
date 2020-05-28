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

#define NN 50000 + 5
int h[NN], e[NN], d[NN], n;

int main() {
    int ans;
    while (cin >> n) {
        rep(i, 0, n) { scanf("%d", &h[i]); }

        e[0] = 1;
        rep(i, 1, n) e[i] = min(e[i - 1] + 1, h[i]);

        d[n - 1] = 1;
        for (int i = n - 2; i >= 0; i--)
            d[i] = min(h[i], d[i + 1] + 1);

        ans = 1;
        for (int i = 0; i < n; i++)
            ans = max(ans, min(e[i], d[i]));
        printf("%d\n", ans);
    }
    return 0;
}
