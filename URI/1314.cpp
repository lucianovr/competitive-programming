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

#define MAXV 10010

int N, M;
vector<int> adj[10010];
int dfs_num[MAXV], dfs_low[MAXV], dfs_parent[MAXV];
int dfscounter, V, dfsRoot, rootChildren, ans;

int pset[MAXV];
int find(int x) {
    if (x != pset[x])
        pset[x] = find(pset[x]);
    return pset[x];
}

int join(int x, int y) {
    if (find(x) != find(y))
        pset[find(x)] = find(y);
}

void pontes(int u) {
    dfs_low[u] = dfs_num[u] = dfscounter++;
    int tam = adj[u].size();
    rep(j, 0, tam) {
        int v = adj[u][j];
        if (dfs_num[v] == -1) {
            dfs_parent[v] = u;
            pontes(v);
            if (dfs_low[v] > dfs_num[u]) {
                ans++;
                //	cout<<"Ponte entre "<<v<<" - "<<u<<endl;
                join(v, u);
            }
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
        } else if (v != dfs_parent[u])
            dfs_low[u] = min(dfs_low[u], dfs_num[v]);
    }
}

int main() {
    int Q, u, v;
    while (cin >> N >> M >> Q) {
        if (N == 0 && M == 0)
            break;
        rep(i, 0, N) adj[i].clear();

        rep(i, 0, M) {
            cin >> u >> v;
            adj[u - 1].push_back(v - 1);
            adj[v - 1].push_back(u - 1);
        }

        for (int i = 0; i < N; i++)
            pset[i] = i;
        memset(dfs_num, -1, sizeof dfs_num);
        rep(i, 0, N) if (dfs_num[i] == -1) { dfsRoot = i, pontes(i); }
        while (Q--) {
            cin >> u >> v;
            if (find(u - 1) == find(v - 1))
                cout << "Y\n";
            else
                cout << "N\n";
        }
        cout << "-\n";
    }
    return 0;
}
