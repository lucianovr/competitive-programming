#include <cmath>
#include <iostream>

using namespace std;

int main() {

    double n;
    int tst = 1;

    while (cin >> n && n) {
        cout << "Teste " << tst++ << "\n";
        cout << int(pow(2.0, n) - 1) << "\n\n";
    }

    return 0;
}