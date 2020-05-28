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

bool dp[100001];
int v[1010];

int main() {
    int M, N;
    while (scanf("%d %d", &M, &N) > 0) {
        if (M == 0 && N == 0)
            break;
        rep(i, 0, N) scanf("%d", &v[i]);
        sort(v, v + N);

        rep(i, 0, M + 1) dp[i] = false;
        dp[0] = true;

        rep(i, 0, N) {
            for (int j = M - v[i]; j >= 0; j--)
                if (dp[j])
                    dp[j + v[i]] = true;
            if (dp[M])
                break;
        }
        dp[M] ? printf("sim\n") : printf("nao\n");
    }
    return 0;
}
