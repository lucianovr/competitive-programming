#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i(a); i < (b); i++)
#define debug(x) cout << #x << " = " << x << "\n";

#define ALL(c) c.begin(), c.end()
#define SORT(c) sort(ALL(c))
#define UNIQUE(c)                                                                                                      \
    {                                                                                                                  \
        SORT(c);                                                                                                       \
        (c).resize(unique(ALL(c)) - c.begin());                                                                        \
    }
#define pb push_back
#define sz size()
#define D(x)                                                                                                           \
    if (1)                                                                                                             \
        cout << __LINE__ << " " << #x " = " << (x) << endl;
#define D2(x, y)                                                                                                       \
    if (1)                                                                                                             \
        cout << __LINE__ << " " << #x " = " << (x) << ", " << #y " = " << (y) << endl;

typedef pair<int, int> ii;
typedef vector<int> VI;
typedef vector<ii> VII;
typedef long long LL;

string L;
vector<int> X;
int N, B;

LL pd[100][2][2];
LL S(int pos, int igual, int p) {
    if (pos == N)
        return 1;

    LL &ret = pd[pos][igual][p];

    if (ret != -1)
        return ret;

    ret = 0;

    if (igual == 0)
        for (int d = p; d < B; d++) {
            if (L[d] == 'S') {
                ret += S(pos + 1, igual, 0);
            }
        }
    else {
        for (int d = p; d < X[pos]; d++) {
            if (L[d] == 'S') {
                ret += S(pos + 1, 0, 0);
            }
        }

        if (L[X[pos]] == 'S')
            ret += S(pos + 1, 1, 0);
    }

    return ret;
}

void toArray(LL V, vector<int> &X) {
    X.clear();
    while (V) {
        X.pb(V % B);
        V /= B;
    }
    reverse(X.begin(), X.end());
}

LL solve(LL A, LL B) {
    LL b = 0, a = 0;

    toArray(B, X);
    for (N = 1; N <= X.size(); N++) {
        memset(pd, -1, sizeof pd);
        b += S(0, N == X.size(), 1);
    }

    toArray(A - 1, X);
    for (N = 1; N <= X.size(); N++) {
        memset(pd, -1, sizeof pd);
        a += S(0, N == X.size(), 1);
    }
    return b - a;
}

int main() {

    LL D, H;
    while (scanf("%lld %lld %lld", &D, &H, &B) > 0) {
        if (D == -1)
            break;

        cin >> L;
        printf("%lld\n", solve(D, H));
    }
    return 0;
}
