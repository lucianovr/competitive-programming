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

typedef pair<int, int> ii;
typedef long long ll;

typedef vector<int> vi;
typedef vector<ii> vii;

const int INF = 0x3f3f3f3f;
const double EPS = 1e-11;

inline int cmp(double x, double y = 0, double tol = EPS) { return ((x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1); }

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

int readInt() {
    bool minus = false;
    int result = 0;
    char ch;

    ch = getchar();
    while (true) {
        if (ch == '-')
            break;
        if (ch >= '0' && ch <= '9')
            break;
        ch = getchar();
    }
    if (ch == '-')
        minus = true;
    else
        result = ch - '0';
    while (true) {
        ch = getchar();
        if (ch < '0' || ch > '9')
            break;
        result = result * 10 + (ch - '0');
    }
    if (minus)
        return -result;
    else
        return result;
}

int main() {

    int N, M;
    int R, C;
    int p[110][110], g[110][110];
    char ch;

    while (scanf("%d %d %d %d", &N, &M, &R, &C) == 4) {
        if (N == 0 && M == 0 && R == 0 && C == 0)
            break;

        rep(i, 0, N) {
            rep(j, 0, M) {
                scanf(" %c", &ch);
                g[i][j] = (ch == '0' ? 0 : 1);
                p[i][j] = 0;
            }
        }

        int cont = 0;
        for (int i = 0; i <= N - R; i++) {
            for (int j = 0; j <= M - C; j++) {
                if (p[i][j] != g[i][j]) {
                    cont++;
                    rep(k, 0, R) rep(l, 0, C) p[i + k][j + l] = 1 - p[i + k][j + l];
                }
            }
        }

        int ok = true;
        rep(i, 0, N) rep(j, 0, M) if (p[i][j] != g[i][j]) ok = false;

        if (!ok)
            cont = -1;
        printf("%d\n", cont);
    }

    return 0;
}
