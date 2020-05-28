#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;

int main() {
    int n, j, t;
    double p;

    cin >> t;
    cout << fixed << setprecision(4);
    while (t--) {
        double resp = 0.0;
        cin >> n >> p >> j;
        for (int i = 0; i < 10000; i += n) {
            resp += pow((1 - p), i) * p;
        }

        double P = 1 - p;

        if (j == 1)
            cout << resp << endl;
        else {
            cout << resp * pow(P, j - 1) << endl;
        }
    }
    return 0;
}