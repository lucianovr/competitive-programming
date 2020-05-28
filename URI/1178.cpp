#include <cstdlib>
#include <iomanip>
#include <iostream>

using namespace std;

int main() {
    double x, n[101];

    cout << fixed << setprecision(4);

    cin >> x;
    for (int i = 0; i < 100; i++) {
        n[i] = x;
        x = x / 2;
        cout << "N[" << i << "] = " << n[i] << endl;
    }
    // system("PAUSE");
    return 0;
}
