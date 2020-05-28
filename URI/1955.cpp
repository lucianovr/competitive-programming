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

int cores[1010];
int G[1001][1001];
int N;

bool dfs(int v, int cor) {
    if (cores[v] == cor)
        return true;
    if (cores[v] == -1)
        cores[v] = cor;
    if (cores[v] != cor)
        return false;

    for (int u = 0; u < N; u++) {
        if (G[v][u] == 0) {
            if (!dfs(u, 1 - cores[v]))
                return false;
        }
    }
    return true;
}

int main() {
    while (cin >> N) {
        rep(i, 0, N) rep(j, 0, N) scanf(" %d", &G[i][j]);
        memset(cores, -1, sizeof(int) * N);
        printf("%s\n", dfs(0, 0) ? "Bazinga!" : "Fail!");
    }
    return 0;
}
