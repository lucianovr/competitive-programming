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

ii E[1010];
int N;
int dp[1010][1010];

int S(int i, int j) {
    if (i == N + 1)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];

    int ans;

    ans = S(i + 1, j);
    if (E[i].fst >= E[j].snd)
        ans = max(ans, (E[i].snd - E[i].fst) + S(i + 1, i));
    return dp[i][j] = ans;
}

int main() {
    while (scanf("%d", &N) == 1) {
        E[0] = ii(0, 0);
        rep(i, 1, N + 1) { scanf("%d %d", &E[i].fst, &E[i].snd); }
        sort(E, E + N + 1);
        rep(i, 0, N + 2) rep(j, 0, N + 2) dp[i][j] = -1;

        printf("%d\n", S(1, 0));
    }
    return 0;
}
