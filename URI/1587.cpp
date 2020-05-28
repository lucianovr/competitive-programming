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

const int NN = 2000000 + 2;
int bA[NN + 10], bB[NN + 10];
int posA[2551805], posB[2551805];

int queryA(int x) {
    int sum = 0;
    while (x) {
        sum += bA[x];
        x -= x & (-x);
    }
    return sum;
}

void updateA(int x, int v) {
    while (x <= NN) {
        bA[x] += v;
        x += x & (-x);
    }
}

int queryB(int x) {
    int sum = 0;
    x = 2000001 - x + 1;
    while (x) {
        sum += bB[x];
        x -= x & (-x);
    }
    return sum;
}

void updateB(int x, int v) {
    x = 2000001 - x + 1;
    while (x <= NN) {
        bB[x] += v;
        x += x & (-x);
    }
}

int main() {
    int N, E;
    while (cin >> N >> E) {
        if (N == 0 && E == N)
            break;

        memset(bA, 0, sizeof bA);
        memset(bB, 0, sizeof bB);

        for (int i = 1; i <= N / 2; i++) {
            scanf("%d", &posA[i]);
            updateA(++posA[i], 1);
        }
        for (int i = 1; i <= N / 2; i++) {
            scanf("%d", &posB[i]);
            updateB(++posB[i], 1);
        }

        int golA = 0, golB = 0;
        bool impedido = false;

        char C, T;
        int jog, pos, qt;

        while (E--) {
            scanf(" %c", &C);
            if (C == 'I' || C == 'P') {
                scanf(" %c%d", &T, &jog);
                if (!impedido) {
                    if (T == 'A') {
                        qt = queryB(posA[jog] + 1); // qtde de jogadores do time B na frente do jog Ai
                        if (qt * 11 < N)
                            impedido = true;
                    } else {
                        qt = queryA(posB[jog] - 1); // qtde de jogadores do time A na frente do jog Bi
                        if (qt * 11 < N)
                            impedido = true;
                    }
                }

            } else if (C == 'M') {
                scanf(" %c%d %d", &T, &jog, &pos);
                pos++;
                if (T == 'A') {
                    updateA(posA[jog], -1);
                    posA[jog] = pos;
                    updateA(posA[jog], +1);
                } else {
                    updateB(posB[jog], -1);
                    posB[jog] = pos;
                    updateB(posB[jog], +1);
                }
            } else if (C == 'G') {
                scanf(" %c", &T);
                if (!impedido) {
                    if (T == 'A')
                        golB++;
                    else
                        golA++;
                }
                impedido = false;
            } else if (C == 'S') {
                impedido = false;
            }
        }

        printf("%d X %d\n", golA, golB);
    }
    return 0;
}
