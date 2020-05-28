#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define rep(i, a, b) for (int i(a); i < (b); i++)
#define debug(x) cout << #x << " = " << x << "\n";

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int v[210][210];

void floyd(int n) { rep(k, 0, n) rep(i, 0, n) rep(j, 0, n) v[i][j] |= v[i][k] & v[k][j]; }
int main() {
    int n, a, b;
    char s[1000];

    while (scanf("%d", &n) && n) {
        rep(i, 0, 200) {
            rep(j, 0, 200) { v[i][j] = 0; }
        }

        while (scanf("%d %d", &a, &b) && a + b) {
            a--;
            b--;
            scanf(" %s", s);
            int sz = strlen(s);
            rep(i, 0, sz) { v[a][b] |= 1 << (s[i] - 'a'); }
        }
        floyd(n);

        while (scanf("%d %d", &a, &b) && a + b) {
            a--;
            b--;
            bool ok = false;
            rep(k, 0, 26) {
                if ((v[a][b] & 1 << k) != 0) {
                    printf("%c", k + 'a');
                    ok = true;
                }
            }
            if (!ok)
                printf("-");
            printf("\n");
        }
        printf("\n");
    }

    return 0;
}
