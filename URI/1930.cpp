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
    int a, b, c, d;

    cin >> a >> b >> c >> d;

    cout << a + b + c + d - 3 << "\n";

    return 0;
}
