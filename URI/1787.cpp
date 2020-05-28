#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define rep(i, a, b) for (int i(a); i < (b); i++)
#define debug(x) cout << #x << " = " << x << "\n";

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef unsigned long long ll;

bool ispowerof2(ll x) {
    int cnt = 0;
    rep(i, 0, 32) if (x & 1 << i) cnt++;
    return cnt == 1;
}

bool isGreater(ll a, ll b, ll c) { return a > max(b, c); }

int main() {
    int U, R, I, n;
    ll u, r, i;

    while (scanf("%d", &n) && n) {
        U = R = I = 0;
        while (n--) {
            scanf("%lld %lld %lld", &u, &r, &i);
            if (ispowerof2(u)) {
                U++;
                if (isGreater(u, r, i))
                    U++;
            }

            if (ispowerof2(r)) {
                R++;
                if (isGreater(r, u, i))
                    R++;
            }

            if (ispowerof2(i)) {
                I++;
                if (isGreater(i, r, u))
                    I++;
            }
        }
        if (isGreater(U, R, I))
            printf("Uilton\n");
        else if (isGreater(R, I, U))
            printf("Rita\n");
        else if (isGreater(I, R, U))
            printf("Ingred\n");
        else
            printf("URI\n");
    }
    return 0;
}
