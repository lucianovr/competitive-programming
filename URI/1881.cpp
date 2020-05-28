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

#define isONE(mask, bit) ((mask & (1<<bit))>0
#define isZERO(mask, bit) ((mask & (1<<bit))==0
#define setBIT(mask, bit) (mask | (1 << bit))
#define clearBIT(mask, bit) (mask & ~(1 << bit))
#define toogleBIT(mask, bit) (mask ^ (1 << bit))
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

struct matrix {
    double m[3][3];
    matrix() { rep(i, 0, 3) rep(j, 0, 3) m[i][j] = 0.0; }
};

matrix mult(matrix a, matrix b) {
    matrix c = matrix();
    rep(i, 0, 3) rep(j, 0, 3) rep(k, 0, 3) c.m[i][j] = c.m[i][j] + a.m[i][k] * b.m[k][j];
    return c;
}

matrix fastPow(matrix a, int n) {
    if (n == 0) {
        matrix id = matrix();
        rep(i, 0, 3) id.m[i][i] = 1.0;
        return id;
    }
    if (n == 1)
        return a;

    matrix ret = fastPow(a, n / 2);
    ret = mult(ret, ret);
    if (n & 1)
        ret = mult(ret, a);

    return ret;
}

int main() {

    int t;
    scanf("%d", &t);
    while (t--) {
        double a, l;
        int n;
        scanf("%lf %lf %d", &a, &l, &n);

        a = a * M_PI / 180.0;

        matrix M;
        M.m[0][0] = cos(a);
        M.m[0][1] = -sin(a);
        M.m[0][2] = 1.0;
        M.m[1][0] = sin(a);
        M.m[1][1] = cos(a);
        M.m[1][2] = 0;
        M.m[2][0] = 0;
        M.m[2][1] = 0;
        M.m[2][2] = 1;

        M = fastPow(M, n);
        double x = M.m[0][0] * 0 + M.m[0][1] * 0 + M.m[0][2] * l;
        double y = M.m[1][0] * 0 + M.m[1][1] * 0 + M.m[1][2] * l;

        if (x <= 0 && cmp(x, 0, 0.001) == 0)
            x = fabs(x);
        if (y <= 0 && cmp(y, 0, 0.001) == 0)
            y = fabs(y);

        printf("%.2lf %.2lf\n", x, y);
    }

    return 0;
}
