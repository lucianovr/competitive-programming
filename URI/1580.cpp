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

typedef long long int ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define rep(i, a, b) for (int i = a; i < b; i++)

ll fat[1010];
int cont['Z' + 10];
ll mod = 1000000000 + 7;

int calFat() {
    fat[0] = fat[1] = 1;
    for (int i = 2; i <= 1000; i++)
        fat[i] = ((fat[i - 1] % mod) * (i % mod)) % mod;
}

ll fastexp(ll a, ll b) {

    ll x;

    if (b == 0)
        return 1;
    if (b == 1)
        return a;

    if (b % 2 == 0) {
        x = fastexp(a, b / 2) % mod;
        return (x * x) % mod;
    } else {
        return (a * fastexp(a, b - 1)) % mod;
    }
}

int main() {
    char s[1010];
    ll num, den, ans, invDen;

    calFat();
    while (gets(s)) {
        memset(cont, 0, sizeof(cont));
        int size = strlen(s);

        rep(i, 0, size) cont[s[i]]++;

        num = fat[size];
        den = 1;
        for (int i = 'A'; i <= 'Z'; i++)
            den = ((den % mod) * (fat[cont[i]] % mod)) % mod;

        invDen = fastexp(den, mod - 2);
        ans = ((num % mod) * (invDen % mod)) % mod;
        printf("%lld\n", ans);
    }

    return 0;
}