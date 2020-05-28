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

int func[210], pd[210][100], n, x, y, z, w;

int solve(int i, int f) {
    if (i == n)
        return f * y;
    if (pd[i][f] != -1)
        return pd[i][f];

    int custo = 0x3f3f3f3f;

    for (int u = max(f, func[i]); u <= 50; u++) {
        int c = u - f; // contratei c funcionarios
        custo = min(custo, x * c + w * (u - func[i]) + solve(i + 1, u));
    }

    if (f > func[i])
        for (int u = f; u >= func[i]; u--) {
            int c = f - u; // demiti c funcionarios
            custo = min(custo, y * c + w * (u - func[i]) + solve(i + 1, u));
        }

    return pd[i][f] = custo + z * func[i];
}

int main() {
    int inst = 1;
    while (scanf("%d", &n) && n) {
        rep(i, 0, n) scanf("%d", &func[i]);
        scanf("%d %d %d %d", &x, &y, &z, &w);
        memset(pd, -1, sizeof pd);
        printf("Instancia %d\n%d\n\n", inst++, solve(0, 0));
    }
    return 0;
}
