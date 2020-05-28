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
#define isONE(mask, bit) ((mask & (1 << bit))) > 0
#define isZERO(mask, bit) ((mask & (1 << bit))) == 0
#define setBIT(mask, bit) (mask | (1 << bit))

typedef pair<int, int> ii;
typedef long long ll;

typedef vector<int> vi;
typedef vector<ii> vii;

const int INF = 0x3f3f3f3f;
const double EPS = 1e-11;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

//               0  1  2  3  4  5  6  7  8  9  0  1  2
int diasNoMes[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int main() {
    int d1, d2, m1, m2;
    while (cin >> d1 >> m1 >> d2 >> m2) {
        int dias = 0;
        while (d1 != d2 || m1 != m2) {
            dias++;
            d1++;
            if (d1 > diasNoMes[m1]) {
                d1 = 1;
                m1++;
                if (m1 == 13)
                    m1 = 1;
            }
        }
        cout << dias << "\n";
    }

    return 0;
}
