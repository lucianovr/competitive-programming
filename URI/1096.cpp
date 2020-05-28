#include <cstdlib>
#include <iostream>

using namespace std;

int main() {
    int i = 1, j = 8, cont = 0;

    while (i <= 9) {
        j = j - 1;
        cout << "I=" << i << " J=" << j << endl;

        if (j == 5)
            j = 8;
        cont++;
        if (cont % 3 == 0)
            i = i + 2;
    }

    // system("PAUSE");
    return EXIT_SUCCESS;
}
