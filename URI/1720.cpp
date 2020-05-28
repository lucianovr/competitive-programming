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

int N, M;
ll pd[11 + 3][11 + 3][(1 << 11) + 1];

#define ZERO(m, b) (!(m & (1 << b)))
#define UM(m, b) (m & (1 << b))

#define left 0
#define down 1

#define bit(b) (1 << b)

ll S(int i, int j, int m) {
    if (i >= N)
        return S(0, j + 1, m);
    if (i == 0 && j == M)
        return m == (1 << N) - 1;

    ll &ret = pd[i][j][m];
    if (ret == -1) {
        ret = 0;
        // colocar nada
        if (UM(m, left))
            ret += S(i + 1, j, m >> 1);
        // try 0
        if (i + 1 < N)
            if (UM(m, left) && UM(m, down))
                ret += S(i + 2, j, (m >> 2) | bit(N - 1) | bit(N - 2));
        // try 1
        if (ZERO(m, left))
            ret += S(i + 1, j, (m >> 1) | bit(N - 1));
    }
    return ret;
}

int main() {
    while (scanf("%d %d", &N, &M) > 0) {
        if (N == 0 && M == 0)
            break;
        memset(pd, -1, sizeof pd);
        printf("%lld\n", S(0, 0, (1 << N) - 1));
    }
    return 0;
}
