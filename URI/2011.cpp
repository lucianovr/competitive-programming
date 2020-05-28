#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i(a); i < (b); i++)

#define all(c) c.begin(), c.end()
#define UNIQUE(c)                                                                                                      \
    { sort(ALL(c); (c).resize( unique(ALL(c))-c.begin() );                                               \
    }
#define pb push_back
#define D(x)                                                                                                           \
    if (1)                                                                                                             \
        cout << __LINE__ << " " << #x " = " << (x) << endl;
#define DVEC(v, n)                                                                                                     \
    {                                                                                                                  \
        cout << #v << "[] ={ ";                                                                                        \
        rep(i, 0, n) cout << v[i] << " ";                                                                              \
        cout << "}\n";                                                                                                 \
    }
#define mp make_pair
#define fst first
#define snd second

typedef pair<int, int> ii;
typedef long long ll;

typedef vector<int> vi;
typedef vector<ii> vii;

const double EPS = 1e-12;

struct edge {
    int y;
    double A, B;
    edge(int _y = 0, double _A = 0, double _B = 0) : y(_y), A(_A), B(_B){};
};

#define MAXV 1000 + 10
int N, M;
vector<edge> E[MAXV];
bool vis[MAXV];
double dist[MAXV];

double func(double t) { // dijkstra
    memset(vis, false, sizeof vis);
    rep(i, 1, N + 1) {
        vis[i] = false;
        dist[i] = -1;
    }
    dist[1] = 0;
    priority_queue<pair<double, int>> q;
    q.push(make_pair(0, 1));

    while (!q.empty()) {
        int v = q.top().snd;
        edge e;
        q.pop();

        if (vis[v])
            continue;
        if (v == N)
            break;

        vis[v] = true;

        rep(i, 0, E[v].size()) {
            e = E[v][i];
            int u = e.y;
            double A = e.A;
            double B = e.B;
            if (dist[u] > dist[v] + A * t + B || dist[u] < 0) {
                dist[u] = dist[v] + A * t + B;
                q.push(make_pair(-dist[u], u));
            }
        }
    }
    return dist[N];
}

double solve() {
    double lo = 0;
    double hi = 24 * 60;

    while (fabs(lo - hi) >= EPS) {
        double tam = fabs((hi - lo)) / 3.0;
        double a = lo + tam;
        double b = hi - tam;
        double fa = func(a);
        double fb = func(b);

        if (fa > fb)
            hi = b;
        else
            lo = a;
    }

    return func(lo);
}

void init() { rep(i, 1, N + 1) E[i].clear(); }

int main() {
    int u, v;
    double A, B;

    while (scanf("%d %d", &N, &M) == 2) {
        init();
        rep(i, 0, M) {
            scanf("%d %d %lf %lf", &u, &v, &A, &B);
            E[u].pb(edge(v, A, B));
            E[v].pb(edge(u, A, B));
        }
        double ret = solve();
        printf("%.5lf\n", ret);
    }
    return 0;
}
