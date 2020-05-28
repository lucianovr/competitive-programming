#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i(a); i < (b); i++)

/*
        Min Cost Max Flow - University of Alberta 2012
        Input (zero based, non-negative edges):
                n = |V|, e = |E|, s = source, t = sink
                cost[v][u] = cost for each unit of flow from v to u
                cap[v][u] = capacity
        Output of mcf():
                Flow contains the flow value
                Cost contains the minimum cost
                f[v][u] contains the flow
        
        Testado:
*/

const int maxn = 200;
const int INF = 0x3f3f3f3f;
int cap[maxn][maxn];  // cap[v][u] = capacity
int cost[maxn][maxn]; // cost[v][u] = cost for each unit of flow from v to u
int f[maxn][maxn];    // f[v][u] contains the flow

int p[maxn], d[maxn], mark[maxn], pi[maxn]; // parent, dist, visitado, potencial
int n, s, t, Flow, Cost;

int pot(int u, int v) { return d[u] + pi[u] - pi[v]; }

int dijkstra() {
    memset(mark, 0, sizeof mark);
    memset(p, -1, sizeof p);
    for (int i = 0; i <= n; i++)
        d[i] = INF;
    d[s] = 0;

    while (1) {
        int u = n;
        for (int i = 0; i < n; i++)
            if (!mark[i] && d[i] < d[u])
                u = i;
        if (u == n)
            break;

        mark[u] = 1;
        for (int v = 0; v < n; v++) {
            if (!mark[v] && f[v][u] && d[v] > pot(u, v) - cost[v][u]) {
                d[v] = pot(u, v) - cost[v][u];
                p[v] = u;
            }
            if (!mark[v] && f[u][v] < cap[u][v] && d[v] > pot(u, v) + cost[u][v]) {
                d[v] = pot(u, v) + cost[u][v];
                p[v] = u;
            }
        }
    }
    for (int i = 0; i < n; i++)
        if (p[i] < INF)
            pi[i] += d[i];
    return mark[t];
}

void mcf() {
    memset(f, 0, sizeof f);
    memset(pi, 0, sizeof pi);
    Flow = Cost = 0;

    while (dijkstra()) {
        int Min = INF;
        for (int x = t; x != s; x = p[x]) {
            if (f[x][p[x]])
                Min = min(Min, f[x][p[x]]);
            else
                Min = min(Min, cap[p[x]][x] - f[p[x]][x]);
        }

        for (int x = t; x != s; x = p[x]) {
            if (f[x][p[x]]) {
                f[x][p[x]] -= Min;
                Cost -= Min * cost[x][p[x]];
            } else {
                f[p[x]][x] += Min;
                Cost += Min * cost[p[x]][x];
            }
        }
        Flow += Min;
    }
}

int main() {

    int N, M;
    int inst = 1;
    while (cin >> N >> M) {
        vector<pair<pair<int, int>, int>> E;
        rep(i, 0, M) {
            int a, b, c;
            cin >> a >> b >> c;
            E.push_back(make_pair(make_pair(a, b), c));
        }
        int D, K; // amigos, assentos em cada voo
        cin >> D >> K;
        n = N + 2;
        s = 0;
        t = N + 1;

        memset(cap, 0, sizeof cap);
        memset(cost, 0, sizeof cost);
        rep(i, 0, E.size()) {
            int a = E[i].first.first;
            int b = E[i].first.second;
            int c = E[i].second;
            cap[a][b] = cap[b][a] = K;
            cost[a][b] = cost[b][a] = c;
        }
        cap[s][1] = cap[1][s] = D;
        cost[s][1] = cost[1][s] = 0;

        cap[N][t] = cap[t][N] = D;
        cost[N][t] = cost[t][N] = 0;

        mcf();

        printf("Instancia %d\n", inst++);

        if (Flow < D)
            printf("impossivel\n");
        else
            printf("%d\n", Cost);

        printf("\n");
    }

    return 0;
}
