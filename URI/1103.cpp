#include <cstdlib>
#include <iostream>
using namespace std;

int main() {
    int x1, y1, x2, y2, h1, h2, dif;

    while (cin >> x1 >> y1 >> x2 >> y2 && (x1 + y1 + x2 + y2)) {
        h1 = x1 * 60 + y1;
        h2 = x2 * 60 + y2;

        dif = h2 - h1;

        if (dif > 0)
            cout << dif << endl;
        else
            cout << 1440 - h1 + h2 << endl;
    }
    // system( "PAUSE");
    return 0;
}