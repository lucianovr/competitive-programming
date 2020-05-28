#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <vector>
#define rep(i, a, b) for (int i = a; i < b; i++)

int gr[1010][1010], base[1010], sgn[1010], vis[1010], mark[1010], order[1010];

std::vector<int> wk[1010], top;

void toposort(int u) {
    if (mark[u])
        return;
    for (int i = 1; i <= gr[u][0]; i++)
        toposort(gr[u][i]);
    mark[u] = 1;
    top.push_back(u);
}

int dfs(int u) {
    if (vis[u] == 1)
        return sgn[u]; // cb

    if (gr[u][0] == 0) { // cb
        return sgn[u] = base[u];
    }

    vis[u] = 1;

    int sum = 0;
    for (int i = 1; i <= gr[u][0]; i++)
        sum += dfs(gr[u][i]);

    return sgn[u] = sum + base[u];
}

void propagate(int u) {
    if (vis[u])
        return;

    for (int i = 1; i <= gr[u][0]; i++)
        propagate(gr[u][i]);
    vis[u] = 1;
}

bool cmp(int a, int b) { return order[a] < order[b]; }

int main() {
    int T, E, workers, x;
    while (scanf("%d %d", &T, &E) && T != 0 && E != 0) {

        rep(i, 0, E + 1) wk[i].clear();

        for (int t = 1; t <= T; t++) {
            scanf("%d %d %d", &base[t], &gr[t][0], &workers);
            for (int i = 1; i <= gr[t][0]; i++)
                scanf("%d", &gr[t][i]);
            for (int i = 0; i < workers; i++) {
                scanf("%d", &x);
                wk[x].push_back(t);
            }
        }

        memset(vis, 0, sizeof vis);
        for (int i = 1; i <= T; i++) {
            sgn[i] = dfs(i);
        }

        top.clear();
        memset(mark, 0, sizeof mark);
        for (int i = 1; i <= T; i++) {
            if (mark[i] == 0) {
                toposort(i);
            }
        }

        reverse(top.begin(), top.end());
        rep(i, 0, top.size()) order[top[i]] = i;

        printf("*****\n");
        for (int i = 1; i <= E; i++) {
            memset(vis, 0, sizeof vis);
            int sal = 0;
            sort(wk[i].begin(), wk[i].end(), cmp);
            for (int j = 0; j < wk[i].size(); j++) {
                int k = wk[i][j];
                if (!vis[k]) {
                    sal += sgn[k];
                    propagate(k);
                }
            }
            printf("%d %d\n", i, sal); // muito sal
        }
    }
    return 0;
}