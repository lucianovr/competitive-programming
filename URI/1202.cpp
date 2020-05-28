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
typedef long long int lli;
typedef pair<lli, lli> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define rep(i, a, b) for (int _i = a, __i = b, i = _i; i < __i; i++)
#define Rep(i, a) rep(i, 0, a)
#define tr(it, S) for (typeof(S.begin()) it = S.begin(); it != S.end(); it++)
#define all(S) S.begin(), S.end()
#define STD std::ios::sync_with_stdio(false)

ii fast_doubling(lli n, lli mod) {
    if (n == 0)
        return ii(0, 0);
    if (n == 1)
        return ii(1, 1);
    else if (n == 2)
        return ii(1, 2);

    ii aux = fast_doubling(n / 2, mod);
    ii ret;
    ret.first = (aux.first * (aux.second * 2 + mod - aux.first)) % mod;
    ret.second = ((lli)pow(aux.first, 2) + (lli)pow(aux.second, 2)) % mod;

    if (n % 2 == 0) {
        return ret;
    } else {
        return ii(ret.second, (ret.first + ret.second) % mod);
    }
}

int main() {
    int ct, n, m;
    char bin[10010];

    for (scanf("%d\n", &ct); ct > 0; ct--) {
        gets(bin);
        int len = strlen(bin);
        int num = 0;
        Rep(i, len) {
            num *= 2;
            num += (bin[i] - '0');
            num = num % 1500;
        }

        ii ret = fast_doubling(num, 1000);
        printf("%03d\n", ret.first);
    }
    return 0;
}
