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
const double EPS = 1e-9;

#define MAXV 110
typedef int edge;
vector<edge> adj[MAXV];
int cor[MAXV];

void dfs(int u) {
    cor[u] = 1;
    rep(i, 0, adj[u].size()) {
        int v = adj[u][i];
        if (cor[v] == 0)
            dfs(v);
    }
    cor[u] = 2;
}

int main() {
    int t = 1, V, A, u, v, ncomp;

    while (cin >> V >> A) {
        if (V == 0 && A == 0)
            break;
        rep(i, 0, V) {
            adj[i].clear();
            cor[i] = 0;
        }
        while (A--) {
            cin >> u >> v;
            u--;
            v--;

            adj[u].pb(v);
            adj[v].pb(u);
        }

        ncomp = 0;
        rep(i, 0, V) {
            if (cor[i] == 0) {
                ncomp++;
                dfs(i);
                if (ncomp > 1)
                    break;
            }
        }

        cout << "Teste " << t++ << "\n";
        if (ncomp == 1)
            cout << "normal\n";
        else
            cout << "falha\n";
        cout << "\n";
    }

    return 0;
}
