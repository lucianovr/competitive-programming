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

struct point {
    double x, y;
    point(double x = 0, double y = 0) : x(x), y(y) {}
    void read() { scanf("%lf %lf", &x, &y); }

    point operator-(point q) { return point(x - q.x, y - q.y); }
    double operator%(point q) { return x * q.y - y * q.x; }
};

double abs(point q) { return hypot(q.x, q.y); }
point P[110];

// d = |(i-j) x (i-k) | / |(i-j)|

int main() {

    int n;
    point a;
    while (scanf("%d", &n) && n) {
        rep(i, 0, n) {
            a.read();
            P[i] = a;
        }
        int sgn;
        double resp = 10000, dist, E, D;

        rep(i, 0, n - 1) rep(j, i + 1, n) {
            D = E = 0;
            rep(k, 0, n) {
                if (k != i && k != j) {
                    dist = (P[i] - P[j]) % (P[i] - P[k]) / abs(P[i] - P[j]);
                    if (cmp(dist) >= 0)
                        D += dist;
                    else
                        E += dist;
                }
            }
            resp = min(resp, fabs(E + D));
        }

        printf("%.3lf\n", resp);
    }
    return 0;
}
