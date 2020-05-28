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

int main() {

    int L, C, P, m[10][10];
    while (cin >> L >> C >> P) {
        if (L == 0 && C == 0 && P == 0)
            break;

        P--;
        rep(i, 0, L) rep(j, 0, C) scanf("%d", &m[i][j]);

        int j = P, i;
        for (i = 0; i < L; i++) {
            if (m[i][j] != 0)
                printf("BOOM %d %d\n", i + 1, j + 1);

            int esq = j, dir = j;
            while (esq >= 0 && m[i][esq] == 0)
                esq--;
            while (dir < C && m[i][dir] == 0)
                dir++;

            if (esq == -1) {
                if (dir != C) {
                    j = max(0, j - m[i][dir]);
                    if (m[i][j] != 0) {
                        printf("BOOM %d %d\n", i + 1, j + 1);
                        break;
                    }
                }
            } else {
                if (dir == C) {
                    j = min(C - 1, j + m[i][esq]);
                    if (m[i][j] != 0) {
                        printf("BOOM %d %d\n", i + 1, j + 1);
                        break;
                    }
                } else {
                    if (m[i][esq] < m[i][dir]) {
                        j = max(0, j - (m[i][dir] - m[i][esq]));
                        if (m[i][j] != 0) {
                            printf("BOOM %d %d\n", i + 1, j + 1);
                            break;
                        }
                    } else {
                        j = max(0, j + (m[i][esq] - m[i][dir]));
                        if (m[i][j] != 0) {
                            printf("BOOM %d %d\n", i + 1, j + 1);
                            break;
                        }
                    }
                }
            }
        }

        if (i == L)
            printf("OUT %d\n", j + 1);
    }

    return 0;
}
