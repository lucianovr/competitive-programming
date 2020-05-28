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

double P[110][110];
double dp[110][110];
int s, d, N;

double S(int v, int t) {
    if (v == d)
        return 1.0;
    if (t == 0)
        return 0;

    if (dp[v][t] > -1.0)
        return dp[v][t];

    double prob = 0.0;
    for (int i = 0; i < N; i++)
        prob += P[v][i] * S(i, t - 1);

    return dp[v][t] = prob;
}

int main() {
    int t, caso = 1;
    while (scanf("%d", &N) && N) {
        scanf("%d %d %d", &s, &d, &t);
        s--;
        d--;

        rep(i, 0, N) rep(j, 0, N) scanf("%lf", &P[i][j]);

        rep(i, 0, 110) rep(j, 0, 110) dp[i][j] = -1.0;

        double ans = S(s, t);

        printf("Instancia %d\n", caso++);
        printf("%.6lf\n", 1 - ans);
        printf("\n");
    }
    return 0;
}
