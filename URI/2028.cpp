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

void func(int n, int vezes, int caso, int x) {
    if (n == 0) {
        x++;
        printf("Caso %d: %d %s\n", caso, x, x > 1 ? "numeros" : "numero");
        printf("0");
        return;
    }
    if (vezes == 1) {
        func(n - 1, n - 1, caso, x + 1);
    } else
        func(n, vezes - 1, caso, x + 1);
    printf(" %d", n);
}

int main() {

    int n, caso = 1;
    while (cin >> n) {
        func(n, n, caso++, 0);
        printf("\n\n");
    }

    return 0;
}
