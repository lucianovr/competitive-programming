#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <ctype.h>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;
#define f first
#define s second
#define rep(i, n) for (int i = 0; i < (n); i = i + 1)
#define all(S) (S).begin(), (S).end()
#define pb push_back

bool func(vector<int> a, int sz) {
    int r = a[1] - a[0];
    for (int i = 2; i < sz; i++) {
        if ((a[i] - a[i - 1]) != r)
            return false;
    }
    return true;
}

int main() {

    int n, r, x, cont = 0;
    vector<int> pa, val;

    while (cin >> n) {
        cont = 0;
        pa.clear();
        val.clear();
        rep(i, n) {
            cin >> x;
            pa.pb(x);
        }
        if (n <= 2)
            cout << 1 << endl;
        else {
            if (func(pa, n))
                cout << 1 << endl;
            else {
                val.pb(pa[0]);
                val.pb(pa[1]);
                r = pa[1] - pa[0];
                for (int i = 2; i < n; i++) {
                    if ((pa[i] - val.back()) != r) {
                        cont++;
                        val.clear();
                        val.pb(pa[i]);
                        if (i != n - 1)
                            r = pa[i + 1] - val.back();
                    } else
                        val.pb(pa[i]);
                }
                if (val.size() > 0)
                    cont++;
                cout << cont << endl;
            }
        }
    }

    return 0;
}
