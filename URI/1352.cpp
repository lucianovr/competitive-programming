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

#define isOne(mask, bit) (mask & (1LL << bit)) > 0
#define isZero(mask, bit) (mask & (1LL << bit)) == 0
#define stBit(mask, bit) (mask | (1LL << bit))
#define clrBit(mask, bit) (mask & ~(1LL << bit))
#define toogleBit(mask, bit) (mask ^ (1LL << bit))
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

int N;
bool dentro(int x, int y) { return x >= 0 && x < N && y >= 0 && y < N; }

ll quadrados() {
    // esta certo =)
    ll cnt1 = 0, cnt2 = 0;

    for (int dx = 1; dx < N; dx++)
        for (int dy = 1; dy < N; dy++) {
            int Is = N - dx - dy;
            int Js = N - dx - dy;
            cnt1 += Is * Js;

            /*
                    rep(i,0,N)
                            rep(j,0,N)
                                    if (dentro(i-dy, j+dx) && dentro(i+dx, j+dy) && dentro(i-dy+dx, j+dx+dy))
                                            cont++;
            */
        }
    for (int i = 1; i < N; i++)
        cnt2 += (N - i) * (N - i);
    return cnt1 / 2 + cnt2;
}

int main() {
    double P;
    while (scanf("%d %lf", &N, &P) && N) {
        P /= 100.0;
        ll Q = quadrados();

        ll NN = N * N;
        double num = (double(NN * (NN - 1) * (NN - 2) * (NN - 3))) * P;
        double den = (double(Q * 24.0));

        printf("%.2lf\n", num / den);
    }
    return 0;
}