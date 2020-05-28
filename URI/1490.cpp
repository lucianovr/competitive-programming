#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i(a); i < (b); i++)
#define debug(x) cout << #x << " = " << x << "\n";

#define ALL(c) c.begin(), c.end()
#define SORT(c) sort(ALL(c))
#define UNIQUE(c)                                                                                                      \
    {                                                                                                                  \
        SORT(c);                                                                                                       \
        (c).resize(unique(ALL(c)) - c.begin());                                                                        \
    }
#define pb push_back
#define sz size()
#define D(x)                                                                                                           \
    if (1)                                                                                                             \
        cout << __LINE__ << " " << #x " = " << (x) << endl;
#define D2(x, y)                                                                                                       \
    if (1)                                                                                                             \
        cout << __LINE__ << " " << #x " = " << (x) << ", " << #y " = " << (y) << endl;

typedef pair<int, int> ii;
typedef vector<int> VI;
typedef vector<ii> VII;
typedef long long LL;

#define WHITE 0
#define GRAY 1
const int NMAX = 100 * 100 + 10;
int N, M;              // sizes of the S and T sets
vector<int> adj[NMAX]; // adj[u][i]=v #> u in (0...n#1); v in (0..m#1)
int color[NMAX];
vector<int> path; // path contains only right side vertices
int match[NMAX];  //#1 or the vertex in S {0..n#1} matched

int aug(int u) {
    if (color[u] == WHITE) {
        color[u] = GRAY;
        rep(i, 0, adj[u].size()) {
            int v = adj[u][i];
            int w = match[v];
            path.push_back(v);
            if (w == -1)
                return 1;
            else {
                if (aug(w))
                    return 1;
                else
                    path.pop_back();
            }
        }
    }
    return 0;
}

int matching() {
    int u, v, w, flow = 0;
    rep(i, 0, M) match[i] = -1;
    rep(i, 0, N) {
        // Solve matching
        rep(j, 0, N) color[j] = WHITE;
        path.clear();
        flow += aug(i);
        // Update path
        u = i;
        rep(j, 0, path.size()) {
            w = path[j];
            v = match[w];
            match[w] = u;
            u = v;
        }
    }
    return flow;
}

int main() {
    int t;
    int grid[110][110], hor[110][110], ver[110][110];

    char in;
    while (scanf("%d", &t) == 1) {
        rep(i, 0, t) rep(j, 0, t) {
            scanf(" %c", &in);
            grid[i][j] = (in == '.' ? 1 : 0);
        }
        memset(hor, 0, sizeof hor);
        memset(ver, 0, sizeof ver);

        int v = -1;
        for (int i = 0; i < t; i++) {
            for (int j = 0; j < t; j++) {
                if (grid[i][j]) {
                    if (j == 0 || grid[i][j - 1] == 0)
                        ++v;
                    hor[i][j] = v;
                }
            }
        }
        N = v + 1;

        v = -1;
        for (int j = 0; j < t; j++) {
            for (int i = 0; i < t; i++) {
                if (grid[i][j]) {
                    if (i == 0 || grid[i - 1][j] == 0)
                        ++v;
                    ver[i][j] = v;
                }
            }
        }

        M = v + 1;

        for (int i = 0; i < t; i++)
            for (int j = 0; j < t; j++)
                if (grid[i][j])
                    adj[hor[i][j]].pb(ver[i][j]);

        cout << matching() << "\n";
        rep(i, 0, N) adj[i].clear();
    }
    return 0;
}
