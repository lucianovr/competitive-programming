#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
    int s = 2002, t;

    do {
        cin >> t;
        if (t == s)
            cout << "Acesso Permitido\n";
        else
            cout << "Senha Invalida\n";
    } while (t != s);

    // system("PAUSE");
    return EXIT_SUCCESS;
}
