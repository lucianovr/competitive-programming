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

// Solucao

int N;
ll M[1005][1005], pd[1005][1005];

ll S(int i, int j) {
    if (i > N)
        return S(i - 1, j);
    if (i < 1 || j > i)
        return 0;
    if (pd[i][j] == -1000000000) {
        ll a, b;
        a = M[i][j] + S(i + 1, j + 1);
        b = S(i - 1, j);
        pd[i][j] = max(a, b);
    }
    return pd[i][j];
}

int main() {

    while (1) {
        N = readInt();
        if (N == 0)
            break;

        memset(M, 0, sizeof M);
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= i; j++) {
                M[i][j] = readInt();
                if (i - 1 > 0)
                    M[i][j] += M[i - 1][j];
                pd[i][j] = -1000000000;
            }
        }
        ll ret = S(N, 1);
        if (ret < 0)
            ret = 0;
        printf("%lld\n", ret);
    }

    return 0;
}
