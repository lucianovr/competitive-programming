#include <cstdlib>
#include <iostream>
#include <math.h>
using namespace std;

int main() {
    double n, intpart, fracpart;
    int T;

    cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> n;
        n = (sqrt(8.0 * n + 1) - 1.0) / 2.0;
        fracpart = modf(n, &intpart);
        cout << (int)intpart << endl;
    }
    return 0;
}
