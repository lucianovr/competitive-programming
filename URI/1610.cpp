#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <string.h>
#include <string>
#include <utility>
#include <vector>
// #include <map> include <set> #include <queue> #include <stack>
using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define rep (i, t) for (int i = 0; i < (t); i++)
#define tr(it, S) for (typeof(S.begin()) it = S.begin(); it != S.end(); it++)
#define pb push_back
#define sz size()
#define setar(S, x) memset(S, x, sizeof(x))
#define all(S) S.begin(), S.end()

vector<int> adj[10010];
int cor[10010];

bool dfs(int u) {
    cor[u] = 1; // cinza
    int v, size = adj[u].size();

    for (int i = 0; i < size; i++) {
        v = adj[u][i];
        if (cor[v] == 1)
            return true;
        else if (cor[v] == 0)
            if (dfs(v))
                return true;
    }

    cor[u] = 2; // black
    return false;
}
bool func(int n) {
    for (int i = 0; i < n; i++)
        cor[i] = 0;
    for (int i = 0; i < n; i++)
        if (cor[i] == 0)
            if (dfs(i))
                return true;

    return false;
}

int main() {
    int t;
    int n, a, b, m;
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &n, &m);
        while (m--) {
            scanf("%d %d", &a, &b);
            adj[a - 1].pb(b - 1);
        }
        if (func(n))
            printf("SIM\n");
        else
            printf("NAO\n");

        for (int i = 0; i < n; i++)
            adj[i].clear();
    }
    return 0;
}
