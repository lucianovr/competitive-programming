#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <utility>
#include <vector>

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define rep(i, n) for (int i = 0; i < n; ++i)
#define all(S) S.begin(), S.end()
#define pb push_back
#define debug(x) cout << #x << " = " << x << endl;

//-------------------------------------------------------------------------------------------
// Almost Shortest Path

const int INF = 0x3f3f3f3f;

vector<int> Dijkstra(int s, int n, vector<pair<int, int>> Adj[]) { // source e # de vertices e lista de Adjacencias
    vector<int> D(n, INF);
    priority_queue<pair<int, int>> PQ;
    PQ.push(make_pair(D[s] = 0, s));

    while (!PQ.empty()) {
        int u = PQ.top().second;
        int d = -PQ.top().first;
        PQ.pop();

        if (d <= D[u]) {
            for (int i = 0; i < Adj[u].size(); i++) {
                int v = Adj[u][i].first, cost = Adj[u][i].second;
                if (D[v] > d + cost) {
                    D[v] = d + cost;
                    PQ.push(make_pair(-D[v], v));
                }
            }
        }
    }
    return D; // retorna vetor de distancias
}

int main() {
    int n, m, a, b, w, s, t;
    vector<pair<int, int>> adj[501], adjT[501]; // lista de adjacencias normal e transposta
    vector<pair<pair<int, int>, int>> edges;    // lista com arestas

    while (scanf("%d%d", &n, &m) && n + m) {

        scanf("%d%d", &s, &t);
        for (int i = 0; i < n; i++) {
            adj[i].clear();
            adjT[i].clear();
        }
        edges.clear();

        while (m--) {
            scanf("%d%d%d", &a, &b, &w);
            adj[a].push_back(make_pair(b, w));
            adjT[b].push_back(make_pair(a, w));
            edges.push_back(make_pair(make_pair(a, b), w));
        }

        vector<int> DS = Dijkstra(s, n, adj); // distancia de S para todos
        int MIN = DS[t];

        if (MIN == INF) {
            printf("-1\n");
            continue;
        }
        vector<int> DT = Dijkstra(t, n, adjT); // distancia de todos para T

        for (int i = 0; i < n; i++)
            adj[i].clear(); // criando nova lista com arestas validas
        pair<pair<int, int>, int> edge;
        for (int i = 0; i < edges.size(); i++) {
            edge = edges[i];
            a = edge.first.first;
            b = edge.first.second;
            w = edge.second;

            if (DS[a] + w + DT[b] != MIN) // s - > (a,b) ->  t,  entao (a,b) nao faz parte de algum menor caminho
                adj[a].pb(make_pair(b, w));
        }
        DS = Dijkstra(s, n, adj); // novamente dist de S para todos
        MIN = DS[t];              // dist de S para t
        printf("%d\n", (MIN != INF ? MIN : -1));
    }
    return 0;
}
