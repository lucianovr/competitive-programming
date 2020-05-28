#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(c) (c).begin(), (c).end()
#define F first
#define S second
#define debug(x) cout << __LINE__ << ": " << #x << " = " << x << endl;
#define debug2(x, y) cout << #x << " = " << x << "  " << #y << " = " << y << endl;
#define pb push_back
#define mk make_pair

const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;
typedef long long ll;
typedef pair<int, int> ii;

int N;

double memo[1010][6002];
double dp(int i, int v) {
    if (v <= 0)
        return 1.0;
    if (i == N)
        return 0;

    double &r = memo[i][v];
    if (r > -1)
        return r;

    r = 0;
    for (int d = 1; d < 7; d++) {
        r += (1.0 / 6.0) * dp(i + 1, v - d);
    }
    return r;
}

int main() {
    int V;
    while (cin >> N >> V) {
        for (int i = 0; i <= N + 1; i++)
            for (int j = 0; j <= V + 2; j++)
                memo[i][j] = -1.0;

        double ways = dp(0, V);

        printf("%.4lf\n", ways);
    }
    return 0;
}
