#include <cstdlib>
#include <iostream>

using namespace std;

int main() {
    float a = 0, b = 1, c = 2, d = 3;

    while (a < 2) {
        cout << "I=" << a << " J=" << b << endl;
        cout << "I=" << a << " J=" << c << endl;
        cout << "I=" << a << " J=" << d << endl;
        a += 0.2;
        b += 0.2;
        c += 0.2;
        d += 0.2;
    }
    cout << "I=" << a << " J=" << b << endl;
    cout << "I=" << a << " J=" << c << endl;
    cout << "I=" << a << " J=" << d << endl;

    // system("PAUSE");
    return 0;
}
