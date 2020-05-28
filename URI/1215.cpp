#include <iostream>
#include <map>
#include <stdio.h>
#include <string.h>
using namespace std;

int main() {
    char frase[210];
    string aux;
    map<string, bool> mapa;

    while (scanf("%s", frase) != EOF) {
        int t = strlen(frase);
        aux.clear();
        for (int i = 0; i < t; i++) {
            if (isalpha(frase[i]))
                aux += tolower(frase[i]);
            else if (aux.size()) {
                // cout << aux << endl;
                mapa[aux] = true;
                aux.clear();
            }

            if (i == t - 1 && aux.size()) {
                // cout << aux << endl;
                mapa[aux] = true;
                aux.clear();
            }
        }
    }
    for (map<string, bool>::iterator it = mapa.begin(); it != mapa.end(); it++) {
        cout << it->first << endl;
    }

    return 0;
}
