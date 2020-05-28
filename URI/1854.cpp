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

const int NN = 1010;
ll MOD = 1e9 + 7;
ll bit[NN][NN];
ll mat[NN][NN];
ll fat[10000010];
int N, M;

void update(int x, int y, ll v) {
    while (x <= N) {
        int yy = y;
        while (yy <= M) {
            bit[x][yy] += v;
            yy += yy & (-yy);
        }
        x += x & (-x);
    }
}

ll query(int x, int y) {
    ll sum = 0;
    while (x) {
        int yy = y;
        while (yy) {
            sum += bit[x][yy];
            yy -= yy & (-yy);
        }
        x -= x & (-x);
    }
    return sum;
}

ll query(int x1, int y1, int x2, int y2) {
    ll sum = query(x2, y2);
    sum -= query(x2, y1 - 1);
    sum -= query(x1 - 1, y2);
    sum += query(x1 - 1, y1 - 1);
    return sum;
}
vector<int> func(char *s) {
    vector<int> vec;
    char *pc;
    pc = strtok(s, " ");
    while (pc != NULL) {
        vec.pb(atoi(pc));
        pc = strtok(NULL, " ");
    }
    return vec;
}

ll fermat(ll b, ll p) {
    if (p == 0)
        return 1;
    ll ret = fermat(b, p / 2) % MOD;

    ret = (ret * ret) % MOD;
    if (p & 1)
        ret = (ret * b) % MOD;
    return ret;
}

int main() {
    char s[1000];
    int X1, Y1, X2, Y2;
    ll B, C;
    int dia = 1;
    fat[0] = 1;
    for (ll i = 1; i <= 10000001; i++) {
        fat[i] = (fat[i - 1] * i) % MOD;
    }

    while (cin >> N >> M) {
        memset(mat, 0, sizeof mat);

        while (gets(s)) {
            vector<int> V = func(s);
            if (V.size() == 3) {
                X1 = V[0];
                Y1 = V[1];
                B = V[2];
                update(X1, Y1, B);
                mat[X1][Y1] += B;
            } else if (V.size() == 2) {
                X1 = V[0];
                Y1 = V[1];
                update(X1, Y1, -mat[X1][Y1]);
                mat[X1][Y1] = 0;
            } else if (V.size() == 5) {
                X1 = V[0];
                Y1 = V[1];
                X2 = V[2];
                Y2 = V[3];
                C = V[4];
                B = query(X1, Y1, X2, Y2);
                ll NUM = fat[B + C - 1];
                ll DEN1 = fat[C], DEN2 = fat[B - 1];
                DEN1 = (DEN1 * DEN2) % MOD;
                DEN1 = fermat(DEN1, MOD - 2);

                printf("Day #%d: %lld\n", dia++, (NUM * DEN1) % MOD);
            }
        }
    }
    return 0;
}
