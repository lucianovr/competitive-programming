#include <cstdio>
#include <vector>
using namespace std;
#define MAX 2010

vector<int> adj[MAX], ADJ[MAX];
int cnt, CNT, vis[MAX];

void dfs(int u) {
    vis[u] = 1;
    cnt++;
    int sz = adj[u].size();
    for (int i = 0; i < sz; i++)
        if (!vis[adj[u][i]])
            dfs(adj[u][i]);
}

void DFS(int u) {
    vis[u] = 1;
    CNT++;
    int sz = ADJ[u].size();
    for (int i = 0; i < sz; i++)
        if (!vis[ADJ[u][i]])
            DFS(ADJ[u][i]);
}

int main() {
    int N, M, a, b, p;
    while (scanf("%d %d", &N, &M) && (N != 0 && M != 0)) {
        while (M--) {
            scanf("%d %d %d", &a, &b, &p);
            a--;
            b--;
            p--;
            adj[a].push_back(b);
            ADJ[b].push_back(a);
            if (p) {
                adj[b].push_back(a);
                ADJ[a].push_back(b);
            }
        }
        cnt = 0;
        for (int i = 0; i < N; i++)
            vis[i] = 0;
        dfs(0);
        if (cnt != N)
            printf("0\n");

        else {
            CNT = 0;
            for (int i = 0; i < N; i++)
                vis[i] = 0;
            DFS(0);
            if (CNT != N)
                printf("0\n");
            else
                printf("1\n");
        }

        for (int i = 0; i < N; i++) {
            adj[i].clear();
            ADJ[i].clear();
        }
    }
    return 0;
}
