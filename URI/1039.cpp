#include <cmath>
#include <cstdlib>
#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
    float r1, x1, y1, r2, x2, y2;

    while (cin >> r1 >> x1 >> y1 >> r2 >> x2 >> y2) {

        if ((r1 > r2) && ((sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2)) + r2 <= r1)))
            cout << "RICO\n";
        else
            cout << "MORTO\n";
    }

    return 0;
}
