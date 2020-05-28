#include <cmath>
#include <cstdlib>
#include <iostream>
using namespace std;

int main() {
    double H, C, R1, R2, D;

    while (cin >> H >> C >> R1 >> R2 && H + C + R1 + R2) {
        if (C < 2 * R1 || C < 2 * R2 || H < 2 * R1 || H < 2 * R2)
            cout << "N\n";
        else if (C - R1 - R2 < 0 || H - R1 - R2 < 0)
            cout << "N\n";
        else {
            D = pow(H - R1 - R2, 2) + pow(C - R1 - R2, 2);
            D = sqrt(D);
            if (D >= R1 + R2)
                cout << "S\n";
            else
                cout << "N\n";
        }
    }

    return 0;
}
