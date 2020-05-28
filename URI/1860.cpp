#include <bits/stdc++.h>
using namespace std;
#define f(i, a, b) for (int i = (a); i < (b); i++)
#define all(c) (c).begin(), (c).end()
#define F first
#define S second
#define debug(x) cout << __LINE__ << ": " << #x << " = " << x << endl;
#define debug2(x, y) cout << #x << " = " << x << "  " << #y << " = " << y << endl;
#define pb push_back
#define mp make_pair

const int INF = 0x3f3f3f3f;
const long long LINF = ((1LL) << 60);
const double EPS = 1e-9;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vector<int>> vvi;

const int NN = 50000 + 10;
double X[NN], Y[NN];
int N;

double dist(double x) {
    double ma_dist = 0;
    for (int i = 0; i < N; i++) {
        ma_dist = max(ma_dist, hypot(x - X[i], 0 - Y[i]));
    }
    return ma_dist;
}

double solve(double lo, double hi) {
    while (fabs(lo - hi) > EPS) {
        double x1 = lo + (hi - lo) / 3.0;
        double x2 = hi - (hi - lo) / 3.0;

        if (dist(x1) < dist(x2)) {
            hi = x2;
        } else
            lo = x1;
    }
    return lo;
}

int main() {
    double lenght;

    while (scanf("%d %lf", &N, &lenght) == 2) {
        for (int i = 0; i < N; i++)
            scanf("%lf %lf", X + i, Y + i);
        double x = solve(0, lenght);

        printf("%.2lf %.2lf\n", x, dist(x));
    }

    return 0;
}
