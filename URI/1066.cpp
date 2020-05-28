#include <cmath>
#include <cstdlib>
#include <iostream>
using namespace std;

int main() {
    int v[5], cpar = 0, cimp = 0, cpos = 0, cneg = 0;

    for (int i = 0; i < 5; i++) {
        cin >> v[i];
        if (v[i] % 2 == 0)
            cpar++;
        else
            cimp++;
        if (v[i] > 0)
            cpos++;
        else if (v[i] < 0)
            cneg++;
    }
    cout << cpar << " valor(es) par(es)\n";
    cout << cimp << " valor(es) impar(es)\n";
    cout << cpos << " valor(es) positivo(s)\n";
    cout << cneg << " valor(es) negativo(s)\n";

    // system("PAUSE");
    return EXIT_SUCCESS;
}