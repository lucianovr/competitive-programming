#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <string.h>
#include <string>
#include <utility>
#include <vector>
using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define rep(i, n) for (int i = 0; i < (n); i = i + 1)
#define tr(it, S) for (typeof(S.begin()) it = S.begin(); it != S.end(); it++)
#define all(S) (S).begin(), (S).end()
#define setar(S, x) memset(S, x, sizeof(S))
#define pb push_back
#define sz size()

int main() {
    const double psi = sin(108 * M_PI / 180) / sin(63 * M_PI / 180);
    double x;
    cout << fixed << setprecision(10);

    while (cin >> x) {
        cout << x * psi << endl;
    }
    return 0;
}
