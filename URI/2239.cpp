#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(c) (c).begin(), (c).end()
#define F first
#define S second
#define debug(x) cout << __LINE__ << ": " << #x << " = " << x << endl;
#define pb push_back
#define mk make_pair

typedef unsigned long long ll;
ll INF;
ll MOD = 1000000007;
ll dp1[1 << 16 + 1];
ll dp2[1 << 16 + 1];
ll dp3[1 << 16 + 1];
ll fat[16];
ll sum[1 << 16 + 1];
ll sum2[1 << 16 + 1];
bool calc1[1 << 16 + 1];
bool calc2[1 << 16 + 1];
bool calc3[1 << 16 + 1];
char S[100][100];
int n, len[100];

inline int v(char c) {
    if (isdigit(c))
        return (c - '0');
    else
        return (c - 'a' + 10);
}

ll sol(ll mask) { // min
    if (__builtin_popcount(mask) == 16)
        return 0;
    ll ans = dp1[mask];

    if (calc1[mask])
        return ans;
    ans = INF;

    ll tot = sum[mask];

    for (ll i = 0; i < 16; i++) {
        if (mask & (1LL << i))
            continue;
        ans = min(ans, (tot + sol(mask | (1 << i))));
    }

    calc1[mask] = true;
    return dp1[mask] = ans;
}

ll sol2(ll mask) { // min
    if (__builtin_popcount(mask) == 16)
        return 0;
    ll ans = dp2[mask];

    if (calc2[mask])
        return ans;
    ans = 0;

    ll tot = sum[mask];

    for (ll i = 0; i < 16; i++) {
        if (mask & (1LL << i))
            continue;
        ans = max(ans, (tot + sol2(mask | (1 << i))));
    }

    calc2[mask] = true;
    return dp2[mask] = ans;
}

ll sol3(ll mask) { // sum
    if (__builtin_popcount(mask) == 16)
        return 0;
    ll ans = dp3[mask];

    if (calc3[mask])
        return ans;
    ans = 0;

    ll tot = sum2[mask];

    int qt = __builtin_popcount(mask);
    ans = (fat[16 - qt] * tot);
    if (ans > MOD)
        ans %= MOD;

    for (ll i = 0; i < 16; i++) {
        if (mask & (1LL << i))
            continue;
        ll ret = sol3(mask | (1 << i));
        ans += ret;
        if (ans > MOD)
            ans %= MOD;
    }
    calc3[mask] = true;
    return dp3[mask] = ans;
}

void precalSum() {
    ll word, word2, d;

    rep(mask, 1, (1 << 16)) {
        sum[mask] = sum2[mask] = 0;
        rep(k, 0, n) {
            word = word2 = 0;
            rep(i, 0, len[k]) {
                d = v(S[k][i]);
                if (mask & (1 << d))
                    continue;
                word = word * 16 + d;
                word2 = ((word2 * 16) % MOD + d) % MOD;
            }
            sum[mask] += word;
            sum2[mask] = (sum2[mask] + word2) % MOD;
        }
    }
}

int main() {
    ll MIN, MAX, TOT;
    INF = 0;
    INF--;
    fat[0] = 1;
    for (ll i = 1; i <= 16; i++)
        fat[i] = (fat[i - 1] * i) % MOD;

    while (scanf("%x", &n) != EOF) {
        MIN = INF;
        MAX = TOT = 0;
        rep(i, 0, n) {
            scanf("%s", S[i]);
            len[i] = strlen(S[i]);
        }
        precalSum();
        rep(i, 0, 16) MIN = min(MIN, sol(1 << i));
        rep(i, 0, 16) MAX = max(MAX, sol2(1 << i));
        rep(i, 0, 16) TOT = (TOT + sol3(1 << i)) % MOD;

        printf("%llx %llx %llx\n", MIN, MAX, TOT);
    }
    return 0;
}