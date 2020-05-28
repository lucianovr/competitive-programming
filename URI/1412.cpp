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
    string in, temp;

    while (cin >> temp && temp != "*") {
        in = "a" + temp + "a";
        vector<int> d;
        rep(i, 1, in.size()) { d.pb((in[i] - in[i - 1] + 26) % 26); }

        int i = 0, j = d.size() - 1, res = 0;
        sort(ALL(d));
        while (i < j) {
            int left = d[i], right = 26 - d[j];

            if (left <= right) {
                d[j] = (d[j] + left) % 26;
                i++;
                if (d[j] == 0)
                    j--;
                res += left;
            } else if (left > right) {
                d[i] -= right;
                j--;
                res += right;
            }
        }

        cout << res << "\n";
    }
    return 0;
}
