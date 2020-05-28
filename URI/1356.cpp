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

long long toi(string s) {
    istringstream is(s);
    long long x;
    is >> x;
    return x;
}
string tos(long long t) {
    stringstream st;
    st << t;
    return st.str();
}
long long gcd(long long a, long long b) { return __gcd(a, b); }
long long lcm(long long a, long long b) { return a * (b / gcd(a, b)); }

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

const int NN = 100010;
ll B, P, L, N;
ll T[4 * NN]; // tree
ll A[NN];     // array
int idx[NN];
ll BB[NN];

ll fast_pow(ll b, ll p) {
    if (p == 0)
        return 1;
    ll ret = fast_pow(b, p / 2) % P;
    ret = (ret * ret) % P;
    if (p & 1)
        ret = (ret * b) % P;
    return ret;
}

void update(int no, int b, int e, int i, ll v) {
    if (b > i || e < i)
        return;
    if (b == e && b == i) {
        A[i] = v % P;
        T[no] = BB[idx[i]] * A[i];
        if (T[no] >= P)
            T[no] %= P;
        return;
    }
    int m = (b + e) / 2;
    update(no * 2, b, m, i, v);
    update(no * 2 + 1, m + 1, e, i, v);
    T[no] = T[no * 2] + T[no * 2 + 1];
    if (T[no] >= P)
        T[no] %= P;
}

ll query(int no, int b, int e, int i, int j) {
    if (b > j || e < i)
        return 0;
    if (b >= i && e <= j)
        return T[no];

    int m = (b + e) / 2;
    ll left = query(no * 2, b, m, i, j);
    ll right = query(no * 2 + 1, m + 1, e, i, j);

    ll aux = left + right;
    if (aux >= P)
        aux %= P;
    return aux;
}

void init() {
    // indexar em zero!!!
    for (int i = 0; i <= L; i++)
        A[i] = 0;
    for (int i = 0; i <= 4 * L; i++)
        T[i] = 0;

    int b = 0;
    for (int i = L - 1; i >= 0; i--)
        idx[i] = b++;

    BB[0] = 1; // B^0
    ll BMOD = B % P;
    for (int i = 1; i <= L; i++) {
        BB[i] = (BB[i - 1] * BMOD);
        if (BB[i] >= P)
            BB[i] %= P;
    }
}

int main() {
    int i, j;
    ll v, ret, INV;

    while (true) {
        B = readInt();
        P = readInt();
        L = readInt();
        N = readInt();

        if (B == 0 && P == 0 && L == 0 && N == 0)
            break;

        init();

        char op;
        while (N--) {
            scanf(" %c", &op);
            if (op == 'E') {
                int i;
                ll v;
                i = readInt();
                v = readInt();
                update(1, 0, L - 1, i - 1, v);
            } else {
                i = readInt();
                j = readInt();
                ret = query(1, 0, L - 1, i - 1, j - 1);
                INV = fast_pow(BB[idx[j - 1]], P - 2);
                ret = (ret * INV);
                if (ret >= P)
                    ret %= P;
                printf("%lld\n", ret);
            }
        }
        printf("-\n");
    }
    return 0;
}
