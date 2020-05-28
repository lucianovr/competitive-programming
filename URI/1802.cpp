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

    int p, m, f, q, b;
    int P[10], M[10], F[10], Q[10], B[10];
    int k;

    p = readInt();
    rep(i, 0, p) P[i] = readInt();

    m = readInt();
    rep(i, 0, m) M[i] = readInt();

    f = readInt();
    rep(i, 0, f) F[i] = readInt();

    q = readInt();
    rep(i, 0, q) Q[i] = readInt();

    b = readInt();
    rep(i, 0, b) B[i] = readInt();

    k = readInt();

    vector<int> v;
    rep(pp, 0, p) rep(mm, 0, m) rep(ff, 0, f) rep(qq, 0, q) rep(bb, 0, b) v.pb(P[pp] + M[mm] + F[ff] + Q[qq] + B[bb]);

    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    int soma = 0;
    rep(i, 0, k) soma += v[i];

    printf("%d\n", soma);

    return 0;
}
