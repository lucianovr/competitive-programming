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

int main() {

    ll A, B, ans;
    string s;

    while (scanf("%lld %lld", &A, &B) == 2) {
        cin >> s;
        ll Bs = 0, Ws = 0;
        rep(i, 0, s.size()) if (s[i] == 'B') Bs++;

        rep(i, 0, Bs) if (s[i] == 'W') Ws++;

        ans = Ws * A;
        ll bidx = Bs;
        for (ll i = Bs - 1; i >= 0; i--) {
            if (s[i] == 'W') {
                ll temp = ans;
                temp -= A;
                while (s[bidx] == 'W')
                    bidx++;
                temp += (A - B) * (bidx - i);
                if (temp > ans)
                    break;
                else {
                    ans = temp;
                    bidx++;
                }
            }
        }

        printf("%lld\n", ans);
    }
    return 0;
}
