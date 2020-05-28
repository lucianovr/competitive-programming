#include <algorithm>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <stack>
#include <utility>
#include <vector>
using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define rep(i, a, b) for (int i = a; i < b; i++)
#define tr(it, S) for (typeof(S.begin()) it = S.begin(); it != S.end(); it++)
#define all(S) S.begin(), S.end()
#define STD std::ios::sync_with_stdio(false)
const double pi = 3.141592653589793238462643383279;

int main() {

    double a;

    cout << fixed << setprecision(3);
    while (cin >> a) {
        double a1 = 2.0 * (a * a / 2.0 - a * a * (cos(pi / 6.0) * sin(pi / 6.0) / 2.0 + pi / 12.0));

        double a2 = 4 * (a * a * (1.0 - pi / 4) - 2 * a1);

        a1 = 4 * a1;

        double a3 = a * a - a1 - a2;

        cout << a3 << " " << a2 << " " << a1 << endl;
    }
    return 0;
}
