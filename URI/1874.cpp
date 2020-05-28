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

    int H, P, F;
    int i, j, row, col, x;

    while (scanf("%d %d %d", &H, &P, &F) == 3) {
        if (H == 0 && P == 0 && F == 0) {
            break;
        }

        vector<int> m[P + 1];

        for (i = 0; i < H; i++) {
            for (j = 0; j < P; j++) {
                scanf("%d", &x);
                if (x) {
                    m[j].pb(1);
                }
            }
        }
        vector<int> v(F);
        for (i = 0; i < F; i++)
            scanf("%d", &v[i]);

        col = P - 1;
        i = 0;
        while (col >= 0) {
            if (m[col].size() != H) {
                if (i != F) {
                    m[col].pb(v[i++]);
                } else
                    break;
            } else
                col--;
        }

        for (col = 0; col < P; col++) {
            while (m[col].size() != H)
                m[col].pb(0);
        }

        for (row = H - 1; row >= 0; row--) {
            for (col = 0; col < P; col++) {
                if (col)
                    printf(" ");
                printf("%d", m[col][row]);
            }
            printf("\n");
        }
    }

    return 0;
}
