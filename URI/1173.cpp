#include <cstdlib>
#include <iostream>

using namespace std;

int main() {
    int x, n[11];

    cin >> x;
    for (int i = 0; i < 10; i++) {
        n[i] = x;
        x = x * 2;
        cout << "N[" << i << "] = " << n[i] << endl;
    }
    // system("PAUSE");
    return EXIT_SUCCESS;
}