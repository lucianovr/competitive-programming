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

const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;

#define MAXV (3 * 10000 + 100)

vector<int> adj[MAXV][2];
int cor[MAXV][2];
int V;
int I, N, O;

bool ciclo;

#define branco 0
#define cinza 1
#define preto 2

void dfs(int u, int d) {
    cor[u][d] = cinza;

    rep(i, 0, adj[u][d].size()) {
        int v = adj[u][d][i];
        if (cor[v][d] == cinza) {
            ciclo = true;
            return;
        }
        if (cor[v][d] == branco)
            dfs(v, d);
    }

    cor[u][d] = preto;
}

bool ok() {
    if (ciclo)
        return false;
    for (int i = N + I; i < N + I + O; i++)
        if (cor[i][0] == branco)
            return false;

    for (int i = 0; i < N + I; i++)
        if (cor[i][1] == branco)
            return false;

    return true;
}

int main() {
    int input;

    while (scanf("%d %d %d", &I, &N, &O) == 3) {
        V = I + N + O;
        rep(i, 0, V + 1) {
            adj[i][0].clear();
            adj[i][1].clear();
            cor[i][0] = cor[i][1] = branco;
        }

        for (int u = I; u < N + I; u++) {
            int k;
            scanf("%d", &k);
            while (k--) {
                scanf("%d", &input);
                input--;
                adj[input][0].pb(u);
                adj[u][1].pb(input);
            }
        }

        for (int u = I + N; u < N + I + O; u++) {
            scanf("%d", &input);
            input--;
            adj[input][0].pb(u);
            adj[u][1].pb(input);
        }

        ciclo = false;

        for (int i = 0; i < I; i++) {
            if (cor[i][0] == branco) {
                dfs(i, 0);
                if (ciclo)
                    break;
            }
        }
        if (ciclo == false)
            for (int i = I + N; i < N + I + O; i++)
                if (cor[i][1] == branco)
                    dfs(i, 1);

        if (ok())
            printf("o.o\n");
        else
            printf("u.u\n");
    }

    return 0;
}
