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
    if (0)                                                                                                             \
        cout << __LINE__ << " " << #x " = " << (x) << endl;
#define D2(x, y)                                                                                                       \
    if (0)                                                                                                             \
        cout << __LINE__ << " " << #x " = " << (x) << ", " << #y " = " << (y) << endl;

typedef pair<int, int> ii;
typedef vector<int> VI;
typedef vector<ii> VII;
typedef long long LL;

set<char> s;
int cont[350];
char t[1000100];

int main() {
    int m;
    while (scanf("%d", &m) && m) {
        scanf("\n");
        gets(t);
        D(t);
        memset(cont, 0, sizeof cont);
        s.clear();

        int ini, fim, ans = 0, tam = strlen(t);

        for (ini = fim = 0; fim < tam; fim++) {
            // cout << "add " << t[fim] << "\n";

            if (cont[t[fim]] == 0)
                s.insert(t[fim]);
            cont[t[fim]]++;

            if (s.size() > m) {
                while (true) {
                    // cout << "del " << t[ini] << "\n";
                    if (--cont[t[ini]] == 0) {
                        s.erase(t[ini++]);
                        break;
                    }
                    ini++;
                }
            }
            if (fim - ini + 1 > ans)
                ans = fim - ini + 1;
        }
        printf("%d\n", ans);
    }
    return 0;
}