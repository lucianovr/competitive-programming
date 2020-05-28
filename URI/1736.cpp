#include <iostream>
#include <queue>
#include <stack>
#include <string.h>
#include <utility>
#include <vector>

using namespace std;

#define rep(i, a, b) for (int i(a); i < (b); i++)
#define pb push_back
#define debug(x) cout << #x << " = " << x << " ";
#define nl printf("\n");

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int N;
vi adj[60];
int grau[60];

void decode(vi prufer) {
    priority_queue<int> Q;
    int u, v;
    memset(grau, 0, sizeof grau);

    rep(i, 0, prufer.size()) grau[prufer[i]]++;

    for (int i = 1; i <= N; i++)
        if (grau[i] == 0)
            Q.push(-i);

    rep(i, 0, prufer.size()) {
        u = prufer[i];
        grau[u]--;
        v = -Q.top();
        Q.pop();
        // 	debug(u); debug(v); nl;
        adj[u].pb(v);
        adj[v].pb(u);
        if (grau[u] == 0)
            Q.push(-u);
    }
}

void dfs(int u) {
    cout << "(" << u;
    grau[u] = 1;

    rep(i, 0, adj[u].size()) {
        int v = adj[u][i];
        if (grau[v] == 0) { // nao foi visitado
            cout << " ";
            dfs(v);
        }
    }
    cout << ")";
}

int main() {
    string in;
    vi prufer;
    int val;

    while (getline(cin, in)) {

        if (in.size() == 0) {
            cout << "(1)\n";
            continue;
        }
        prufer.clear();
        N = -1;

        int len = in.size();
        for (int i = 0; i < len; i++) {
            if (in[i] == ' ')
                continue;
            val = (in[i] - '0');
            if (i + 1 < len && in[i + 1] != ' ') {
                i++;
                val *= 10;
                val = val + (in[i] - '0');
            }
            N = max(N, val);
            prufer.pb(val);
        }

        if (N == 1) {
            cout << "(" << 2 << ")\n";
            continue;
        }

        for (int i = 0; i <= N; i++) {
            adj[i].clear();
        }

        decode(prufer);

        //		for(int i=1; i <= N; i++){
        //			cout << i << "->";
        //			rep(j,0,adj[i].size())
        //				cout << adj[i][j] << "->";
        //			cout << "\n";
        //		}
        memset(grau, 0, sizeof grau); // visitado
        dfs(N);
        nl;
    }

    return 0;
}