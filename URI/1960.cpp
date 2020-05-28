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

int main() {
    int n;

    while (cin >> n) {
        int c, d, u;

        c = (n / 100) * 100;
        n %= 100;
        if (c)
            if (c < 500) {
                if (c == 400)
                    cout << "CD";
                if (c == 300)
                    cout << "CCC";
                if (c == 200)
                    cout << "CC";
                if (c == 100)
                    cout << "C";
            } else {
                if (c < 900) {
                    cout << "D";
                    if (c == 600)
                        cout << "C";
                    if (c == 700)
                        cout << "CC";
                    if (c == 800)
                        cout << "CCC";
                } else
                    cout << "CM";
            }

        d = (n / 10) * 10;
        n %= 10;
        if (d)
            if (d < 50) {
                if (d == 40)
                    cout << "XL";
                if (d == 30)
                    cout << "XXX";
                if (d == 20)
                    cout << "XX";
                if (d == 10)
                    cout << "X";
            } else {
                if (d < 90) {
                    cout << "L";
                    if (d == 60)
                        cout << "X";
                    if (d == 70)
                        cout << "XX";
                    if (d == 80)
                        cout << "XXX";
                } else
                    cout << "XC";
            }

        u = n;
        if (u)
            if (u < 5) {
                if (u == 4)
                    cout << "IV";
                if (u == 3)
                    cout << "III";
                if (u == 2)
                    cout << "II";
                if (u == 1)
                    cout << "I";
            } else {
                if (u < 9) {
                    cout << "V";
                    if (u == 6)
                        cout << "I";
                    if (u == 7)
                        cout << "II";
                    if (u == 8)
                        cout << "III";
                } else
                    cout << "IX";
            }
        cout << "\n";
    }

    return 0;
}
