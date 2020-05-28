#include <bits/stdc++.h>
using namespace std;

int main() {

    int n, m;
    while (cin >> n >> m) {
        int x, y;
        vector<int> E[n + 1];
        while (m--) {
            cin >> x >> y;
            E[x].push_back(y);
            E[y].push_back(x);
        }
        vector<int> vis(n + 1, 0);
        queue<int> q;
        int comp = 0;

        for (int i = 1; i <= n; i++) {
            if (vis[i] == 0) {
                comp++;
                q.push(i);
                vis[i] = 1;
                while (!q.empty()) {
                    int v = q.front();
                    q.pop();
                    for (int j = 0; j < E[v].size(); j++) {
                        int u = E[v][j];
                        if (vis[u] == 0)
                            vis[u] = 1, q.push(u);
                    }
                }
            }
        }

        cout << comp << "\n";
    }
    return 0;
}