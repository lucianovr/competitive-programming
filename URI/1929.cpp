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

bool f(int c, int b, int a) { return a < b + c; }

int main() {
    int v[4];

    rep(i, 0, 4) cin >> v[i];

    sort(v, v + 4);

    if (f(v[0], v[1], v[2]) || f(v[0], v[2], v[3]) || f(v[0], v[1], v[3]) || f(v[1], v[2], v[3]))
        cout << "S\n";
    else
        cout << "N\n";

    return 0;
}
