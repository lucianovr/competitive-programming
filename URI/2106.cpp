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

const int INF = 0x3f3f3f3f;
int N;
int cost[20][20];

int dp[1 << 18 + 1][18];

int solve(int mask, int k) {
    if (mask == ((1 << N) - 1))
        return 0;
    int &ret = dp[mask][k];

    if (ret != -1)
        return ret;
    ret = INF;

    for (int i = 0; i < N; i++) {
        if (!(mask & (1 << i)))
            ret = min(ret, solve(mask | (1 << i), k + 1) + cost[i][k]);
    }
    return ret;
}

int main() {
    while (scanf("%d", &N) > 0 && N) {
        rep(i, 0, N) {
            rep(j, 0, N) { scanf("%d", &cost[i][j]); }
        }
        rep(i, 0, (1 << N)) rep(j, 0, N) dp[i][j] = -1;
        printf("%d\n", solve(0, 0));
    }
}
