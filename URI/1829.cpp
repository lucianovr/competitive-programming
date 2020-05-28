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
    int t, ans[1010], L, P;
    double a, b, n, l, p;

    while (cin >> t) {
        L = P = 0;
        rep(j, 0, t) {
            scanf("%lf^%lf", &a, &b);
            scanf("%lf!", &n);

            l = b * log10(a);
            p = 0;
            for (int i = 1; i <= n; i++)
                p += log10(double(i));

            if (l > p)
                ans[j] = 1, L++;
            if (l < p)
                ans[j] = 2, P++;
        }

        if (L == P)
            printf("A competicao terminou empatada!\n");
        else if (L > P)
            printf("Campeao: Lucas!\n");
        else
            printf("Campeao: Pedro!\n");
        rep(j, 0, t) {
            printf("Rodada #%d: ", j + 1);
            if (ans[j] == 1)
                printf("Lucas foi o vencedor\n");
            else
                printf("Pedro foi o vencedor\n");
        }
    }
    return 0;
}