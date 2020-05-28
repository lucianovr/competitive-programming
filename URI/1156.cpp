#include <cstdlib>
#include <iomanip>
#include <iostream>
using namespace std;
int main() {

    float s = 0, k = 1;

    for (float j = 1; j <= 39; j += 2) {
        s = s + j / k;
        k = k * 2;
    }

    cout << fixed << setprecision(2);
    cout << s << endl;

    system("PAUSE");
    return 0;
}
