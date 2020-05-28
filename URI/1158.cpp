#include <cstdlib>
#include <iostream>

using namespace std;

int main() {
    int n, x, y;

    cin >> n;
    for (int j = 0; j < n; j++) {
        int s = 0;
        cin >> x >> y;
        if (x % 2 == 0)
            x++; // transforma X em impar
        for (int i = 0; i < y; i++) {
            s += x;
            x += 2;
            ; // apenas soma os X's impares
        }
        cout << s << endl;
    }

    // system("PAUSE");
    return EXIT_SUCCESS;
}
