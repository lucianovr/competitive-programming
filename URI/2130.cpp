#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i(a); i < (b); i++)
#define all(c) c.begin(), c.end()
#define pb push_back
#define D(x)                                                                                                           \
    if (1)                                                                                                             \
        cout << __LINE__ << " " << #x " = " << (x) << endl;
#define D2(x, y) cout << #x " = " << x << "  " << #y " = " << y << endl;
#define mp make_pair
#define fst first
#define snd second

typedef pair<int, int> ii;
typedef long long ll;

typedef vector<int> vi;
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;

int inst = 1;
int mat[110][110];

int main() {
    int N, M, Q;
    int x, y, c, t;

    while (cin >> N >> M) {
        memset(mat, INF, sizeof mat);
        for (int i = 1; i <= N; i++)
            //			for (int t = 0; t <= N; t++)
            mat[i][i] = 0;
        while (M--) {
            cin >> x >> y >> c;
            mat[x][y] = min(mat[x][y], c);
            //			mat[y][x] = c;
        }

        vector<pair<pair<int, int>, int>> K[N + 1]; // consultas
        cin >> Q;
        for (int i = 0; i < Q; i++) {
            cin >> x >> y >> t;
            K[t].push_back(make_pair(ii(x, y), i));
        }
        int ans[Q];

        for (c = 0; c < K[0].size(); c++) {
            int query = K[0][c].second;
            x = K[0][c].first.first;
            y = K[0][c].first.second;
            ans[query] = mat[x][y];
        }
        for (int k = 1; k <= N; k++) {
            for (int i = 1; i <= N; i++)
                for (int j = 1; j <= N; j++)
                    mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
            for (c = 0; c < K[k].size(); c++) {
                int query = K[k][c].second;
                x = K[k][c].first.first;
                y = K[k][c].first.second;
                ans[query] = mat[x][y];
            }
        }
        cout << "Instancia " << inst++ << "\n";
        for (int i = 0; i < Q; i++) {
            if (ans[i] == INF)
                ans[i] = -1;
            cout << ans[i] << "\n";
        }
        cout << "\n";
    }
    return 0;
}