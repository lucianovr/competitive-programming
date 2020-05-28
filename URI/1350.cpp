#include <bits/stdc++.h>
using namespace std;

#define MAX 1000

int N;
int NOT(int v) {
    if (v <= N)
        return v + N;
    else
        return v - N;
}

vector<int> adj[2 * MAX + 10];
int cor[2 * MAX + 10];
int size[2 * MAX + 10];

bool cons(int u) {
    cor[u] = 1;
    if (cor[NOT(u)] == 1)
        return false;

    for (int i = 0; i < adj[u].size(); i++) {
        int viz = adj[u][i];
        if (cor[viz] == 0)
            if (!cons(viz))
                return false;
    }
    cor[u] = 2;
    return true;
}

int vv, vf, tot;
void dfs(int u) {
    if (u <= N)
        vv++;
    tot++;

    cor[u] = 1;
    for (int i = 0; i < adj[u].size(); i++) {
        int viz = adj[u][i];
        if (cor[viz] == 0)
            dfs(viz);
    }
    cor[u] = 2;
}

int Sol() {
    memset(cor, 0, sizeof cor);
    for (int u = 1; u <= 2 * N; u++)
        if (cor[u] == 0)
            if (!cons(u))
                return -1;

    memset(cor, 0, sizeof cor);

    int ans = 0, op1, op2;
    for (int u = 1; u <= N; u++) {
        if (cor[u] == 0) {
            vv = 0;
            tot = 0;
            dfs(u);
            vf = tot - vv;
            op1 = max(vv, vf);

            //			printf("uV = %d   vv = %d   vf = %d\n", u, vv, vf);

            vv = 0;
            tot = 0;
            dfs(u + N);
            vf = tot - vv;
            op2 = max(vv, vf);

            //			printf("uF = %d   vv = %d   vf = %d\n", u, vv, vf);

            ans += max(op1, op2);
        }
    }
    return ans;
}

int main() {
    while (cin >> N && N) {
        string setenca, is, valor;
        int v;

        for (int u = 1; u <= 2 * N + 1; u++)
            adj[u].clear();

        for (int u = 1; u <= N; u++) {
            cin >> setenca >> v >> is >> valor;
            bool T = (valor == "true.");

            if (T) {
                adj[u].push_back(v);
                adj[v].push_back(u);
                adj[NOT(u)].push_back(NOT(v));
                adj[NOT(v)].push_back(NOT(u));
            } else {
                adj[u].push_back(NOT(v));
                adj[NOT(v)].push_back(u);

                adj[NOT(u)].push_back(v);
                adj[v].push_back(NOT(u));
            }
        }

        int ret = Sol();
        if (ret == -1)
            cout << "Inconsistent\n";
        else
            cout << ret << "\n";
    }
}