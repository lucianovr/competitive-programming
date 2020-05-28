#include <cstdlib>
#include <iostream>
#include <string.h>

using namespace std;
char aux, frase[1060];
int i, t;

bool verifica(int k) {

    for (i = k + 1; i < t; i++) {
        if (frase[i] == ' ' && i + 1 < t && tolower(frase[i + 1]) != aux)
            return false;
    }
    return true;
}

int main() {
    while (cin.getline(frase, 1060) && frase[0] != '*') {
        t = strlen(frase);
        i = 0;
        while (true) {
            if (isalpha(frase[i])) {
                aux = tolower(frase[i]);
                break;
            }
            i++;
        }

        if (verifica(i))
            cout << "Y\n";
        else
            cout << "N\n";
    }
    // system("PAUSE");
    return 0;
}
