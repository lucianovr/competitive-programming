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
#define D2(x, y) cout << #x " = " << x << "  " << #y " = " << y << endl;
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
const double EPS = 1e-11;

inline int cmp(double x, double y = 0, double tol = EPS) { return ((x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1); }

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

int readInt() {
    bool minus = false;
    int result = 0;
    char ch;

    ch = getchar();
    while (true) {
        if (ch == '-')
            break;
        if (ch >= '0' && ch <= '9')
            break;
        ch = getchar();
    }
    if (ch == '-')
        minus = true;
    else
        result = ch - '0';
    while (true) {
        ch = getchar();
        if (ch < '0' || ch > '9')
            break;
        result = result * 10 + (ch - '0');
    }
    if (minus)
        return -result;
    else
        return result;
}

ll mod = 100000007;

ll fermat(ll a, ll p) {
    if (p == 0)
        return 1LL;

    ll ret = fermat(a, p / 2);
    ret = (ret * ret) % mod;

    if (p & 1)
        ret = (ret * a) % mod;

    return ret;
}

int main() {

    long long f[10010];
    int freq[300];
    f[0] = 1;
    for (ll i = 1; i < 10010; i++) {
        f[i] = (i * f[i - 1]) % mod;
    }

    string s;
    while (cin >> s && s != "0") {
        memset(freq, 0, sizeof freq);
        rep(i, 0, s.size()) freq[s[i]]++;

        ll num = 1, den = 1;

        num = f[s.size()];
        for (char i = 'a'; i <= 'z'; i++)
            den = (den * f[freq[i]]) % mod;

        ll inv = fermat(den % mod, mod - 2);

        printf("%lld\n", (num * inv) % mod);
    }

    return 0;
}
