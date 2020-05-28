#include <cstdlib>
#include <iostream>

using namespace std;

int main() {
    int x;

    while (cin >> x && x) {

        int s = 0;
        if (x % 2 != 0)
            x++;
        for (int i = 0; i < 5; i++) {
            s += x;
            x += 2;
        }
        cout << s << endl;
    }
    // system("PAUSE");
    return EXIT_SUCCESS;
}