#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <utility>
#include <vector>
using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long int lli;

#define rep(i, a, b) for (int _i = a, __i = b, i = _i; i < __i; i++)
#define Rep(i, a) rep(i, 0, a)
#define tr(it, S) for (typeof(S.begin()) it = S.begin(); it != S.end(); it++)
#define all(S) S.begin(), S.end()
#define STD std::ios::sync_with_stdio(false)
#define MAX 400

int cont[MAX];

int main() {
    lli n;
    int t, ma;
    unsigned short h;

    scanf("%d", &t);
    Rep(j, t) {
        scanf("%lld", &n);
        ma = 0;
        while (n--) {
            scanf("%u", &h);
            cont[h]++;
        }

        int i = 0;
        for (i = 0; i < 400; i++)
            if (cont[i]) {
                printf("%d", i);
                cont[i]--;
                break;
            }
        for (; i < 231; i++)
            if (cont[i])
                while (cont[i]--)
                    printf(" %d", i);
        printf("\n");
        memset(cont, 0, sizeof(cont));
    }

    return 0;
}
