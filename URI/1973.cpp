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

long long v[1000010];
int ataca[1000010];

int main() {

    int n;
    long long s = 0;

    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &v[i]);
        ataca[i] = 1;
        s += v[i];
    }

    int e = 1, new_e;
    int c = 0;
    int l = 0;
    while (e >= 1 && e <= n) {
        if (v[e] % 2 == 0)
            new_e = e - 1;
        else
            new_e = e + 1;

        if (v[e]) {
            l += ataca[e];
            ataca[e] = 0;
            c++;
            v[e]--;
        }
        e = new_e;
    }

    cout << l << " " << s - c << "\n";

    return 0;
}
