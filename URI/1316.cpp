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
    int N, M, L, doces[2010], sum;

    while (scanf("%d %d", &M, &L) == 2) {
        if (M == 0 && L == 0)
            break;

        scanf("%d", &N);
        sum = 0;
        rep(i, 0, N) {
            scanf("%d", &doces[i]);
            sum += doces[i];
        }

        int tab[M + 1], pai[M + 1];
        memset(tab, 0, sizeof tab);
        memset(pai, -1, sizeof pai);

        tab[0] = 1;

        for (int i = 0; i < N; i++) {
            for (int j = M; j >= 0; --j) {

                if (j - doces[i] >= 0 && tab[j] == 0) {
                    if (tab[j - doces[i]]) {
                        tab[j] = 1;
                        pai[j] = i;
                    }
                }
            }
        }
        int maior = -1;
        for (int j = M; j >= 0; j--)
            if (tab[j] == 1) {
                maior = j;
                break;
            }

        if (maior == -1 || (sum - maior) > L)
            printf("Impossible to distribute\n");
        else {
            vector<int> ans;
            int aux = maior;
            while (maior) {
                ans.pb(pai[maior] + 1);
                maior -= doces[pai[maior]];
            }

            printf("%d", ans.size());
            for (int i = ans.size() - 1; i >= 0; --i)
                printf(" %d", ans[i]);
            printf("\n");
        }
    }
    return 0;
}
