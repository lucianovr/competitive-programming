#include <cstdlib>
#include <iostream>

using namespace std;

int main() {
    int i = 1, j = 7, cont = 0;

    while (i <= 9) {
        cout << "I=" << i << " J=" << j << endl;
        j = j - 1;
        cont++;

        if (cont % 3 == 0) {

            i = i + 2;
            j = j + 5;
        }
    }

    // system("PAUSE");
    return EXIT_SUCCESS;
}