#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctype.h>
#include <iostream>
#include <map>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define rep(i, a, b) for (int i = a; i < b; ++i)
#define pb push_back

const int INF = 0x3F3F3F3F;

int main() {
    int t;
    int dinheiro, preco[110], I, B, Q, k, q;
    int ans, aux;

    scanf("%d", &t);
    while (t--) {
        scanf("%d %d %d", &dinheiro, &I, &B);
        rep(i, 0, I) scanf("%d", &preco[i]);

        ans = 0;
        while (B--) {
            scanf("%d", &Q);
            aux = 0;
            while (Q--) {
                scanf("%d %d", &k, &q);
                aux += preco[k] * q;
            }
            ans = max(ans, dinheiro / aux);
        }

        printf("%d\n", ans);
    }
    return 0;
}
