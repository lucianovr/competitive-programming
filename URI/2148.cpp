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

ll pd[100][20];

ll S(int s, int d) {
    if (d == 0)
        return (s == 0) * 1LL;

    if (s == 0)
        return 0;

    ll &ans = pd[s][d];
    if (ans != -1)
        return ans;

    ans = 0;
    for (int face = 1; face <= 6; face++) {
        if (s - face >= 0)
            ans += S(s - face, d - 1);
    }
    return ans;
}

int main() {

    //	ios_base::sync_with_stdio(false);

#ifndef ONLINE_JUDGE
    // freopen("_in.txt", "r", stdin);
    // freopen("_out.txt", "w", stdout);
#endif
    int t;
    scanf("%d", &t);
    while (t--) {
        int s, d;
        scanf("%d %d", &s, &d);

        memset(pd, -1, sizeof pd);
        ll qte = S(s, d);
        ll even = 1;
        rep(i, 0, d) even *= 6;

        // db(qte);
        // db(even);
        printf("%.15Lf\n", ((long double)(qte)) / ((long double)(even)));
    }
    return 0;
}
