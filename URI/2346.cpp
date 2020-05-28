#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)
#define mk make_pair
#define debug(x) cout << #x << " = " << x << "\n";
#define pb push_back
typedef long long ll;
typedef pair<int, int> ii;

const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;

vector<vector<int>> E;
vector<int> deg;

struct comp {
    inline bool operator()(const int u, const int v) { return (deg[u] != deg[v]) ? deg[u] < deg[v] : u < v; }
};
set<int, comp> s;

void doit(int v) {
    deg[v] = 0;
    rep(i, 0, E[v].size()) {
        int u = E[v][i];
        if (deg[u]) {
            s.erase(u);
            --deg[u];
            s.insert(u);
        }
    }
}
int sol(int V, int A, int B) {
    s.clear();
    for (int i = 1; i <= V; i++)
        s.insert(i);
    bool flag = true;
    // for (set<int,comp> :: iterator i= s.begin(); i != s.end(); i++) cout << *i << " " ; cout << "\n";
    while (flag) {
        flag = false;

        if (!s.empty()) {
            int v = *(s.begin());
            if (deg[v] < A || s.size() - deg[v] - 1 < B) {
                s.erase(v);
                doit(v);
                flag = true;
            }
        }
        if (!s.empty()) {
            int v = *(--s.end());
            if (deg[v] < A || s.size() - deg[v] - 1 < B) {
                s.erase(v);
                doit(v);
                flag = true;
            }
        }
    }
    return s.size();
}

int main() {
    int n, m, a, b;
    cin >> n >> m >> a >> b;

    E.resize(n + 1, vector<int>());
    deg.resize(n + 1, 0);

    int u, v;
    rep(i, 0, m) {
        cin >> u >> v;
        E[u].pb(v);
        E[v].pb(u);
        deg[u]++;
        deg[v]++;
    }
    /*
    for (int v = 1; v <= n; v++){
        printf("v=%d, deg = %d : ", v, deg[v]);
        rep(i, 0, E[v].size()){
            printf ("(%d, %d) ", v, E[v][i]);
        } printf("\n");
    }
    */
    cout << sol(n, a, b) << endl;
    return 0;
}
