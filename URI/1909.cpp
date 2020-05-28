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

ll N, T, V[110], has[100010];

ll lcm(ll a, ll b) { return a / __gcd(a, b) * b; }

int main() {

    while (scanf("%lld %lld", &N, &T) == 2) {
        if (N == 0 && T == 0)
            break;

        memset(has, 0, sizeof has);
        ll LCM;

        rep(i, 0, N) {
            scanf("%lld", &V[i]);
            if (i == 0)
                LCM = V[i];
            else
                LCM = lcm(V[i], LCM);
            has[V[i]] = 1;
        }

        int ok = 0;
        for (ll t = 2; t <= T; t++) {
            if (!has[t]) {
                ll tt = lcm(t, LCM);
                if (tt == T) {
                    ok = 1;
                    printf("%lld\n", t);
                    break;
                }
            }
        }

        if (!ok)
            printf("impossivel\n");
    }

    return 0;
}
