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

long long b[10000010];
void crivo(long long limite) {

    for (long long i = 0; i <= limite; i++)
        b[i] = 1;
    b[0] = b[1] = 0;
    for (long long i = 2; i <= limite; i++) {
        if (b[i] == 1) {
            for (long long j = i * i; j <= limite; j += i) {
                b[j] = 0;
            }
        }
        b[i] = b[i] + b[i - 1];
    }
}

long long func(long x) {
    long long sum = 0;
    while (x / 2 > 0) {
        sum += x / 2;
        x /= 2;
    }
    return sum;
}

int main() {

    crivo(10000001);

    long long A, B;
    while (scanf("%lld %lld", &A, &B) == 2) {
        if (A > B)
            swap(A, B);

        if (A == B) {
            printf("?\n");
            continue;
        }
        long long p = B - A;
        long long m = b[B] - b[A - 1];

        long long num = func(m + p - 1);
        long long den = func(p) + func(m - 1);

        if (m == 0 || num > den)
            printf("Bob\n");
        else
            printf("Alice\n");
    }
    return 0;
}
