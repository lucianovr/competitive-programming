#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i(a); i < (b); i++)

#define all(c) c.begin(), c.end()
#define UNIQUE(c)                                                                                                      \
    { sort(ALL(c); (c).resize( unique(ALL(c))-c.begin() );                                               \
    }
#define pb push_back
#define D(x)                                                                                                           \
    if (1)                                                                                                             \
        cout << __LINE__ << " " << #x " = " << (x) << endl;
#define DVEC(v, n)                                                                                                     \
    {                                                                                                                  \
        cout << #v << "[] ={ ";                                                                                        \
        rep(i, 0, n) cout << v[i] << " ";                                                                              \
        cout << "}\n";                                                                                                 \
    }
#define mp make_pair
#define fst first
#define snd second

typedef pair<int, int> ii;
typedef long long ll;

typedef vector<int> vi;
typedef vector<ii> vii;

const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;

// bezout
struct triple {
    int d, x, y;
    triple(int q, int w, int e) : d(q), x(w), y(e) {}
};

triple egcd(int a, int b) {
    if (b == 0)
        return triple(a, 1, 0);
    triple q = egcd(b, a % b);
    return triple(q.d, q.y, q.x - a / b * q.y);
}

ll invMod(ll a, ll n) {
    triple t = egcd(a, n);
    if (t.d > 1)
        return 0;
    ll r = t.x % n;
    return (r + n) % n;
}

// fim

// primos
void factorize(ll n, vector<ll> &v) {
    ll sq = ll(sqrt((double)n));
    for (ll i = 2; i <= sq; ++i) {
        if (n % i == 0) {
            v.pb(i);
            n /= i--;
            sq = ll(sqrt((double)n));
        }
    }
    if (n > 1)
        v.pb(n);
}

ll phi(ll n) {
    vector<ll> p;
    factorize(n, p);
    rep(i, 0, p.size()) {
        if (i && p[i] == p[i - 1])
            continue;
        n /= p[i];
        n *= p[i] - 1;
    }
    return n;
}

// fim

// fastpow

ll fast_pow(ll a, ll p, ll mod) {
    if (p == 0)
        return 1;
    if (p == 1)
        return a % mod;

    ll ret = fast_pow(a, p / 2, mod);
    ret = (ret * ret) % mod;
    if (p % 2 == 1)
        ret = (ret * (a % mod)) % mod;

    return ret;
}

// fim

int main() {
    ll n, e, c;
    ll m;
    ll d;
    ll totN;

    while (cin >> n >> e >> c) {
        totN = phi(n);
        d = invMod(e, totN);
        m = fast_pow(c, d, n);

        printf("%lld\n", m);
    }

    return 0;
}
