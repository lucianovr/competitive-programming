#include <cmath>
#include <cstdlib>
#include <iostream>

using namespace std;

int main() {
    double d, vf, vg;

    while (cin >> d >> vf >> vg) {
        double tf = 12 / vf;
        double tg = sqrt(144.0 + d * d) / vg;

        if (tf < tg)
            cout << "N\n";
        else
            cout << "S\n";
    }
    return 0;
}
