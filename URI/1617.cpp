#include <bits/stdc++.h>

#define INF 0x3F3F3F3F
#define rep(i, a, b) for (int i = int(a); i < int(b); i++)
#define pb push_back
#define clr(a) memset((a), 0, sizeof(a))
#define pi 3.1415926535897932384626433832795028841971
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x, y) cout << #x << " = " << x << " --- " << #y << " " << y << "\n";
#define all(S) (S).begin(), (S).end()
#define MAXV 1005
#define F first
#define S second
#define EPS 1e-9
#define mp make_pair

using namespace std;

typedef unsigned long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int N, M, S, T;
vector<int> ladj[110];
int res[110][110];
int dist[110], pai[110];

int bellman() {
    rep(i, 0, N + 1) dist[i] = INF, pai[i] = -1;
    dist[S] = 0;

    rep(i, 1, N) rep(u, 1, N + 1) rep(v, 1, N + 1) {
        int w = res[u][v];
        if (dist[v] > dist[u] + w) {
            dist[v] = dist[u] + w;
            pai[v] = u;
        }
    }
    return dist[T];
}

int main() {
    int u, v, w;
    while (scanf("%d", &N) && N) {
        S = 1;
        T = N;

        rep(i, 0, N + 1) {
            ladj[i].clear();
            rep(j, 0, N + 1) res[i][j] = INF;
        }

        scanf("%d", &M);
        rep(i, 0, M) {
            scanf("%d %d %d", &u, &v, &w);

            res[u][v] = w;
            res[v][u] = w;
        }

        int ans = bellman();
        int x = T;

        while (x != S) {
            res[pai[x]][x] = INF;
            res[x][pai[x]] *= -1;
            x = pai[x];
        }

        ans += bellman();

        if (ans >= INF)
            printf("Pernoite.\n");
        else
            printf("%d\n", ans);
    }

    return 0;
}
