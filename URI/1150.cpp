#include <bits/stdc++.h>
using namespace std;
#define pi 3.1415926535897932384626433832795028841971693993751058209
#define rep(a, b, n) for (int a = b; a < n; a++)

typedef pair<int, int> ii;
typedef vector<ii> vii;

int main() {
    int x, z, sum, cnt;
    sum = cnt = 0;

    cin >> x;
    cin >> z;
    while (z <= x)
        cin >> z;

    while (sum <= z) {
        sum += x;
        x++;
        cnt++;
    }
    cout << cnt << "\n";
    return 0;
}
