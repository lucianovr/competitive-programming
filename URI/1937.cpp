#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i(a); i < (b); i++)
#define all(c) (c).begin(), (c).end()
#define fst first
#define snd second
#define db(x) cerr << __LINE__ << ": " << #x << " = " << x << endl

#define pb push_back
#define mp make_pair

const int INF = 0x3f3f3f3f;
typedef long long ll;
typedef pair<int, int> ii;

int N, K;
ll pd[110][110];
ll comb[110][110];
ll MOD = 1e9 + 7;

ll S(int n, int m) {
    if (n == 0 && m > 0)
        return 0;
    if (m == 0)
        return 1;
    if (K * n < m)
        return 0;

    ll &ret = pd[n][m];
    if (ret != -1)
        return ret;
    ret = 0;
    for (int i = 0; i < min(m + 1, K); i++) {
        ret += comb[m][i] * S(n - 1, m - i);
        if (ret > MOD)
            ret %= MOD;
    }
    return ret;
}

int main() {

    for (int n = 0; n <= 100; n++)
        for (int k = 0; k <= n; k++) {
            if (k == 0 || n == k)
                comb[n][k] = 1;
            else
                comb[n][k] = (comb[n - 1][k - 1] + comb[n - 1][k]) % MOD;
        }

    while (scanf("%d %d", &N, &K) != EOF) {
        if (N == 1 && K == 1) {
            printf("1\n");
            continue;
        }
        for (int i = 0; i <= N; i++)
            for (int j = 0; j <= N; j++)
                pd[i][j] = -1;

        printf("%lld\n", S(N, N - 2));
    }
    return 0;
}
