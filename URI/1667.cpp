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

    //	freopen("htmlout.txt", "w", stdout);

    vector<string> v;
    string w, traces = "--------------------------------------------------------------------------------";
    while (cin >> w) {
        v.pb(w);
    }
    int len = 0;

    for (int i = 0; i < v.size(); i++) {
        if (v[i] == "<br>") {
            cout << "\n";
            len = 0;
        } else if (v[i] == "<hr>") {
            if (len)
                cout << "\n";
            cout << traces << "\n";
            len = 0;
        } else {
            if (len == 0) {
                cout << v[i];
                len = v[i].size();
            } else if (len + 1 + v[i].size() <= 80) {
                cout << " " << v[i];
                len = len + 1 + v[i].size();
            } else {
                cout << "\n";
                cout << v[i];
                len = v[i].size();
            }
        }
    }
    cout << "\n";

    return 0;
}
