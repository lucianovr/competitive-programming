#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
char fruta[10000], c;
int main() {
    double ndias, preco, somapreco = 0, somacont = 0;

    int spc, i, lenfruta;

    cin >> ndias;

    for (i = 0; i < ndias; i++) {
        cin >> preco;
        spc = 0;
        somapreco += preco;
        scanf("\n");
        gets(fruta);
        lenfruta = strlen(fruta);
        for (int j = 0; j < lenfruta; j++)
            if (fruta[j] == ' ')
                spc++;

        cout << "day " << i + 1 << ": " << spc + 1 << " kg\n";
        somacont += spc + 1;
    }
    cout << fixed << setprecision(2);
    cout << somacont / ndias << " kg by day\n";
    cout << "R$ " << somapreco / ndias << " by day\n";
    // system("PAUSE");
    return 0;
}
