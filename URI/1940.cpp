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
typedef long long ll;

const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;

int main() {
    int j, r;
    cin >> j >> r;
    int v[j * r + 1];
    int s[j + 1];
    rep(i, 0, j) s[i] = 0;

    int x, maior = -1, idx;
    rep(i, 0, j * r) {
        cin >> x;
        s[i % j] += x;
        if (s[i % j] >= maior)
            maior = s[i % j], idx = i % j;
    }

    cout << idx + 1 << "\n";

    return 0;
}
