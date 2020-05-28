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
    string s;

    map<string, int> mapa;

    mapa["---"] = 0;
    mapa["--*"] = 1;
    mapa["-*-"] = 2;
    mapa["-**"] = 3;
    mapa["*--"] = 4;
    mapa["*-*"] = 5;
    mapa["**-"] = 6;
    mapa["***"] = 7;

    int sum = 0;

    while (getline(cin, s)) {
        if (s == "caw caw") {
            cout << sum << "\n";
            sum = 0;
        } else
            sum += mapa[s];
    }

    return 0;
}