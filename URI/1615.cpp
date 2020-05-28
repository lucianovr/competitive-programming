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

struct candidato {
    int votos, id;
};

bool comp(candidato a, candidato b) { return a.votos > b.votos; }

int main() {
    int t, n, m, x;
    candidato v[11];

    scanf("%d", &t);
    while (t--) {

        scanf("%d %d", &n, &m);
        rep(i, 0, n) {
            v[i].votos = 0;
            v[i].id = i;
        }

        rep(i, 0, m) {
            scanf("%d", &x);
            v[x - 1].votos++;
        }

        sort(v, v + n, comp);

        double percent = (double(v[0].votos)) / ((double)(m)) * 100.0;
        if (percent > 50.0)
            printf("%d\n", v[0].id + 1);
        else
            printf("-1\n");
    }
}
