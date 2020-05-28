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

const int NN = 100010;
int R[4 * NN]; // armazena indices
int A[NN];

void update(int no, int b, int e, int i, int v) {
    if (b > i || e < i)
        return;
    if (b == e && b == i) {
        A[i] = v;
        R[no] = i;
        return;
    }
    int m = (b + e) / 2;
    update(no * 2, b, m, i, v);
    update(no * 2 + 1, m + 1, e, i, v);

    int p1 = R[no * 2], p2 = R[no * 2 + 1];

    if (A[p1] <= A[p2])
        R[no] = p1;
    else
        R[no] = p2;
}

int query(int no, int b, int e, int i, int j) {
    if (b > j || e < i)
        return -1;
    if (b >= i && e <= j)
        return R[no]; // index

    int m = (b + e) / 2;
    int p1 = query(no * 2, b, m, i, j);
    int p2 = query(no * 2 + 1, m + 1, e, i, j);

    if (p1 == -1)
        return p2;
    if (p2 == -1)
        return p1;
    if (A[p1] <= A[p2])
        return p1;
    else
        return p2;
}

int main() {

    int N, M, m[NN], used[NN];

    while (scanf("%d %d", &N, &M) == 2) {
        if (N == M && N == 0)
            break;

        // leitura
        rep(i, 0, M) scanf("%d", &m[i]);

        // inicializacao
        rep(i, 0, N) update(1, 0, N - 1, i, -1);
        for (int i = 0; i <= N; i++)
            used[i] = 0;

        for (int i = 0; i < M; i++)
            update(used[i + 1] = 1, 0, N - 1, query(1, 0, N - 1, m[i], N - 1), i + 1);

        int v = 1, i = 0;
        while (i < N) {
            while (v <= N && used[v] == 1)
                v++;
            while (i < N && A[i] != -1)
                i++;
            if (i == N || v > N)
                break;
            A[i++] = v++;
        }

        printf("%d", A[0]);
        for (int i = 1; i < N; i++) {
            printf(" %d", A[i]);
        }
        printf("\n");
    }
    return 0;
}
