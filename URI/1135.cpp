#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;
typedef long long int ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define rep(i, a, b) for (int _i = a, __i = b, i = _i; i < __i; i++)
#define Rep(i, a) rep(i, 0, a)
#define tr(it, S) for (typeof(S.begin()) it = S.begin(); it != S.end(); it++)
#define all(S) S.begin(), S.end()
#define pb push_back
#define MAX 100010
int level[MAX], pai[MAX], dist[MAX]; // nivel, pai do vertice, distancia desde a origem

int main() {
    int n, u, d, q, v;

    while (scanf("%d", &n) && n) {
        level[0] = 0;
        dist[0] = 0;

        rep(i, 1, n) {
            scanf("%d%d", &u, &d);
            pai[i] = u;
            level[i] = level[u] + 1;
            dist[i] = dist[u] + d;
        }

        scanf("%d", &q);
        Rep(i, q) {
            ll tot = 0LL;
            scanf("%d%d", &u, &v);
            if (level[u] > level[v])
                swap(u, v);

            while (level[v] != level[u]) {
                tot += dist[v] - dist[pai[v]];
                v = pai[v];
            }

            while (u != v) {
                tot += dist[u] - dist[pai[u]];
                tot += dist[v] - dist[pai[v]];
                u = pai[u];
                v = pai[v];
            }
            if (i == 0)
                printf("%lld", tot);
            else
                printf(" %lld", tot);
        }
        printf("\n");
    }
    return 0;
}
