#include <bits/stdc++.h>
using namespace std;
#define f(i, a, b) for (int i = (a); i < (b); i++)
#define all(c) (c).begin(), (c).end()
#define F first
#define S second
#define debug(x) cout << __LINE__ << ": " << #x << " = " << x << endl;
#define debug2(x, y) cout << #x << " = " << x << "  " << #y << " = " << y << endl;
#define pb push_back
#define mp make_pair

const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<vector<int>> vvi;

struct frac {
    int n, d;

    frac() {}

    frac(int num, int den) {
        int gcd = __gcd(num, den);
        n = num / gcd;
        d = den / gcd;
    }

    frac operator+(frac outra) {
        int num = n * outra.d + outra.n * d;
        int den = d * outra.d;

        return frac(num, den);
    }

    void print() { cout << n << " " << d << "\n"; }
};

int main() {
    int n1, d1, n2, d2;
    while (cin >> n1 >> d1 >> n2 >> d2) {
        frac f1 = frac(n1, d1);
        frac f2 = frac(n2, d2);
        frac f3 = f1 + f2;
        f3.print();
    }
    return 0;
}
