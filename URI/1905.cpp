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

int main() {
    int t;
    int g[5][5];
    cin >> t;
    while (t--) {
        rep(i, 0, 5) rep(j, 0, 5) cin >> g[i][j];
        queue<ii> q;
        int vis[5][5];
        memset(vis, 0, sizeof vis);
        q.push(ii(4, 4));
        while (!q.empty()) {
            int x = q.front().fst;
            int y = q.front().snd;
            vis[x][y] = 1;
            q.pop();

            rep(i, 0, 4) {
                int a = x + dx[i];
                int b = y + dy[i];
                if (a >= 0 && a < 5 && b >= 0 && b < 5 && !vis[a][b] && g[a][b] == 0)
                    q.push(ii(a, b));
            }
        }

        vis[0][0] ? printf("COPS\n") : printf("ROBBERS\n");
    }
}
