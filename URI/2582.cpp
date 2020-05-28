#include <bits/stdc++.h>

#define rep(i, a, b) for (int i = a; i < b; i++)
using namespace std;

const double EPS = 1e-9;

int main() {
    char songs[][100] = {"PROXYCITY",   "P.Y.N.G.", "DNSUEY!", "SERVERS", "HOST!",        "CRIPTONIZE",
                         "OFFLINE DAY", "SALT",     "ANSWER!", "RAR?",    "WIFI ANTENNAS"};

    int n;
    while (cin >> n) {
        for (unsigned int i = 0; i < n; i += 1) {
            int a, b;
            cin >> a >> b;
            cout << songs[a + b] << "\n";
        }
    }
    return 0;
}
