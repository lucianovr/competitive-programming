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
typedef pair<ll, ll> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define rep(i, a, b) for (int i = a; i < b; ++i)
#define Rep(i, a) rep(i, 0, a)
#define tr(it, S) for (typeof(S.begin()) it = S.begin(); it != S.end(); it++)
#define all(S) S.begin(), S.end()
#define pb push_back
#define MAX 1000

const int INF = 0x3F3F3F3F;
const double EPS = 1e-10;
int cmp(double x, double y = 0, double tol = EPS) { return ((x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1); }
bool cmp_eq(double x, double y) { return cmp(x, y) == 0; }
bool cmp_lt(double x, double y) { return cmp(x, y) < 0; }

// 			lef Rig Up Dow
int di[] = {0, 0, -1, 1, -1, -1, 1, 1};
int dj[] = {-1, 1, 0, 0, -1, 1, 1, -1};

ii fast_doubling(ll n, ll mod) {
    if (n == 0)
        return ii(0, 0);
    if (n == 1)
        return ii(1, 1);
    else if (n == 2)
        return ii(1, 2);

    ii aux = fast_doubling(n / 2, mod);
    ii ret;
    ret.first = (aux.first * (aux.second * 2 + mod - aux.first)) % mod;
    ret.second = ((ll)pow(aux.first, 2) + (ll)pow(aux.second, 2)) % mod;

    if (n % 2 == 0) {
        return ret;
    } else {
        return ii(ret.second, (ret.first + ret.second) % mod);
    }
}

int main() {

    int N, M, C;
    while (cin >> N >> M) {
        ll C = 1;
        int a, b, sum;
        a = 1;
        b = 1;
        while (true) {
            sum = (a + b) % M;
            if (b == sum && b == 1)
                break;
            a = b;
            b = sum;
            C++;
        }
        cout << fast_doubling(fast_doubling(N, C).first, M).first << "\n";
    }
    return 0;
}