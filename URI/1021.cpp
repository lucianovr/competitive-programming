#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i(a); i < (b); i++)
#define debug(x) cout << #x << " = " << x << "\n";

#define ALL(c) c.begin(), c.end()
#define SORT(c) sort(ALL(c))
#define UNIQUE(c)                                                                                                      \
    {                                                                                                                  \
        SORT(c);                                                                                                       \
        (c).resize(unique(ALL(c)) - c.begin());                                                                        \
    }
#define pb push_back
#define sz size()
#define D(x)                                                                                                           \
    if (1)                                                                                                             \
        cout << __LINE__ << " " << #x " = " << (x) << endl;
#define D2(x, y)                                                                                                       \
    if (1)                                                                                                             \
        cout << __LINE__ << " " << #x " = " << (x) << ", " << #y " = " << (y) << endl;

typedef pair<int, int> ii;
typedef vector<int> VI;
typedef vector<ii> VII;
typedef long long LL;

int main() {
    double values[] = {100, 50, 20, 10, 5, 2, 1, 0.5, 0.25, 0.10, 0.05, 0.01};
    int qt[12];
    double v;

    while (scanf("%lf", &v) == 1) {
        memset(qt, 0, sizeof qt);

        rep(i, 0, 12) {
            while (v >= values[i]) {
                v -= values[i];
                qt[i]++;
            }
        }

        printf("NOTAS:\n");
        rep(i, 0, 6) { printf("%d nota(s) de R$ %.2lf\n", qt[i], values[i]); }
        printf("MOEDAS:\n");
        rep(i, 6, 12) { printf("%d moeda(s) de R$ %.2lf\n", qt[i], values[i]); }
    }

    return 0;
}
