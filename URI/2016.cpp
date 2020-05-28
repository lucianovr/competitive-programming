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

int main() {

    int P, R, VC[] = {10000, 1000, 100, 10, 1};

    while (scanf("%d %d", &P, &R) == 2) {
        int ganhou = 0, poderia = 0;

        while (R--) {
            int B, D, pi; // banco, Daedalus, valor da pessoa i
            int somaT, somaO;

            scanf("%d", &B);
            scanf("%d", &D);

            somaT = somaO = 0;
            rep(i, 1, P) {
                scanf("%d", &pi);
                somaO += pi;
            }
            somaT = somaO + D;

            if (somaT <= B)
                ganhou += D;

            for (int i = 0; i < 5; i++)
                if (somaO + VC[i] <= B) {
                    poderia += VC[i];
                    break;
                }
        }

        printf("%d\n", poderia - ganhou);
    }
    return 0;
}
