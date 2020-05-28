#include <cstdlib>
#include <iomanip>
#include <iostream>
using namespace std;
int main() {

    float s = 0;

    for (float i = 1; i <= 100; i++)
        s = s + 1 / i;

    cout << fixed << setprecision(2);

    cout << s << endl;
    system("PAUSE");
    return 0;
}
