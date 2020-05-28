#include <algorithm>
#include <cstdlib>
#include <map>
#include <stdio.h>
#include <string>
#include <utility>
#include <vector>
using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define rep(i, n) for (int i = 0; i < (n); i = i + 1)
#define tr(it, S) for (typeof(S.begin()) it = S.begin(); it != S.end(); it++)
#define all(S) (S).begin(), (S).end()
#define setar(S, x) memset(S, x, sizeof(S))
#define pb push_back
#define sz size()
#define contem(s, x) (s.find(x) != s.end())

int main() {
    int madj[110][110];

    int M, t, x0, y0, x1, y1, n, s, l, o;
    while (scanf("%d", &M) && M) {
        map<ii, int> mp;
        int r = 1;
        for (int i = M - 1; i >= 0; i--)
            for (int j = 0; j < M; j++) {
                ii p(i, j);
                mp[p] = r++;
            }
        int MAX = M * M;
        for (int i = 1; i <= MAX; i++)
            for (int j = 1; j <= MAX; j++) {
                madj[i][j] = -1;
                if (i == j)
                    madj[i][j] = 0;
            }

        for (int i = M - 1; i >= 0; i--)
            for (int j = 0; j < M; j++) {

                ii u(i, j);
                int x = mp[u];
                scanf("%d %d %d %d", &n, &s, &l, &o);
                if (n == 1) {
                    ii v(i + 1, j);
                    int e = mp[v];
                    madj[x][e] = 1;
                }
                if (s == 1) {
                    ii v(i - 1, j);
                    int e = mp[v];
                    madj[x][e] = 1;
                }
                if (l == 1) {
                    ii v(i, j - 1);
                    int e = mp[v];
                    madj[x][e] = 1;
                }
                if (o == 1) {
                    ii v(i, j + 1);
                    int e = mp[v];
                    madj[x][e] = 1;
                }
            }

        for (int k = 1; k <= MAX; k++)
            for (int i = 1; i <= MAX; i++)
                if (i != k && madj[i][k] != -1)
                    for (int j = 1; j <= MAX; j++)
                        if (j != i && j != k && madj[k][j] != -1)
                            if (madj[i][j] == -1 || madj[i][j] > madj[i][k] + madj[k][j])
                                madj[i][j] = madj[i][k] + madj[k][j];

        scanf("%d", &t);
        int d;
        while (t--) {
            scanf("%d %d %d %d", &x0, &y0, &x1, &y1);
            ii a(y0, x0), b(y1, x1);

            int u = mp[a], v = mp[b];
            d = madj[u][v];
            if (d != -1)
                printf("%d\n", d);
            else
                printf("Impossible\n");
        }
        printf("\n");
    }
    return 0;
}