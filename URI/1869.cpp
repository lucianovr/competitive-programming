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
typedef unsigned long long ll;

const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;

string convert(ll num) {
    string s;
    int rest;

    while (num >= 32) {
        rest = num % 32;
        num /= 32;

        if (rest < 10)
            s += char(rest + '0');
        else
            s += (rest - 10 + 'A');
    }

    if (num < 10)
        s += char(num + '0');
    else
        s += char(num - 10 + 'A');

    reverse(ALL(s));
    return s;
}

int main() {
    ll num;
    while (cin >> num && num) {
        string s = convert(num);
        cout << s << "\n";
    }
    cout << 0 << "\n";
    return 0;
}
