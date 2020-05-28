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

ll vec[10010];

int main() {
    int t;
    scanf(" %d", &t);
    while (t--) {
        int n;
        scanf(" %d", &n);
        rep(i, 0, n) scanf(" %lld", &vec[i]);
        sort(vec, vec + n);

        ll X = 0;
        rep(i, 0, n) {
            if (vec[i] > X + 1)
                break;
            X = X + vec[i];
        }
        printf("%lld\n", X + 1);
    }
    return 0;
}
