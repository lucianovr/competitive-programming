#include <cstdlib>
#include <iostream>

using namespace std;

int main() {
    int i, f;

    cin >> i >> f;

    if (f > i)
        cout << "O JOGO DUROU " << f - i << " HORA(S)\n";
    else
        cout << "O JOGO DUROU " << (24 - i) + f << " HORA(S)\n";

    // system("PAUSE");
    return EXIT_SUCCESS;
}
