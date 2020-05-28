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

    int N;
    double A, V[100010];

    while (cin >> N >> A) {
        if (N == 0 && A < 1)
            break;

        double lo = 0, hi = 0;
        double soma = 0;
        rep(i, 0, N) {
            cin >> V[i];
            if (V[i] > hi)
                hi = V[i];
            soma += V[i];
        }
        if (soma == A)
            printf(":D\n");

        else if (soma < A)
            printf("-.-\n");

        else {
            double mid, ans;

            rep(i, 0, 40) {
                mid = (lo + hi) / 2.0;
                soma = 0;
                rep(j, 0, N) {
                    if (V[j] > mid)
                        soma += (V[j] - mid);
                }
                if (soma < A) {
                    hi = mid;
                } else
                    lo = mid;
            }
            printf("%.4lf\n", mid);
        }
    }

    return 0;
}
