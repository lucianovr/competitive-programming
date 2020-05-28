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

    int T;
    scanf("%d", &T);
    while (T--) {
        int P;
        char a, b;
        int g[3];
        g[0] = g[1] = g[2] = 0;
        scanf("%d", &P);

        // R G B
        // 0 1 2

        while (P--) {
            scanf(" %c %c", &a, &b);
            if (a == 'R') {
                if (b == 'G')
                    g[0] += 2;
                if (b == 'B')
                    g[0]++;
            }
            if (a == 'G') {
                if (b == 'B')
                    g[1] += 2;
                if (b == 'R')
                    g[1]++;
            }
            if (a == 'B') {
                if (b == 'R')
                    g[2] += 2;
                if (b == 'G')
                    g[2]++;
            }
        }

        if (g[0] == g[1] && g[1] == g[2])
            printf("trempate");
        else if (g[0] == g[1] && g[0] > g[2] || g[0] == g[2] && g[0] > g[1] || g[1] == g[2] && g[1] > g[0])
            printf("empate");
        else if (g[0] > g[1] && g[0] > g[2])
            printf("red");
        else if (g[1] > g[2] && g[1] > g[0])
            printf("green");
        else if (g[2] > g[1] && g[2] > g[0])
            printf("blue");

        printf("\n");
    }

    return 0;
}
