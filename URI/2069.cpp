#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i(a); i < (b); i++)
#define all(c) (c).begin(), (c).end()
#define fst first
#define snd second
#define db(x) cerr << __LINE__ << ": " << #x << " = " << x << endl

#define pb push_back
#define mp make_pair

const int INF = 0x3f3f3f3f;
typedef long long ll;
typedef pair<int, int> ii;

int main() {
#ifndef ONLINE_JUDGE
    // freopen("_in.txt", "r", stdin);
    // freopen("_out.txt", "w", stdout);
#endif

    ll A, B;
    while (scanf("%lld %lld", &A, &B) > 0) {
        ll g = __gcd(A, B);

        ll f = 2;
        ll d = 1;
        while (f * f <= g) {
            if (g % f == 0) {
                int e = 1;
                g /= f;
                while (g % f == 0) {
                    g /= f;
                    e++;
                }
                if (e % 2 == 1)
                    e++;
                e = e / 2;
                while (e--)
                    d *= f;
            }
            f++;
        }
        if (g > 1) {
            int e = 1;
            d *= g;
        }
        printf("%lld\n", d);
    }
    return 0;
}
