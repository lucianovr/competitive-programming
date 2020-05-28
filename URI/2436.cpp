#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <string.h>
#include <string>
#include <utility>
#include <vector>
using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define rep(i, n) for (int i = 0; i < (n); i = i + 1)
#define tr(it, S) for (typeof(S.begin()) it = S.begin(); it != S.end(); it++)
#define all(S) (S).begin(), (S).end()
#define setar(S, x) memset(S, x, sizeof(S))
#define pb push_back
#define sz size()
#define contem(s, x) (s.find(x) != s.end())
#define MAX 1001
#define x first
#define y second
int r, c;
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};
int vis[MAX][MAX], m[MAX][MAX];

bool dentro(int a, int b) { return (a >= 0 && a < r && b >= 0 && b < c); }

ii dfs(int a, int b) {
    vis[a][b] = 1;
    int aa, bb;
    rep(k, 4) {
        aa = a + dx[k];
        bb = b + dy[k];
        if (dentro(aa, bb) && m[aa][bb] && !vis[aa][bb])
            return dfs(aa, bb);
    }
    return ii(a, b);
}

int main() {
    while (cin >> r >> c) {
        int a, b;
        cin >> a >> b;
        rep(i, r) rep(j, c) {
            vis[i][j] = 0;
            cin >> m[i][j];
        }
        ii ret = dfs(a - 1, b - 1);
        cout << ret.first + 1 << " " << ret.second + 1 << endl;
    }
    return 0;
}
