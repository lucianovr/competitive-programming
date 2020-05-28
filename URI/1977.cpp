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
#define D2(x, y) cout << #x " = " << x << "  " << #y " = " << y << endl;
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

const int INF = 0x3f3f3f3f;
const double EPS = 1e-11;

inline int cmp(double x, double y = 0, double tol = EPS) { return ((x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1); }

int readInt() {
    bool minus = false;
    int result = 0;
    char ch;

    ch = getchar();
    while (true) {
        if (ch == '-')
            break;
        if (ch >= '0' && ch <= '9')
            break;
        ch = getchar();
    }
    if (ch == '-')
        minus = true;
    else
        result = ch - '0';
    while (true) {
        ch = getchar();
        if (ch < '0' || ch > '9')
            break;
        result = result * 10 + (ch - '0');
    }
    if (minus)
        return -result;
    else
        return result;
}

vector<pair<int, int>> E[100];

int dijkstra(int N, int s, int t) {
    vector<int> dist(N, INF);
    priority_queue<pair<int, int>> pq;

    pq.push(mp(dist[s] = 0, s));
    while (!pq.empty()) {
        s = pq.top().second;
        int d = -pq.top().first;
        pq.pop();

        if (d == dist[s]) {
            if (s == t)
                break;

            for (int i = 0; i < E[s].size(); i++) {
                int viz = E[s][i].fst;
                int custo = E[s][i].snd;

                if (dist[viz] > dist[s] + custo) {
                    dist[viz] = dist[s] + custo;
                    pq.push(mp(-dist[viz], viz));
                }
            }
        }
    }
    return dist[t];
}

int main() {

    /*
     sai do servico as 17:00 , gasta X minutos
     onibus tem as 17:30 ou 17:50
     
     ela sai de 'varzea' e tem q chegar em 'alto'
    */
    int X, M, N;
    while (true) {
        X = readInt();
        M = readInt();
        N = readInt();
        if (X == 0 && M == 0 && N == 0)
            break;

        map<string, int> mapa;
        string a, b;
        int T, id = 0;

        for (int v = 0; v <= N; v++)
            E[v].clear();
        while (M-- > 0) {
            cin >> a >> b >> T;
            if (mapa.count(a) == 0)
                mapa[a] = id++;
            if (mapa.count(b) == 0)
                mapa[b] = id++;
            E[mapa[a]].pb(mp(mapa[b], T));
        }

        int dur = dijkstra(N, mapa["varzea"], mapa["alto"]);

        int min = 17 * 60 + dur + (X <= 30 ? 30 : 50);
        int hora = min / 60;
        min %= 60;

        printf("%02d:%02d\n", hora, min);
        if (hora > 18 || hora == 18 && min > 0) {
            printf("Ira se atrasar\n");
        } else
            printf("Nao ira se atrasar\n");
    }

    return 0;
}
