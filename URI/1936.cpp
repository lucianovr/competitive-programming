#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i(a); i < (b); i++)

#define ALL(c) c.begin(), c.end()
#define UNIQUE(c)                                                                                                      \
    { sort(ALL(c); (c).resize( unique(ALL(c))-c.begin() );                                               \
    }
#define pb push_back
#define sz size()
#define D(x)                                                                                                           \
    if (1)                                                                                                             \
        cout << __LINE__ << " " << #x " = " << (x) << endl;

typedef pair<int, int> ii;
typedef long long ll;

const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;

int main() {
    int fat[10];

    fat[0] = 1;
    int i;
    for (i = 1; fat[i - 1] <= 100000; i++) {
        fat[i] = i * fat[i - 1];
    }

    int n, cont;
    while (cin >> n) {
        cont = 0;
        i = 9;
        while (n) {
            while (n >= fat[i]) {
                n -= fat[i];
                cont++;
            }
            i--;
        }

        cout << cont << "\n";
    }

    return 0;
}
