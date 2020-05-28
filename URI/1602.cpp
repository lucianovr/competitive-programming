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

int v[2000001], acc[2000001];

inline bool primo(int p) {
    if (p == 2)
        return 1;

    if (p % 2 == 0)
        return false;

    for (int i = 3; i * i <= p; i += 2)
        if (p % i == 0)
            return false;
    return true;
}
int main() {
    memset(v, 0, sizeof v);
    rep(j, 1, 2000001) {
        for (int i = j; i < 2000001; i += j) {
            v[i]++;
        }
    }

    rep(i, 2, 2000001) {
        if (primo(v[i]))
            acc[i] = 1;
        acc[i] += acc[i - 1];
    }

    int n;
    while (scanf("%d", &n) == 1) {

        printf("%d\n", acc[n]);
    }

    return 0;
}
