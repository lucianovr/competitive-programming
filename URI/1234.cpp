#include <cstdlib>
#include <cstring>
#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

int main() {
    char frase[52];
    int i, j, tam;

    while (cin.getline(frase, 52)) {

        tam = strlen(frase);
        for (i = 0; i < tam && frase[i] == ' '; i++) {
        }
        // i = primeira letra
        j = 0;
        for (i = i; i < tam; i++) {
            if ((frase[i] >= 'a' && frase[i] <= 'z') || (frase[i] >= 'A' && frase[i] <= 'Z')) {
                if (j % 2 == 0)
                    frase[i] = toupper(frase[i]);
                else
                    frase[i] = tolower(frase[i]);
                j++;
            } // if
        }     // for
        cout << frase << endl;
    } // while
    // system("PAUSE");
    return 0;
}