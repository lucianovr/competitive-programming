#include <algorithm>
#include <cstdlib>
#include <math.h>
#include <stdio.h>
#include <utility>
#include <vector>
using namespace std;
typedef long long int lli;
typedef pair<lli, lli> ii;
typedef vector<ii> vii;
#define rep(i, a, b) for (int _i = a, __i = b, i = _i; i < __i; i++)
#define Rep(i, a) rep(i, 0, a)
#define all(S) S.begin(), S.end()
#define pb push_back

lli P, Q, sqrtP, sqrtQ, sqrtQ2, sqrtP2;
vector<ii> R; // raiz

void simpleX() {
    if (Q < 0)
        return;
    lli x;

    // (x+y)y = 0, 	(x-y)x = Q
    x = sqrtQ;
    R.pb(ii(x, 0LL));
    R.pb(ii(-x, 0LL));
    // if ( y = -x)  (x - x)(-x) = 0,  (x - - x)x = Q -> (2x)x = Q
    x = sqrtQ2;
    R.pb(ii(x, -x));
    R.pb(ii(-x, x));
}

void simpleY() {
    if (P < 0)
        return;
    lli y;
    // (x+y)y = P, 	(x-y)x = 0
    // x = 0
    y = sqrtP;
    R.pb(ii(0LL, y));
    R.pb(ii(0LL, -y));
    // x = y -> (y+y)y = P
    y = sqrtP2;
    R.pb(ii(y, y));
    R.pb(ii(-y, -y));
}

void eq() {
    lli A, B, C, Delta, t1, t2, x, y;

    A = 2LL;
    B = -3 * Q - P;
    C = Q * Q;
    Delta = B * B - 4 * A * C;

    if (Delta < 0)
        return;
    t1 = (-B + sqrt(Delta)) / (2 * A);

    t2 = (-B - sqrt(Delta)) / (2 * A);

    if (t1 >= 0) {
        x = sqrt(t1);
        if (x > 0) {
            y = x - Q / x;
            R.pb(ii(x, y));
            x = -x;
            y = x - Q / x;
            R.pb(ii(x, y));
        }
    }

    if (t2 >= 0) {
        x = sqrt(t2);
        if (x > 0) {
            y = x - Q / x;
            R.pb(ii(x, y));
            x = -x;
            y = x - Q / x;
            R.pb(ii(x, y));
        }
    }
}

bool check(lli x, lli y) {
    if (x >= y) {
        if ((x + y) * y == P && (x - y) * x == Q)
            return true;
    }
    return false;
}

int main() {
    int ct;
    scanf("%d", &ct);
    Rep(i, ct) {
        printf("Case %d:\n", i + 1);

        scanf("%lld %lld", &P, &Q);

        if (P >= 0LL) {
            sqrtP = sqrt(P);
            sqrtP2 = sqrt(P / 2LL);
        }
        if (Q >= 0LL) {
            sqrtQ = sqrt(Q);
            sqrtQ2 = sqrt(Q / 2LL);
        }

        R.clear();
        if (P == 0LL && Q == 0LL) {
            printf("0 0\n");
            continue;
        }
        if (P == 0LL)
            simpleX();
        else if (Q == 0LL)
            simpleY();
        else
            eq();

        sort(all(R));

        bool flag = true;
        Rep(j, R.size()) {
            if (check(R[j].first, R[j].second)) {
                printf("%lld %lld\n", R[j].first, R[j].second);
                flag = false;
                break;
            }
        }

        if (flag)
            printf("Impossible.\n");
    }
    return 0;
}