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

vector<ll> V;

bool bate_palma(ll x) {
    if (x % 7 == 0)
        return true;
    while (x) {
        if (x % 10 == 7)
            return true;
        x /= 10;
    }
    return false;
}

int main() {

    int n, m, k;
    while (true) {
        n = readInt();
        m = readInt();
        k = readInt();
        if (n == 0 && m == 0 && k == 0)
            break;

        V.clear();
        int vsize = 0;
        bool direita = true;
        ll cont = m;

        int De, Ed;
        if (m == 1 || m == n) {
            De = Ed = 2 * n - 2;
        } else {
            De = 2 * (n - m);
            Ed = 2 * (m - 1);
        }

        while (vsize != k) {
            if (direita) {
                if (bate_palma(cont)) {
                    V.pb(cont);
                    vsize++;
                }
                cont += De;
            } else {
                if (bate_palma(cont)) {
                    V.pb(cont);
                    vsize++;
                }
                cont += Ed;
            }
            direita = !direita;
        }

        printf("%lld\n", V.back());
    }
    return 0;
}