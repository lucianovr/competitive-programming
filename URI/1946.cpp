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
#define DVEC(v, n)                                                                                                     \
    {                                                                                                                  \
        cout << #v << "[] ={ ";                                                                                        \
        rep(i, 0, n) cout << v[i] << ", ";                                                                             \
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
const double EPS = 1e-9;

int N;
double M[5000][5000];

int main() {
    while (scanf("%d", &N) == 1) {
        M[0][0] = 1;
        rep(i, 1, N) M[i][0] = 0.5 * M[i - 1][0];

        for (int i = 1; i < N; i++)
            for (int j = 1; j <= i; j++)
                M[i][j] = 0.5 * M[i - 1][j - 1] + 0.5 * M[i - 1][j];

        printf("%.2lf\n", M[N - 1][N / 2] * 100);
    }
    return 0;
}