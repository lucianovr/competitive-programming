#include <cstdlib>
#include <iostream>

using namespace std;

int main() {
    float v[6];
    short cont = 0;

    for (int i = 0; i < 6; i++) {
        cin >> v[i];
        if (v[i] > 0)
            cont++;
    }
    cout << cont << " valores positivos\n";

    // system("PAUSE");
    return EXIT_SUCCESS;
}