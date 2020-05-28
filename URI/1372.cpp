#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define debug(x) cout << #x << " = " << x << "\n";
#define all(v) v.begin(), v.end()
#define pb push_back

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef unsigned long long ll;

ll pd[100010];
ll vet[100010], C[100010];
int N, M;

ll candy1(int j) {
    if (j >= N)
        return 0;
    if (pd[j] != -1)
        return pd[j];

    ll r1 = vet[j] + candy1(j + 2);
    ll r2 = candy1(j + 1);

    return pd[j] = max(r1, r2);
}

ll candy2(int i) {
    if (i >= M)
        return 0;
    if (pd[i] != -1)
        return pd[i];

    ll r1 = C[i] + candy2(i + 2);
    ll r2 = candy2(i + 1);

    return pd[i] = max(r1, r2);
}

int main() {
    while (scanf("%d %d", &M, &N) && N && M) {
        rep(i, 0, M) {
            rep(j, 0, N) {
                pd[j] = -1;
                scanf("%d", &vet[j]);
            }
            C[i] = candy1(0);
        }
        memset(pd, -1, sizeof pd);
        ll ans = candy2(0);
        printf("%lld\n", ans);
    }
    return 0;
}