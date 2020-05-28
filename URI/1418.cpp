#include <algorithm>
#include <math.h>
#include <stdio.h>
#include <vector>
using namespace std;

double T;
int N;
vector<int> adj[100010];

int dfs(int u) {
    if (adj[u].size() == 0)
        return 1;
    vector<int> w;
    for (int i = 0; i < adj[u].size(); i++)
        w.push_back(dfs(adj[u][i]));

    sort(w.begin(), w.end());
    int ans = 0, qt = ceil(T / 100 * adj[u].size());

    for (int i = 0; i < qt; i++)
        ans += w[i];

    return ans;
}

int main() {
    while (scanf("%d %lf", &N, &T) && N && T) {
        int chefe;
        for (int i = 0; i <= N; i++)
            adj[i].clear();
        for (int i = 1; i <= N; i++) {
            scanf("%d", &chefe);
            adj[chefe].push_back(i);
        }
        int ans = dfs(0);
        printf("%d\n", ans);
    }
    return 0;
}
