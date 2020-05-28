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

int fermat[] = {3, 5, 17, 257, 65537};

int main() {
    int t, n;

    scanf("%d", &t);
    while (t--) {

        scanf("%d", &n);
        while (n % 2 == 0)
            n /= 2;
        if (n == 1)
            printf("Yes\n");
        else {
            rep(i, 0, 5) {
                if (n % fermat[i] == 0) {
                    n /= fermat[i];
                }
            }
            if (n == 1)
                printf("Yes\n");
            else
                printf("No\n");
        }
    }
    return 0;
}
