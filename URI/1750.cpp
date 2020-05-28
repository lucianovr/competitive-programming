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

int solve(int i, vector<int> &d) {
    int soma = 0;
    for (; i < d.size(); i += 2)
        soma += d[i];
    return soma;
}
int main() {
    int n, x;
    while (scanf("%d", &n) == 1) {
        vector<int> vec;
        rep(i, 0, n) {
            cin >> x;
            vec.pb(x);
        }
        sort(vec.begin(), vec.end());
        vec.pb(vec[0]);
        vector<int> d(n);
        for (int i = 0; i < n; i++)
            d[i] = min(abs(vec[i] - vec[i + 1]), 24 - abs(vec[i] - vec[i + 1]));

        int ans = min(solve(0, d), solve(1, d));
        cout << ans << "\n";
    }
    return 0;
}
