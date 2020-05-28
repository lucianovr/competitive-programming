#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i(a); i < (b); i++)

#define all(c) c.begin(), c.end()
#define UNIQUE(c)                                                                                                      \
    {                                                                                                                  \
        sort(all(c));                                                                                                  \
        (c).resize(unique(all(c)) - c.begin());                                                                        \
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

#define isONE(mask, bit) ((mask & (1<<bit))>0
#define isZERO(mask, bit) ((mask & (1<<bit))==0
#define setBIT(mask, bit) (mask | (1 << bit))
#define clearBIT(mask, bit) (mask & ~(1 << bit))
#define toogleBIT(mask, bit) (mask ^ (1 << bit))
#define LSOne(mask) (mask & (-mask))

typedef pair<int, int> ii;
typedef long long ll;

const int INF = 0x3f3f3f3f;
const double EPS = 1e-11;

// compara doubles
inline int cmp(double x, double y = 0, double tol = EPS) { return ((x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1); }

// compara inteiros
inline int cmp(int x, int y = 0) { return (x <= y) ? (x < y) ? -1 : 0 : 1; }

// direcoes  N  W  S  E  NW SW SE NE
int dx[] = {-1, 0, 1, 0, -1, 1, 1, -1};
int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

// knight moves
int dkx[] = {-2, -2, -1, 1, 2, 2, 1, -1};
int dky[] = {1, -1, -2, -2, -1, 1, 2, 2};

struct Triple {
    ll d, x, y;
    Triple(ll q = 0, ll w = 0, ll e = 0) : d(q), x(w), y(e) {}
};

Triple egcd(ll a, ll b) {
    if (!b)
        return Triple(a, 1, 0);

    Triple q = egcd(b, a % b);
    return Triple(q.d, q.y, q.x - a / b * q.y);
}
ll invMod(ll a, ll n) {
    Triple t = egcd(a, n);

    if (t.d > 1)
        return 0;

    ll r = t.x % n;

    return (r < 0 ? r + n : r);
}

int n;
ll a[3], p[3];

ll crt() {
    ll M = 1, x = 0;

    for (int i = 0; i < n; ++i)
        M *= p[i];

    for (int i = 0; i < n; ++i)
        x += a[i] * invMod(M / p[i], p[i]) * (M / p[i]);

    ll ret = (((x % M) + M) % M);
    if (ret == 0)
        return M;
    return ret;
}

int main() {
    int tt = 1;
    while (scanf("%lld %lld", &a[0], &p[0]) > 0) {
        scanf("%lld %lld", &a[1], &p[1]);
        scanf("%lld %ld", &a[2], &p[2]);

        n = 3;
        ll x = crt();

        printf("Caso #%d: %lld laranja(s)\n", tt++, x);
    }
    return 0;
}
