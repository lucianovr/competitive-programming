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
typedef long long int ll;

#define rep(i, a, b) for (int i = a; i < b; i++)
#define Rep(i, a) rep(i, 0, a)
#define tr(it, S) for (typeof(S.begin()) it = S.begin(); it != S.end(); it++)
#define all(S) S.begin(), S.end()
ll mod = 1000000000 + 9;

ll memo[100005];

int main() {
    int n;

    memo[3] = 1;

    for (int i = 4; i <= 100000; i++) {
        memo[i] = ((i % mod) * (memo[i - 1] % mod)) % mod;
    }

    while (scanf("%d", &n) && n) {
        printf("%lld\n", memo[n]);
    }
    return 0;
}