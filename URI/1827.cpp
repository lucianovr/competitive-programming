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

int main() {
    int n;
    int m[110][110];

    while (cin >> n) {
        memset(m, 0, sizeof m);

        rep(i, 0, n) {
            m[i][i] = 2;
            m[i][n - i - 1] = 3;
        }

        int inicio = n / 3;
        int fim = n - inicio;
        rep(i, inicio, fim) rep(j, inicio, fim) m[i][j] = 1;

        m[n / 2][n / 2] = 4;

        rep(i, 0, n) {
            rep(j, 0, n) { cout << m[i][j]; }
            cout << "\n";
        }
        cout << "\n";
    }

    return 0;
}
