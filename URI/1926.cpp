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

int b[1000005], p[1000005];

void crivo(ll limite = 1000003) {
    memset(b, 0, sizeof b);
    memset(p, 0, sizeof p);

    b[0] = b[1] = 1;

    for (ll i = 2; i <= limite; i++)
        if (b[i] == 0)
            for (ll j = i * i; j <= limite; j += i)
                b[j] = 1;

    for (ll i = 2; i <= limite - 3; i++) {
        if (b[i] == 0 && b[i - 2] == 0)
            p[i] = p[i - 2] = 1;
        if (b[i] == 0 && b[i + 2] == 0)
            p[i] = p[i + 2] = 1;
    }

    for (ll i = 2; i <= limite; i++)
        p[i] = p[i] + p[i - 1];
}

int main() {

    int t, a, b;
    scanf("%d", &t);

    crivo();
    while (t--) {
        scanf("%d %d", &a, &b);
        if (a > b)
            swap(a, b);
        if (a == 1)
            a = 2;
        printf("%d\n", p[b] - p[a - 1]);
    }

    return 0;
}
