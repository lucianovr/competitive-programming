#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i(a); i < (b); i++)

#define all(c) c.begin(), c.end()
#define SORT(c) sort(ALL(c))
#define UNIQUE(c)                                                                                                      \
    {                                                                                                                  \
        SORT(c);                                                                                                       \
        (c).resize(unique(ALL(c)) - c.begin());                                                                        \
    }
#define pb push_back
#define sz(c) ((int)(c.size()))
#define fst first
#define snd second
#define clr(x) memset(x, 0, sizeof x)
#define nulo(x) memset(x, -1, sizeof x)

typedef pair<int, int> ii;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef map<string, int> msi;
typedef map<string, string> mss;

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

const int MAXV = 10000 + 10;

vector<int> adj[2 * MAXV];
vector<int> radj[2 * MAXV];
int seen[2 * MAXV], comp[2 * MAXV], order[2 * MAXV], ncomp, norder;
int N; // #variables
int n; // #vertices

#define NOT(x) ((x <= N) ? (x + N) : (x - N))

#define quero 1
void add_edge(int a, int b, int opcao) {
    if (a > b)
        swap(a, b);
    if (b == 0)
        return;
    if (a == 0) {
        if (opcao == quero) { // esta certo disso?? haha
            adj[NOT(b)].pb(b);
        } else {
            adj[b].pb(NOT(b));
        }
    } else {
        // normal...
        if (opcao == quero) {
            adj[NOT(a)].pb(b);
            adj[NOT(b)].pb(a);
        } else {
            a = NOT(a);
            b = NOT(b);
            adj[NOT(a)].pb(b);
            adj[NOT(b)].pb(a);
        }
    }
}

void init() {
    rep(i, 0, n + 1) {
        adj[i].clear();
        radj[i].clear();
    }
}

void dfs1(int u) {
    seen[u] = 1;
    rep(i, 0, adj[u].size()) if (!seen[adj[u][i]]) dfs1(adj[u][i]);
    order[norder++] = u;
}

void dfs2(int u) {
    seen[u] = 1;
    rep(i, 0, radj[u].size()) if (!seen[radj[u][i]]) dfs2(radj[u][i]);
    comp[u] = ncomp;
}

void strongly_connected_components() {
    rep(v, 1, n + 1) rep(i, 0, (int)adj[v].size()) radj[adj[v][i]].pb(v);

    norder = 0;
    memset(seen, 0, sizeof seen);
    rep(v, 1, n + 1) if (!seen[v]) dfs1(v);

    ncomp = 0;
    memset(seen, 0, sizeof seen);
    for (int i = n - 1, u = order[n - 1]; i >= 0; u = order[--i])
        if (!seen[u]) {
            dfs2(u);
            ncomp++;
        }
}

bool sat2() {
    strongly_connected_components();
    rep(i, 1, n + 1) if (comp[i] == comp[NOT(i)]) return false;
    return true;
}

int main() {
    int Clientes;
    while (cin >> Clientes >> N) {
        if (Clientes == 0 && N == 0)
            break;
        n = 2 * N;
        init();
        int u, v;
        rep(i, 0, Clientes) {
            scanf("%d %d", &u, &v);
            add_edge(u, v, quero);

            scanf("%d %d", &u, &v);
            add_edge(u, v, !quero);
        }

        if (sat2()) {
            printf("yes\n");
        } else
            printf("no\n");
    }
    return 0;
}
