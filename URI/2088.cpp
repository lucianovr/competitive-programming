#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i(a); i < (b); i++)

#define all(c) c.begin(), c.end()
#define SORT(c) sort(all(c))
#define UNIQUE(c)                                                                                                      \
    {                                                                                                                  \
        SORT(c);                                                                                                       \
        (c).resize(unique(all(c)) - c.begin());                                                                        \
    }
#define pb push_back
#define sz(c) ((int)(c.size()))
#define fst first
#define snd second
#define clr(x) memset(x, 0, sizeof x)
#define nulo(x) memset(x, -1, sizeof x)
#define debug(x) cout << #x << " = " << x << "\n";
#define debug2(x, y) cout << #x << " = " << x << "  " << #y << " = " << y << "\n";
#define debugV(v)                                                                                                      \
    {                                                                                                                  \
        cout << #v << "[] = ";                                                                                         \
        rep(i, 0, sz(v)) cout << v[i] << " ";                                                                          \
        cout << "\n";                                                                                                  \
    }

typedef pair<int, int> ii;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef map<string, int> msi;
typedef map<string, string> mss;

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

int N;
double X[16], Y[16];
double dp[1 << 16 + 1][17];
double INF = 1000000.0;
double sol(int mask, int v) {
    if (v == 0 && mask) {
        if (mask == ((1 << N) - 1))
            return 0;
        return INF;
    }

    double &ans = dp[mask][v];
    if (ans > -0.5)
        return ans;

    ans = INF;
    rep(i, 0, N) {
        if (!(mask & (1 << i)) && v != i)
            ans = min(ans, sol(mask | (1 << i), i) + hypot(X[v] - X[i], Y[v] - Y[i]));
    }
    return ans;
}
int main() {
    while (scanf("%d", &N) && N) {
        N++;
        rep(i, 0, N) scanf("%lf %lf", &X[i], &Y[i]);
        rep(i, 0, 1 << N) rep(j, 0, N) dp[i][j] = -1.0;

        printf("%.2lf\n", sol(0, 0));
    }

    return 0;
}
