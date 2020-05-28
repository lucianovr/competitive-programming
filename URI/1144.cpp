#include <cstdlib>
#include <iostream>

using namespace std;

int main() {
    int n, i, a = 1, b = 1, c = 1;

    cin >> n;
    for (i = 0; i < n; i++) {
        b = a * a;
        c = b * a;
        cout << a << " " << b << " " << c << endl;
        cout << a << " " << b + 1 << " " << c + 1 << endl;
        a++;
    }

    // system("PAUSE");
    return 0;
}
