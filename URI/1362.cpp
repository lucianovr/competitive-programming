#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define rep(i, a, b) for (int i(a); i < (b); i++)
#define debug(x) cout << #x << " = " << x << "\n";

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int res[60][60];
const int INF = 0x3f3f3f3f;

int flow, sink, source;
int pai[60];

void augment_path(int v, int minEdge) {
    if (v == source) {
        flow = minEdge;
        return;
    } else if (pai[v] != -1) {
        augment_path(pai[v], min(minEdge, res[pai[v]][v]));
        res[pai[v]][v] -= flow;
        res[v][pai[v]] += flow;
    }
}

int MAX_FLOW() {
    int max_flow = 0;
    // set up the 2d AdjMat 'res', 's', and 't' with appropriate values
    int dist[60];
    queue<int> Q;

    while (1) {
        flow = 0;

        while (!Q.empty())
            Q.pop();

        rep(i, 0, sink + 1) dist[i] = INF;
        dist[source] = 0;
        Q.push(source);
        rep(i, 0, sink + 1) pai[i] = -1;

        while (!Q.empty()) {
            int u = Q.front();
            Q.pop();
            if (u == sink)
                break;
            for (int v(0); v <= sink; v++)
                if (res[u][v] > 0 && dist[v] == INF) {
                    dist[v] = dist[u] + 1;
                    Q.push(v);
                    pai[v] = u;
                }
        }

        augment_path(sink, INF); // find the minimum edge weight 'f' along this path, if any

        // debug(flow);

        if (flow == 0)
            break;
        max_flow += flow;
    }
    return max_flow;
}

int main() {

    int t;
    // mapeando
    map<string, int> mp;
    char camisas[][4] = {{"XS"}, {"S"}, {"M"}, {"L"}, {"XL"}, {"XXL"}};
    for (int i = 0, j = 1; i < 6; i++, j += 2)
        mp[camisas[i]] = j;

    int N, M;
    for (cin >> t; t; t--) {
        cin >> N >> M;
        source = 0;
        sink = 59;

        memset(res, 0, sizeof res);

        for (int i = 1; i < 12; i += 2) { // add as camisetas usando a ideia de dividir um vertice em dois
            res[i][i + 1] = N / 6;
            res[i + 1][sink] = INF; // das camisetas para o destino
        }
        string c1, c2;
        for (int i = 1; i <= M; i++) {
            cin >> c1 >> c2;
            int C1 = mp[c1], C2 = mp[c2];

            res[i + 12][C1] = res[i + 12][C2] = 1; // arestas ligando as pessoas com suas camisetas
            res[source][i + 12] = 1;               // da origem para as pessoas
        }
        int ret = MAX_FLOW();

        if (ret == M)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}