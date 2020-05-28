#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < b; i++)
#define mp make_pair
#define pb push_back
#define contains(s, x) (s.find(x) != s.end())

const int oo = 0x3f3f3f3f;
const double EPS = 1e-9;

map<string, int> murder;

int main() {

    string m, k;
    while (cin >> m >> k) {
        //	if (m == "*") break;
        murder[m]++;
        murder[k] = -oo;
    }

    map<string, int>::iterator it;
    cout << "HALL OF MURDERERS\n";
    for (it = murder.begin(); it != murder.end(); it++) {
        if (it->second > 0) {
            cout << it->first << " " << it->second << "\n";
        }
    }

    return 0;
}
