#include <cstring>
#include <iostream>
using namespace std;

int mdc(int a, int b) {
    if (b == 0)
        return a;
    else
        return mdc(b, a % b);
}

int main() {
    int n, a, b, p;
    string s1, s2;

    cin >> n;
    for (int k = 0; k < n; k++) {
        cin >> s1 >> s2;
        int t = s1.size();

        a = 0;
        p = 1;
        for (int i = t - 1; i >= 0; i--) {
            a += (s1[i] - '0') * p;
            p *= 2;
        }

        t = s2.size();
        b = 0;
        p = 1;
        for (int i = t - 1; i >= 0; i--) {
            b += (s2[i] - '0') * p;
            p *= 2;
        }
        if (mdc(a, b) > 1)
            cout << "Pair #" << k + 1 << ": All you need is love!\n";
        else
            cout << "Pair #" << k + 1 << ": Love is not all you need!\n";
    }
    return 0;
}
