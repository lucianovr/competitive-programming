#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define debug(x) cout << #x << " = " << x << "\n";
#define all(v) v.begin(), v.end()
#define clear(v) memset(v, 0, sizeof v)
#define initpd(v) memset(v, -1, sizeof v)
#define pb push_back

inline int cmp(double x, double y = 0, double tol = 1e-9) { return ((x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1); }

int main() {
    string s;

    getline(cin, s);
    int size = s.size();

    int p = 1;
    int i = 0;
    while (i < size && s[i] != 'p') {
        cout << s[i];
        i++;
    }

    for (; i < size; i++) {
        // if(s[i] == ' ') cout << ' ';

        if (p == 1) {
            if (s[i] == ' ')
                cout << ' ';
            else
                p = 0;
        } else if (p == 0) {
            cout << s[i];
            p = 1;
        }
    }
    cout << "\n";

    return 0;
}
