#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(c) (c).begin(), (c).end()
#define F first
#define S second
#define debug(x) cout << __LINE__ << ": " << #x << " = " << x << endl;
#define debug2(x, y) #x << " = " << x << "  " << #y << " = " << y << endl;
#define pb push_back
#define mk make_pair

const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;
typedef long long ll;
typedef pair<int, int> ii;

vector<int> E[2][10010];
int N, M, prof, root;

void dfs(int v, int n, int t) { // vertice, tamanho, arvore
    prof = max(prof, n);
    int B = E[t][v][0]; // central
    int L = E[t][v][1]; // do lado (esq, dir)

    if (B == L)
        return;
    if (B)
        dfs(B, n + 1, t);
    if (L)
        dfs(L, 1, t);
}

int main() {
    int u, v, w;
    while (scanf("%d", &N) != EOF) {
        rep(i, 0, N + 1) E[0][i].clear();
        rep(i, 0, N) {
            scanf("%d %d %d", &u, &v, &w);
            E[0][u].pb(w);
            E[0][u].pb(v);
        }

        cin >> M;
        rep(i, 0, M + 1) E[1][i].clear();
        rep(i, 0, M) {
            scanf("%d %d %d", &u, &v, &w);
            E[1][u].pb(v);
            E[1][u].pb(w);
        }

        int ans = 1000000000;
        rep(t, 0, 2) {
            prof = root = 1;
            dfs(1, 1, t);
            u = 1;
            while (E[1 - t][u][0] != 0) { // enquanto tiver filho central
                root++;
                u = E[1 - t][u][0];
            }
            ans = min(ans, N + M - min(prof, root));
        }
        printf("%d\n", ans);
    }
    return 0;
}
