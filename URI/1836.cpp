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

int hp_calc(double iv, double bhp, double ev, double l) { return (int)((iv + bhp + sqrt(ev) / 8 + 50) * l / 50 + 10); }

int other(double iv, double bs, double ev, double l) { return (int)((iv + bs + sqrt(ev) / 8) * l / 50 + 5); }

int main() {
    int t, caso(1), ans[4];
    char nome[100], tipo[4][3] = {"HP", "AT", "DF", "SP"};
    double lvl, bs, iv, ev;

    scanf("%d", &t);
    while (t--) {
        scanf(" %s %lf", nome, &lvl);

        rep(i, 0, 4) {
            scanf(" %lf %lf %lf", &bs, &iv, &ev);
            if (i == 0)
                ans[i] = hp_calc(iv, bs, ev, lvl);
            else
                ans[i] = other(iv, bs, ev, lvl);
        }

        printf("Caso #%d: %s nivel %d\n", caso++, nome, (int)lvl);
        rep(i, 0, 4) { printf("%s: %d\n", tipo[i], ans[i]); }
    }
    return 0;
}
