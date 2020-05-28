#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i(a); i < (b); i++)
#define all(c) (c).begin(), (c).end()
#define fst first
#define snd second
#define db(x) cerr << __LINE__ << ": " << #x << " = " << x << endl;

#define pb push_back
#define mp make_pair

const int INF = 0x3f3f3f3f;
typedef long long ll;
typedef pair<int, int> ii;

#define variaveis 2005

map<string, int> MP;
vector<int> adj[2 * variaveis];
vector<int> radj[2 * variaveis];
int seen[2 * variaveis], comp[2 * variaveis], ncomp;
vector<int> order;
int n; // qtde de vertices
int N; // qtde de variaveis
inline int NOT(int a) { return (a < N ? a + N : a - N); }

void add_edge(int u, int v) {
    adj[NOT(u)].pb(v);
    adj[NOT(v)].pb(u);
    radj[v].pb(NOT(u));
    radj[u].pb(NOT(v));
}

void dfs1(int u) {
    seen[u] = 1;
    rep(i, 0, (int)adj[u].size()) if (!seen[adj[u][i]]) dfs1(adj[u][i]);
    order.pb(u);
}

void dfs2(int u) {
    seen[u] = 1;
    rep(i, 0, (int)radj[u].size()) if (!seen[radj[u][i]]) dfs2(radj[u][i]);
    comp[u] = ncomp;
}

void strongly_connected_components() {
    memset(seen, 0, sizeof seen);
    order.clear();
    rep(v, 0, n) if (!seen[v]) dfs1(v);

    ncomp = 0;
    memset(seen, 0, sizeof seen);
    for (int i = order.size() - 1; i >= 0; i--) {
        int u = order[i];
        if (!seen[u]) {
            dfs2(u);
            ++ncomp;
        }
    }
}
bool sat2() {
    strongly_connected_components();
    rep(i, 0, n) if (comp[i] == comp[NOT(i)]) { return false; }
    return true;
}

void init() {
    rep(v, 0, 2 * variaveis) {
        adj[v].clear();
        radj[v].clear();
    }
    order.clear();
}

int main() {
#ifndef ONLINE_JUDGE
// freopen("_in.txt", "r", stdin);
// freopen("_out.txt", "w", stdout);
#endif
    int m, instancia = 1, flag = 0;
    while (scanf("%d", &m) > 0) {
        init();
        vector<pair<ii, ii>> edge;

        MP.clear();
        n = 0;
        string a, b;
        int nota, notb;
        rep(i, 0, m) {
            cin >> a >> b;
            nota = a[0] == '!';
            notb = b[0] == '!';
            if (nota)
                a = a.substr(1, a.size());
            if (notb)
                b = b.substr(1, b.size());
            if (MP.count(a) == 0)
                MP[a] = n++;
            if (MP.count(b) == 0)
                MP[b] = n++;
            edge.pb(mp(mp(MP[a], nota), mp(MP[b], notb)));
        }

        N = n = MP.size();
        n = n + n;

        rep(i, 0, m) {
            int va = edge[i].fst.fst + N * edge[i].fst.snd;
            int vb = edge[i].snd.fst + N * edge[i].snd.snd;
            add_edge(va, vb);
        }
        printf("Instancia %d\n%s\n\n", instancia++, sat2() ? "sim" : "nao");
    }
    return 0;
}
