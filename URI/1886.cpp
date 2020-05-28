#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <stdio.h>
#include <string.h>
#include <utility>
#include <vector>
using namespace std;

#define rep(i, a, b) for (int i = a; i < b; i++)
typedef pair<int, int> ii;

vector<int> adj[1010];
vector<int> V[2];
int match[1010];
int cor[1010];
int vis[1010];
int N, M;

int aug(int v) {

    if (vis[v])
        return 0;
    vis[v] = true;
    int tam = adj[v].size();
    rep(j, 0, tam) {
        int r = adj[v][j]; // vertex from right side
        if (match[r] == -1 || aug(match[r])) {
            match[r] = v;
            return 1;
        }
    }
    return 0;
}

int matching() {
    int mcbm = 0;

    memset(match, -1, sizeof match);
    rep(i, 0, V[0].size()) { // vertex from left side
        rep(j, 0, V[0].size()) vis[V[0][j]] = false;
        mcbm += aug(V[0][i]);
    }
    return mcbm;
}

void collor(int v, int c) {
    cor[v] = c;
    V[c].push_back(v); // add v to the side c {0,1}
    for (int i = 0; i < adj[v].size(); i++) {
        int u = adj[v][i];
        if (cor[u] == -1)
            collor(u, 1 - c);
    }
}

int main() {
    int t, u, v;
    cin >> t;
    while (t--) {
        scanf("%d %d", &N, &M);
        for (int i = 0; i <= N; i++)
            adj[i].clear();

        for (int i = 0; i < M; i++) {
            scanf("%d %d", &v, &u);
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        memset(cor, -1, sizeof cor);
        V[0].clear();
        V[1].clear();
        for (v = 1; v <= N; v++)
            if (cor[v] == -1)
                collor(v, 0);
        int resp = matching();

        if (resp * 2 < N)
            resp = resp + (N - resp * 2);

        printf("%d\n", resp);
    }
    return 0;
}
