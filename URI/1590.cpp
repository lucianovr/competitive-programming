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
const double EPS = 1e-10;

int cmp(double x, double y = 0, double tol = EPS) { return ((x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1); }

inline bool cmp_eq(double x, double y) { return cmp(x, y) == 0; }
inline bool cmp_lt(double x, double y) { return cmp(x, y) < 0; }

int dx[] = {0, 0, -1, 1, -1, -1, 1, 1};
int dy[] = {-1, 1, 0, 0, -1, 1, 1, -1};

int N, K;
unsigned int num[42], ans;

void func(unsigned int v, int n, int k) {
    if (k == K) {
        ans = max(ans, v);
    }
    if (n == N)
        return;

    if (ans && k != 0 && v < ans)
        return;

    func(v, n + 1, k);
    if (k == 0)
        func(num[n], n + 1, k + 1);
    else
        func(v & num[n], n + 1, k + 1);
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &N, &K);
        rep(i, 0, N) scanf("%d", &num[i]);
        ans = 0;
        func(0, 0, 0);
        printf("%d\n", ans);
    }
    return 0;
}