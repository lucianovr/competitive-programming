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

#define N 100100
#define LOG 22

int V; // vertices
int Ciclos;
vector<int> E[N];
int pai[N][LOG + 2];
int H[N]; // altura
int label[N];
int tam[N + N];
int cor[N];
int dist[N]; // distancia de u para uma saida do ciclo

enum { BRANCO, CINZA, PRETO };

int pset[N];
int find(int x) {
    if (x != pset[x])
        return pset[x] = find(pset[x]);
    return pset[x];
}
void join(int x, int y) { pset[find(x)] = find(y); }
bool same_set(int x, int y) { return find(x) == find(y); }

int dfs(int u) {
    cor[u] = CINZA;

    for (auto v : E[u]) {
        if (cor[v] == BRANCO) {
            pai[v][0] = u;
            dfs(v);
        }
        if (cor[v] == CINZA) {
            vector<int> ciclo;
            int a = u;
            while (a != v) {
                ciclo.pb(a);
                a = pai[a][0];
            }
            ciclo.pb(v);
            for (auto x : ciclo) {
                label[x] = Ciclos; // rotulando os vertices que fazem parte de um ciclo
            }
            tam[Ciclos] = ciclo.size(); // tamanho do ciclo
            Ciclos++;

            int i, x;
            // encontrando uma saida de um ciclo .: vertice que tem aresta para as folhas
            for (i = 0; i < ciclo.size(); i++) {
                x = ciclo[i];
                if (E[x].size() > 1) {
                    break;
                }
            }
            dist[x] = 0; // calculo as distancias dos outros para ele
            for (int j = (i + 1) % ciclo.size(), sz = 0; sz < ciclo.size() - 1; sz++, j = (j + 1) % ciclo.size()) {
                dist[ciclo[j]] = dist[ciclo[(j - 1 + ciclo.size()) % ciclo.size()]] + 1;
            }
        }
    }
    cor[u] = PRETO;
}

void init() {
    Ciclos = V + 1; // valor do rotulo do 1o ciclo
    for (int i = 0; i <= V; i++) {
        label[i] = i;
        H[i] = 0;
        pai[i][0] = i;
        cor[i] = BRANCO;
        pset[i] = i;
        E[i].clear();
    }
}

void build(int u, int p) {
    for (auto v : E[u]) {
        if (v == p || label[u] == label[v])
            continue;
        H[v] = H[u] + 1;
        pai[v][0] = u;
        for (int k = 1; k <= LOG; k++) {
            pai[v][k] = pai[pai[v][k - 1]][k - 1];
        }
        build(v, u);
    }
}

int inside_ciclo(int a, int b) {
    int len = tam[label[a]];

    if (dist[a] > dist[b])
        swap(a, b);

    int op1 = dist[b] - dist[a];
    int op2 = len - dist[b] + dist[a];
    return min(op1, op2);
}

int lca(int a, int b) {
    if (!same_set(a, b))
        return -1;
    if (H[a] < H[b])
        return lca(b, a);

    // subir a
    int ans = 0;
    if (H[a] != H[b]) {
        for (int k = LOG; k >= 0; k--) {
            if (H[pai[a][k]] > H[b]) {
                a = pai[a][k];
                ans += (1 << k);
            }
        }
        a = pai[a][0];
        ans++;
        if (a == b) {
            //  printf("lca = %d %d\n", a, b);
            return ans;
        }
    }
    if (label[a] == label[b]) {
        // printf("lca = %d %d\n", a, b);
        return ans + inside_ciclo(a, b);
    }

    for (int k = LOG; k >= 0; k--) {
        if (label[pai[a][k]] != label[pai[b][k]]) {
            ans = ans + (1 << k) + (1 << k);
            a = pai[a][k];
            b = pai[b][k];
        }
    }
    a = pai[a][0];
    b = pai[b][0];
    ans += 2;

    // printf("lca = %d %d\n", a, b);

    if (a == b)
        return ans;
    else
        return ans + inside_ciclo(a, b);
}
int main() {

    while (scanf("%d", &V) == 1) {
        init();
        for (int u = 1, v; u <= V; u++) {
            scanf(" %d", &v);
            E[v].pb(u); // montei o grafo invertido
            join(u, v);
        }

        // para achar os ciclos
        for (int u = 1; u <= V; u++) {
            if (cor[u] == BRANCO) {
                dfs(u);
            }
        }

        // for (int u = 1; u <= V; u++){
        //    printf("u=%d lb=%d ", u, label[u]); if (label[u] != u) printf("dist=%d", dist[u]);
        //    printf("\n");
        // }

        // construir a pd do lca
        for (int u = 1; u <= V; u++) {
            if (label[u] > V && E[u].size() > 1) { // v esta num ciclo
                for (int k = 0; k <= LOG; k++)
                    pai[u][k] = u;
                H[u] = 0;
                build(u, u);
            }
        }

        //  for (int u = 1; u <= V; u++){
        //       if (label[u] > V) continue;
        //       printf("\n%d:", u);
        //       int v = pai[u][0];
        //       for (int k = 0; k <= V; k++){
        //            printf(" ->%d",v);
        //           v = pai[v][0];
        //       }
        //    } printf("\n");

        int Q;
        scanf("%d", &Q);
        while (Q--) {
            int a, b;
            scanf("%d %d", &a, &b);
            printf("%d\n", lca(a, b));
        }
    }

    return 0;
}
