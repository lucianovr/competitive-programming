#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i(a); i < (b); i++)

#define all(c) c.begin(), c.end()
#define SORT(c) sort(all(c))
#define UNIQUE(c)                                                                                                      \
    {                                                                                                                  \
        SORT(c);                                                                                                       \
        (c).resize(unique(all(c)) - c.begin());                                                                        \
    }
#define pb push_back
#define sz(c) ((int)(c.size()))
#define fst first
#define snd second
#define clr(x) memset(x, 0, sizeof x)
#define nulo(x) memset(x, -1, sizeof x)
#define debug(x) cout << #x << " = " << x << "\n";
#define debug2(x, y) cout << #x << " = " << x << "  " << #y << " = " << y << "\n";
#define debugV(v)                                                                                                      \
    {                                                                                                                  \
        cout << #v << "[] = ";                                                                                         \
        rep(i, 0, sz(v)) cout << v[i] << " ";                                                                          \
        cout << "\n";                                                                                                  \
    }

typedef pair<int, int> ii;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef map<string, int> msi;
typedef map<string, string> mss;

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
typedef long long ll;

vector<ll> v, m[25];
ll sum[25], ini, fim, mod = 1300031;
int n;

void func(ll mask) {
    ll mmc = 1;
    int b = 0;
    for (int i = 0; i < n; ++i) {
        if (mask & (1 << i)) {
            mmc = mmc / (__gcd(mmc, v[i])) * v[i];
            ++b;
        }
    }
    m[b].push_back(mmc);
}

/*
    r = 3
        5 20
        
        
*/

ll f(ll r) {
    ll ao, an, n;
    /* calculando limite inferior */
    n = (ini - 1) / r;
    ao = r + n * r;

    /* calculando limit superior */
    an = (fim / r) * r;

    if (ao > an)
        return 0;

    n = (an - ao) / r + 1;
    ll soma = (ao + an) * n / 2;

    return soma;
}

void soma(int b) {
    sum[b] = 0;
    rep(i, 0, m[b].size()) { sum[b] = (sum[b] + f(m[b][i])) % mod; }
}

void solve(int i, ll mmc, int b) {
    if (i == n) {
        if (b) {
            m[b].pb(mmc);
        }
        // process
        return;
    }

    // take it
    solve(i + 1, mmc / __gcd(mmc, v[i]) * v[i], b + 1);
    solve(i + 1, mmc, b);
    // no take it
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%lld %lld %d", &ini, &fim, &n);
        v.resize(n);
        rep(i, 0, n) scanf("%d", &v[i]);

        rep(i, 0, 25) {
            m[i].clear();
            sum[i] = 0;
        }

        /*
        for (ll i = 1; i < (1<<n); i++){
                func(i);
        }
        */
        solve(0, 1, 0); // versao iterativa

        for (int i = 1; i <= n; i++) {
            soma(i);
        }

        ll ans = 0;
        for (int i = 1; i <= n; i++) {
            if (i & 1)
                ans += sum[i];
            else
                ans -= sum[i];
        }
        ans = (ans % mod + mod) % mod;
        printf("%lld\n", ans);
    }

    return 0;
}
