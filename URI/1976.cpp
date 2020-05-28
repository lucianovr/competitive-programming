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

ll row[1010], col[1010];
ll pd[1010][1010];
ll M[1010][1010];
int S[1010][1010];
int one;

ll solve(int N) {
    for (int i = 0; i < N; i++)
        M[i][i] = 0, S[i][i] = i;

    for (int i = N - 2; i >= 0; i--)
        for (int j = i + 1; j < N; j++) {
            M[i][j] = INF;
            for (int k = i; k < j; k++) {
                ll ret = M[i][k] + M[k + 1][j] + row[i] * col[k] * col[j];
                if (ret < M[i][j]) {
                    M[i][j] = ret;
                    S[i][j] = k;
                } else if (ret == M[i][j])
                    one = 2;
            }
        }

    return M[0][N - 1];
}

void backtrack(int i, int j) {
    if (i == j) {
        printf("A%d", i + 1);
    } else {
        int k = S[i][j];
        printf("(");
        backtrack(i, k);
        backtrack(k + 1, j);
        printf(")");
    }
}

int main() {
    int n;
    while (scanf("%d", &n) && n) {
        rep(i, 0, n) scanf("%lld %lld", &row[i], &col[i]);

        one = 1;
        ll ans = solve(n);
        if (one == 1) {
            backtrack(0, n - 1);
            printf("\n");
        } else
            printf("%lld\n", ans);
    }
    return 0;
}
