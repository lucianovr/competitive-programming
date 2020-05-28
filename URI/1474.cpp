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

typedef unsigned long long int ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define rep(i, a, b) for (int i = a; i < b; ++i)
#define pb push_back
ll mod = 1000000;

struct matriz {
    ll a, b, c, d;
    matriz(ll _a = 1, ll _b = 0, ll _c = 0, ll _d = 1) {
        a = _a;
        b = _b;
        c = _c;
        d = _d;
    }
    matriz operator*(matriz q) {
        return matriz(

            (((a % mod) * (q.a % mod)) % mod + ((b % mod) * (q.c % mod) % mod)) % mod,
            (((a % mod) * (q.b % mod)) % mod + ((b % mod) * (q.d % mod) % mod)) % mod,

            (((c % mod) * (q.a % mod)) % mod + ((d % mod) * (q.c % mod) % mod)) % mod,
            (((c % mod) * (q.b % mod)) % mod + ((d % mod) * (q.d % mod) % mod)) % mod

        );
    }
};
matriz id;

matriz exp(matriz M, ll e) {
    if (e == 0)
        return id;
    else {
        matriz ret = exp(M, e / 2ULL);
        ret = ret * ret;
        if (e % 2 == 1ULL) {
            ret = ret * M;
        }
        return ret;
    }
}

int main() {
    ll N, K, L, ans;
    matriz ret;

    while (scanf("%llu %llu %llu", &N, &K, &L) == 3) {
        N /= 5;
        ret = exp(matriz(0, L, 1, K), N);

        ans = (ret.a + ((K % mod) * ret.c) % mod) % mod;

        printf("%06llu\n", ans);
    }
    return 0;
}
