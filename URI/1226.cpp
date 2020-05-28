#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i(a); i < (b); i++)

#define ALL(c) c.begin(), c.end()
#define UNIQUE(c)                                                                                                      \
    { sort(ALL(c); (c).resize( unique(ALL(c))-c.begin() );                                               \
    }
#define pb push_back
#define sz size()
#define D(x)                                                                                                           \
    if (1)                                                                                                             \
        cout << __LINE__ << " " << #x " = " << (x) << endl;

typedef pair<int, int> ii;
typedef unsigned long long ll;

const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;

string A;
int szA;
ll pd[30][2][2];
int calc[30][2][2];

ll s(int pos, int prefix, int u) {
    if (pos == szA)
        return 1;
    if (calc[pos][prefix][u] == 1)
        return pd[pos][prefix][u];

    ll ret = 0;

    if (prefix == 0) {
        for (int d = 0; d <= 9; d++) {
            if (d == 4)
                continue;
            if (u == 1 && d == 3)
                continue;
            ret += s(pos + 1, 0, (d == 1 ? 1 : 0));
        }
    } else {
        for (int d = 0; d < (A[pos] - '0'); d++) {
            if (d == 4)
                continue;
            if (u == 1 && d == 3)
                continue;
            ret += s(pos + 1, 0, (d == 1 ? 1 : 0));
        }
        int d = (A[pos] - '0');
        if (d == 4 || d == 3 && u == 1) {
        } // faz nada
        else {
            ret += s(pos + 1, 1, (d == 1 ? 1 : 0));
        }
    }
    calc[pos][prefix][u] = 1;
    return pd[pos][prefix][u] = ret;
}

int main() {
    ll target, lo, hi, ans;
    while (cin >> target) {
        lo = 0;
        hi = 9330720600916705820;
        while (lo < hi) {
            ll mid = lo + (hi - lo) / 2;

            ll aux = mid;
            A = "";
            while (aux) {
                A += (char)((aux % 10) + '0');
                aux /= 10;
            }
            reverse(ALL(A));
            //			D(A);

            szA = A.size();

            memset(calc, 0, sizeof calc);
            ll ret = s(0, 1, 0) - 1;

            if (ret >= target) {
                ans = mid;
                hi = mid;
            } else
                lo = mid + 1;
        }
        cout << lo << "\n";
    }
    return 0;
}
