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
const double EPS = 1e-9;

bool solve(int a, int b, int c, int d, int e, int K) {
    vector<int> v;
    v.pb(a);
    v.pb(b);
    v.pb(c);
    v.pb(d);
    v.pb(e);
    int soma = 0;
    do {
        int num = 0;
        rep(i, 0, v.size()) num = num * 10 + v[i];
        soma += num;
    } while (next_permutation(v.begin(), v.end()));

    return soma == K;
}

int main() {

    int N;
    scanf("%d", &N);
    while (N--) {
        int K;
        scanf("%d", &K);

        bool ok = 0;
        rep(a, 0, 10) rep(b, a + 1, 10) rep(c, b + 1, 10) rep(d, c + 1, 10) rep(e, d + 1, 10) {
            if (solve(a, b, c, d, e, K)) {
                printf("{%d,%d,%d,%d,%d}\n", a, b, c, d, e);
                ok = 1;
            }
        }
        if (!ok)
            printf("impossivel\n");

        printf("\n");
    }

    return 0;
}
