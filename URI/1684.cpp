#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define rep(i, a, b) for (int i(a); i < (b); i++)
#define debug(x) cout << #x << " = " << x << "\n";

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int main() {
    int t, n, m, a, b, cnt[10001];
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &n, &m);
        rep(i, 0, n) cnt[i] = 0;
        rep(i, 0, m) {
            scanf("%d %d", &a, &b);
            cnt[a]++;
            cnt[b]++;
        }
        bool ok = true;
        for (int i = 0; i < n && ok; i++) {
            if (cnt[i] % 2 != 0)
                ok = false;
        }

        if (!ok)
            printf("No\n");
        else
            printf("Yes\n");
    }
    return 0;
}
