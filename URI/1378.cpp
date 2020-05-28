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

vector<pair<long long, long long>> p;
vector<pair<long long, int>> v[1010];

int main() {
    int N, ans;
    long long x, y, dij, D, A, B;

    while (scanf("%d", &N) && N) {

        ans = 0;
        p.clear();
        rep(i, 0, N) {
            v[i].clear();
            scanf("%lld %lld", &x, &y);
            p.pb(mp(x, y));
        }

        rep(i, 0, N) {
            rep(j, 0, N) {
                dij = (p[i].fst - p[j].fst) * (p[i].fst - p[j].fst) + (p[i].snd - p[j].snd) * (p[i].snd - p[j].snd);
                v[i].pb(mp(dij, j));
            }
            sort(v[i].begin(), v[i].end());
        }
        /*
                        rep(i,0,N){
                                cout << "i = " << i << "\n";
                                rep(ii,0,N){
                                        cout << "(" << v[i][ii].fst << ", " << v[i][ii].snd << ")  ";
                                } cout << "\n";
                        }
        */

        //		cout << "\n\n";

        rep(i, 0, N) {
            //			cout << "i = " << i << "\n";
            rep(ii, 1, N) {
                D = v[i][ii].fst;
                int j = v[i][ii].snd;
                //					cout << "D = " << D << "   j = " << j << "\n";
                A = lower_bound(v[j].begin(), v[j].end(), mp(D, -INF)) - v[j].begin();
                B = upper_bound(v[j].begin(), v[j].end(), mp(D, INF)) - v[j].begin();
                //					cout << A << " " << B << "\n";

                ans += (B - A - 1);
            }
            //			cout << "\n\n";
        }
        printf("%d\n", ans / 2);
    }
    return 0;
}