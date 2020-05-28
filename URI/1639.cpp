#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define debug(x) cout << #x << " = " << x << "\n";
#define all(v) v.begin(), v.end()
#define clear(v) memset(v, 0, sizeof v)
#define initpd(v) memset(v, -1, sizeof v)
#define pb push_back

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int func(int seed) { return (((seed * seed) / 100) % 10000); }

int main() {

    int x0, cnt, vis[10000];
    while (scanf("%d", &x0) && x0) {
        cnt = 0;
        memset(vis, 0, sizeof vis);
        while (!vis[x0]) {
            cnt++;
            vis[x0] = 1;
            x0 = ((x0 * x0) / 100) % 10000;
        }

        printf("%d\n", cnt);
    }

    return 0;
}
