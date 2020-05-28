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

int N;
int v[50];
ll pd[50][50];

ll S(int i, int j) {
    if (i > j)
        return 1;
    if ((j - i + 1) % 3 != 0)
        return 0;

    ll &ret = pd[i][j];
    if (ret != -1)
        return ret;

    ret = 0;
    for (int k1 = i + 1; k1 < j; k1++) {
        for (int k2 = k1 + 1; k2 <= j; k2++) {
            if (v[i] + v[k1] + v[k2] >= 2) {
                ret += S(i + 1, k1 - 1) * S(k1 + 1, k2 - 1) * S(k2 + 1, j);
            }
        }
    }
    return ret;
}

int main() {
    int t;
    scanf("%d", &t);
    for (int caso = 1; caso <= t; caso++) {
        scanf("%d", &N);
        char ch;
        rep(i, 0, N) {
            scanf(" %c", &ch);
            v[i] = (ch == 'B' ? 1 : 0);
        }
        memset(pd, -1, sizeof pd);
        ll ret = S(0, N - 1);
        printf("Case %d: %lld\n", caso, ret);
    }
    return 0;
}
