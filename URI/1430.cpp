#include <cstdlib>
#include <iostream>
#include <map>
#include <stdio.h>
#include <string.h>

using namespace std;

int main() {
    char seq[205];
    int cond, cont, i, tam;
    float soma;

    map<char, float> mapa;
    mapa['W'] = 1;
    mapa['H'] = 0.5;
    mapa['Q'] = 0.25;
    mapa['E'] = 0.125;
    mapa['S'] = 0.0625;
    mapa['T'] = 0.03125;
    mapa['X'] = 0.015625;

    while (scanf("%s", seq) && seq[0] != '*') {
        soma = 0.0;
        cont = 0;
        tam = strlen(seq);
        for (i = 0; i < tam; i++) {
            if (seq[i] != '/') {
                while (seq[i] != '/') {
                    soma += mapa[seq[i]];
                    i++;
                }
                if (soma == 1)
                    cont++;
                soma = 0.0;
            }
        }
        printf("%d\n", cont);
    }
    // system("PAUSE");
    return 0;
}
