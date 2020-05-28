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
#define D2(x, y) cout << #x " = " << x << "  " << #y " = " << y << endl;
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
const double EPS = 1e-11;

inline int cmp(double x, double y = 0, double tol = EPS) { return ((x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1); }

char g[100][100];
bool vis[100][100];
int cols, rows;

bool dentro(int x, int y) { return x >= 0 && y >= 0 && x < rows && y < cols; }

int indice(char c) {
    if (c == '>')
        return 0;
    if (c == 'v')
        return 1;
    if (c == '<')
        return 2;
    if (c == '^')
        return 3;
    return -1;
}

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int main() {

    while (cin >> cols >> rows) {
        memset(vis, false, sizeof vis);
        rep(i, 0, rows) rep(j, 0, cols) scanf(" %c", &g[i][j]);
        int x = 0, y = 0;
        int dir = -1;
        while (1) {
            vis[x][y] = true;

            if (g[x][y] == '.') {
                if (dir == -1) {
                    cout << "!\n";
                    break;
                }
            } else
                dir = indice(g[x][y]);

            x = x + dx[dir];
            y = y + dy[dir];
            if (!dentro(x, y) || vis[x][y]) {
                cout << "!\n";
                break;
            }
            if (g[x][y] == '*') {
                cout << "*\n";
                break;
            }
        }
    }

    return 0;
}
