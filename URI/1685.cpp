#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i(a); i < (b); i++)

#define all(c) c.begin(), c.end()
#define UNIQUE(c)                                                                                                      \
    {                                                                                                                  \
        sort(all(c));                                                                                                  \
        (c).resize(unique(all(c)) - c.begin());                                                                        \
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

#define isOne(mask, bit) (mask & (1LL << bit)) > 0
#define isZero(mask, bit) (mask & (1LL << bit)) == 0
#define stBit(mask, bit) (mask | (1LL << bit))
#define clrBit(mask, bit) (mask & ~(1LL << bit))
#define toogleBit(mask, bit) (mask ^ (1LL << bit))
#define LSOne(mask) (mask & (-mask))

typedef pair<int, int> ii;
typedef long long ll;

const int INF = 0x3f3f3f3f;
const double EPS = 1e-11;

// compara doubles
inline int cmp(double x, double y = 0, double tol = EPS) { return ((x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1); }

// compara inteiros
inline int cmp(int x, int y = 0) { return (x <= y) ? (x < y) ? -1 : 0 : 1; }

// direcoes  N  W  S  E  NW SW SE NE
int dx[] = {-1, 0, 1, 0, -1, 1, 1, -1};
int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

// knight moves
int dkx[] = {-2, -2, -1, 1, 2, 2, 1, -1};
int dky[] = {1, -1, -2, -2, -1, 1, 2, 2};

int m[1010][1010];
int R, C;

inline int getSum(int x, int y, int xx, int yy) { return m[xx][yy] - m[xx][y - 1] - m[x - 1][yy] + m[x - 1][y - 1]; }

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &R, &C);
        for (int i = 0; i <= R; i++)
            m[i][0] = 0;
        for (int j = 0; j <= C; j++)
            m[0][j] = 0;

        char cel;
        for (int i = 1; i <= R; i++)
            for (int j = 1; j <= C; j++) {
                scanf(" %c", &cel);
                m[i][j] = cel == '*';
                m[i][j] = m[i][j] + m[i - 1][j] + m[i][j - 1] - m[i - 1][j - 1];
            }
        int bestK = 0, maxK = min(R, C);
        for (int i = 1; i <= R; i++)
            for (int j = 1; j <= C; j++) {
                int lo = 0, hi = min(R - i, C - j) + 1;
                if (hi <= bestK)
                    continue; // optimization

                for (int tt = 0; tt < 20; tt++) {
                    int k = (lo + hi) / 2;
                    if (getSum(i, j, i + k - 1, j + k - 1) == 0) {
                        lo = k;
                    } else
                        hi = k - 1;
                }
                for (int k = lo; k <= hi; k++)
                    if (getSum(i, j, i + k - 1, j + k - 1) == 0) {
                        bestK = max(bestK, k);
                    }
            }
        vector<pair<int, int>> ans;
        for (int i = 1; i <= R - bestK + 1; i++)
            for (int j = 1; j <= C - bestK + 1; j++)
                if (getSum(i, j, i + bestK - 1, j + bestK - 1) == 0)
                    ans.pb(ii(i, j));
        printf("The side of the square is %d and the locations are:\n", bestK);
        rep(i, 0, ans.size()) printf("%d %d\n", ans[i].fst, ans[i].snd);
        printf("%d in total.\n", ans.size());
    }

    return 0;
}
