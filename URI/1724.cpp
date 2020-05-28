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
const long long LINF = ((1LL) << 60);
const double EPS = 1e-9;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vector<int>> vvi;

struct vertice {
    int a, b, c; // posicoes dos vertices
    vertice() {}
    vertice(int a, int b, int c) : a(a), b(b), c(c) {}
};
int n;
char m[55][55];
int dist[55][55][55];

int sol(vertice v) {
    memset(dist, -1, sizeof dist);
    dist[v.a][v.b][v.c] = 0;
    queue<vertice> q;
    q.push(v);

    while (!q.empty()) {
        v = q.front();
        q.pop();

        for (int u = 0; u < n; u++) {
            // move vertice a to u
            if (m[v.a][u] == m[v.b][v.c]) {
                if (dist[u][v.b][v.c] == -1) {
                    dist[u][v.b][v.c] = dist[v.a][v.b][v.c] + 1;
                    q.push(vertice(u, v.b, v.c));
                }
            }

            // move vertice b to u
            if (m[v.b][u] == m[v.a][v.c]) {
                if (dist[v.a][u][v.c] == -1) {
                    dist[v.a][u][v.c] = dist[v.a][v.b][v.c] + 1;
                    q.push(vertice(v.a, u, v.c));
                }
            }

            // move vertice c to u
            if (m[v.c][u] == m[v.a][v.b]) {
                if (dist[v.a][v.b][u] == -1) {
                    dist[v.a][v.b][u] = dist[v.a][v.b][v.c] + 1;
                    q.push(vertice(v.a, v.b, u));
                }
            }
        }
    }
    int resp = INF;
    for (int p = 0; p < n; p++)
        if (dist[p][p][p] != -1)
            resp = min(resp, dist[p][p][p]);
    return resp;
}

int main() {
    while (scanf("%d", &n) && n) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        a--, b--, c--;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                scanf(" %c", &m[i][j]);
        int ret = sol(vertice(a, b, c));
        if (ret == INF)
            printf("impossible\n");
        else
            printf("%d\n", ret);
    }
    return 0;
}