#include <cmath>
#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
    int x, y;

    while (cin >> x >> y && (x != y)) {
        if (x > y)
            cout << "Decrescente\n";
        else
            cout << "Crescente\n";
    }

    // system("PAUSE");
    return EXIT_SUCCESS;
}
