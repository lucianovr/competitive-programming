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

int N, M, P, D;
ll B;

vector<pair<int, pair<ll, ll>>> E[110];

ll INF = 1e18;
ll dp[1100][1100];
int calc[1100][1100];

ll sol(int v, ll b) {
    if (v == D && b >= 0)
        return 0;
    if (calc[v][b] == 1)
        return dp[v][b];
    calc[v][b] = 1;

    ll ret = -INF;
    for (int i = 0; i < E[v].size(); i++) {
        int u = E[v][i].fst;
        ll f = E[v][i].snd.fst;
        ll s = E[v][i].snd.snd;

        if (s <= b)
            ret = max(ret, f + sol(u, b - s));
    }
    return dp[v][b] = ret;
}

int main() {
    int x, y;
    ll s, f;
    scanf("%d %d", &N, &M);
    scanf("%d %d", &P, &D);
    scanf("%lld", &B);
    while (M--) {
        scanf("%d %d %lld %lld", &x, &y, &f, &s);
        E[x].pb(make_pair(y, make_pair(f, s)));
        E[y].pb(make_pair(x, make_pair(f, s)));
    }

    for (int v = 1; v <= N; v++)
        for (ll b = 0; b <= B; b++)
            dp[v][b] = -1;

    ll ret = sol(P, B);
    if (ret <= 0)
        ret = -1;
    cout << ret << "\n";
    return 0;
}
