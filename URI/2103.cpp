#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(c) (c).begin(), (c).end()
#define F first
#define S second
#define debug(x) cout << __LINE__ << ": " << #x << " = " << x << endl;
#define debug2(x, y) cout << #x << " = " << x << "  " << #y << " = " << y << endl;
#define pb push_back
#define mk make_pair

const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;
typedef long long ll;
typedef pair<int, int> ii;

// 17:28
// 17:50
const int NN = 100000 + 10;
vector<int> E[NN], W[NN];
int U[NN], D[NN], N;

int dfs(int v, int p) {
    int sum = 0;
    for (int i = 0; i < E[v].size(); i++) {
        int u = E[v][i];
        if (u == p)
            continue;
        sum += dfs(u, v);
    }
    D[v] = 1 + sum;    // subarvore de v incluindo v
    U[v] = (N - D[v]); // acima de v sem incluir v

    //	printf("v:%d  D:%d  U:%d\n", v, D[v], U[v]);
    return 1 + sum;
}

long long ans;
long long mod = 1300031;
long long mult(long a, long b) { return ((a % mod) * (b % mod)) % mod; }

void cont(int v, int p, int c) {

    ans = (ans + mult(mult(D[v], U[v]), c)) % mod;
    for (int i = 0; i < E[v].size(); i++) {
        int u = E[v][i];
        if (u == p)
            continue;
        cont(u, v, W[v][i]);
    }
}

int main() {
    // Ideia
    // para cada aresta (x-y), apos sua remocao, saber o tamanho das duas componentes restantes

    // solucao
    /*
            para cada vertice, armazenar em  up(v) qtos vertices tem acima dele e down(v) qtos tem abaixo
    */
    int t;
    cin >> t;
    while (t--) {
        cin >> N;
        int u, v, c;
        for (int i = 1; i <= N; i++) {
            E[i].clear();
            W[i].clear();
        }

        for (int i = 0; i < N - 1; i++) {
            scanf("%d %d %d", &u, &v, &c);
            E[v].pb(u);
            W[v].pb(c);
            E[u].pb(v);
            W[u].pb(c);
        }

        dfs(1, 1);
        ans = 0;
        for (int i = 0; i < E[1].size(); i++) {
            int u = E[1][i];
            cont(u, 1, W[1][i]);
        }
        cout << ans << "\n";
    }
    return 0;
}
