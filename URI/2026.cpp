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

int pd[110][1100];
int enfeite[110];
int peso[110];
int N;

int S(int i, int W) {
    if (i == N || W == 0)
        return 0;
    if (pd[i][W] != -1)
        return pd[i][W];

    int ans = S(i + 1, W);
    if (W >= peso[i])
        ans = max(ans, S(i + 1, W - peso[i]) + enfeite[i]);
    return pd[i][W] = ans;
}

int main() {

    int t, W;
    cin >> t;
    rep(tt, 0, t) {
        cin >> N;
        cin >> W;
        rep(i, 0, N) { cin >> enfeite[i] >> peso[i]; }
        memset(pd, -1, sizeof pd);
        int ans = S(0, W);
        printf("Galho %d:\n", tt + 1);
        printf("Numero total de enfeites: %d\n", ans);
        printf("\n");
    }

    return 0;
}
