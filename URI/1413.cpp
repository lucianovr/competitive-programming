#include <bits/stdc++.h>
using namespace std;
#define f(i, a, b) for (int i = (a); i < (b); i++)
#define all(c) (c).begin(), (c).end()
#define F first
#define S second
#define debug(x) cout << __LINE__ << ": " << #x << " = " << x << endl;
#define debug2(x, y) cout << #x << " = " << x << "  " << #y << " = " << y << endl;
#define pb push_back
#define mp make_pair

const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<vector<int>> vvi;

bool menor(double a, double b) {
    if (a < b && fabs(a - b) > EPS)
        return true;
    return false;
}

// Criar o grafo chamando MCMF g(V), onde g eh o grafo e V a qtde de vertices (indexado em 0)
// chamar g.add(u,v,cap,cost) para add a aresta u->v, se for bidirecional, chamar denovo .: g.add(v,u,cap,cost)
struct MCMF {
    enum { MAXN = 210, INF = INT_MAX };
    struct Edge {
        int x, y;
        int cap;
        double cost;
    };
    vector<Edge> E;
    vector<int> adj[MAXN];
    int N, prev[MAXN];
    double dist[MAXN], phi[MAXN];

    MCMF(int NN) : N(NN) {}

    void add(int x, int y, int cap, double cost) { // cost >= 0
        Edge e1 = {x, y, cap, cost}, e2 = {y, x, 0, -cost};
        adj[e1.x].push_back(E.size());
        E.push_back(e1);
        adj[e2.x].push_back(E.size());
        E.push_back(e2);
    }

    void mcmf(int s, int t, int &flowVal, double &flowCost) {
        int x;
        flowVal = flowCost = 0;
        for (x = 0; x < N; x++)
            phi[x] = 0;
        while (true) {
            for (x = 0; x < N; x++)
                prev[x] = -1, dist[x] = INF;
            dist[s] = prev[s] = 0;

            set<pair<double, int>> Q;
            Q.insert(make_pair(dist[s], s));
            while (!Q.empty()) {
                x = Q.begin()->second;
                Q.erase(Q.begin());
                for (vector<int>::iterator it = adj[x].begin(); it != adj[x].end(); it++) {
                    const Edge &e = E[*it];
                    if (e.cap <= 0)
                        continue;
                    double cc = e.cost + phi[x] - phi[e.y]; // ***
                    if (menor(dist[x] + cc, dist[e.y])) {
                        Q.erase(make_pair(dist[e.y], e.y));
                        dist[e.y] = dist[x] + cc;
                        prev[e.y] = *it;
                        Q.insert(make_pair(dist[e.y], e.y));
                    }
                }
            }
            if (prev[t] == -1)
                break;

            int z = INF;
            for (x = t; x != s; x = E[prev[x]].x)
                z = min(z, E[prev[x]].cap);
            for (x = t; x != s; x = E[prev[x]].x) {
                E[prev[x]].cap -= z;
                E[prev[x] ^ 1].cap += z;
            }
            flowVal += z;
            flowCost += z * (dist[t] - phi[s] + phi[t]);
            for (x = 0; x < N; x++)
                if (prev[x] != -1)
                    phi[x] += dist[x]; // ***
        }
    }
};

int main() {
    int N, M; // pessoas, pontos de chegada
    double X[110], Y[110], V[110];
    while (scanf("%d %d", &N, &M) == 2) {
        if (N == 0 && M == 0)
            break;
        f(i, 1, N + 1) { scanf("%lf %lf %lf", &X[i], &Y[i], &V[i]); }
        /*
                s=0,   N1, N2, Ni, Nn    Mn+j, Mn+j+1, Mn+m , t = n+m+1
        */
        MCMF g(N + M + 2);
        int s = 0, t = N + M + 1;
        f(i, 1, N + 1) g.add(s, i, 1, 0);
        f(j, 1, M + 1) g.add(N + j, t, 1, 0);

        double x, y;
        f(j, 1, M + 1) {
            scanf("%lf %lf", &x, &y);
            int c;
            while (scanf("%d", &c) && c) {
                if (V[c] > 0) {
                    double tempo = hypot(X[c] - x, Y[c] - y) / V[c];
                    g.add(c, N + j, INF, tempo);
                }
            }
        }

        int Val;
        double Cost;
        g.mcmf(s, t, Val, Cost);
        printf("%.1lf\n", Cost);
    }

    return 0;
}
