#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i(a); i < (b); i++)

#define ALL(c) c.begin(), c.end()
#define UNIQUE(c)                                                                                                      \
    { sort(ALL(c); (c).resize( unique(ALL(c))-c.begin() );                                               \
    }
#define pb push_back
#define sz size()
#define D(x)                                                                                                           \
    if (1)                                                                                                             \
        cout << __LINE__ << " " << #x " = " << (x) << endl;

typedef pair<int, int> ii;
typedef long long ll;

const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;

struct ponto {
    int x, y, row, col;
};
int pd[3010][3010], N;
ponto P[3010];

bool compX(ponto a, ponto b) { return a.x < b.x; }

bool compY(ponto a, ponto b) { return a.y > b.y; }

int main() {
    while (scanf("%d", &N) == 1) {
        rep(i, 0, N) { scanf("%d %d", &P[i].x, &P[i].y); }

        memset(pd, 0, sizeof pd);

        sort(P, P + N, compX);
        rep(i, 0, N) { P[i].col = i + 1; }

        sort(P, P + N, compY);
        rep(i, 0, N) { P[i].row = i + 1; }

        rep(i, 0, N) { pd[P[i].row][P[i].col] = 1; }

        rep(i, 1, N + 1) rep(j, 1, N + 1) pd[i][j] = pd[i][j] + pd[i - 1][j] + pd[i][j - 1] - pd[i - 1][j - 1];

        int ans = 0;

        int xs, xf, ys, yf;
        rep(i, 0, N) rep(j, i + 1, N) {
            xs = min(P[i].row, P[j].row);
            xf = max(P[i].row, P[j].row);

            ys = min(P[i].col, P[j].col);
            yf = max(P[i].col, P[j].col);

            int ret = pd[xf][yf] - pd[xs - 1][yf] - pd[xf][ys - 1] + pd[xs - 1][ys - 1];
            if (ret == 2) {
                ans++;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
