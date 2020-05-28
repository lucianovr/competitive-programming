#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i(a); i < (b); i++)

#define ALL(c) c.begin(), c.end()
#define UNIQUE(c)                                                                                                      \
    { sort(ALL(c); (c).resize( unique(ALL(c))-c.begin() );                                               \
    }
#define pb push_back
#define sz size()
#define D(x)                                                                                                           \
    if (1)                                                                                                             \
        cout << __LINE__ << " " << #x " = " << (x) << endl;

typedef pair<int, int> ii;
typedef long long ll;

const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;

int tam[1010][1010];
int comp[1010][1010];
bool vis[1010][1010];
char m[1010][1010];
int R, C, cont;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, 1, -1};

inline bool dentro(int x, int y) { return x >= 0 && x < R && y >= 0 && y < C; }

int dfs(int x, int y) {
    vis[x][y] = true;
    cont++;
    rep(i, 0, 4) {
        int a = x + dx[i];
        int b = y + dy[i];
        if (dentro(a, b) && m[a][b] == 'n' && !vis[a][b])
            dfs(a, b);
    }
}

void propaga(int x, int y, int t, int id) {
    tam[x][y] = t;
    comp[x][y] = id;
    rep(i, 0, 4) {
        int a = x + dx[i];
        int b = y + dy[i];
        if (dentro(a, b) && m[a][b] == 'n' && vis[a][b] && tam[a][b] == 0)
            propaga(a, b, t, id);
    }
}

int main() {
    int id;
    while (cin >> R >> C) {
        rep(i, 0, R) rep(j, 0, C) {
            scanf(" %c", &m[i][j]);
            vis[i][j] = false;
            tam[i][j] = 0;
        }
        id = 1;
        rep(i, 0, R) {
            rep(j, 0, C) {
                if (m[i][j] == 'n' && !vis[i][j]) {
                    cont = 0;
                    dfs(i, j);
                    propaga(i, j, cont, id);
                    id++;
                }
                // cout << tam[i][j] << " ";
            } // cout << "\n";
        }
        int ans = -1, X, Y;
        rep(i, 0, R) rep(j, 0, C) if (m[i][j] == '*') {
            cont = 0;
            set<int> st;
            rep(k, 0, 4) {
                int a = i + dx[k];
                int b = j + dy[k];
                if (dentro(a, b) && st.find(comp[a][b]) == st.end()) {
                    cont += tam[a][b];
                    st.insert(comp[a][b]);
                }
            }
            if (cont > ans)
                ans = cont, X = i, Y = j;
        }
        printf("%d,%d\n", X + 1, Y + 1);
    }
    return 0;
}
