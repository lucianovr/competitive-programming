#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;
int main() {

    int i, c, tam;
    char F[5110], atual, spc = ' ';
    bool flag;

    while (cin.getline(F, 5110)) {
        tam = strlen(F);
        atual = tolower(F[0]);
        flag = true;
        c = 0;
        for (i = 1; i < tam; i++) {
            if (F[i] == spc) {
                if (flag && tolower(F[i + 1]) == atual) {
                    flag = false;
                    c++;
                } else if (tolower(F[i + 1]) != atual) {
                    atual = tolower(F[i + 1]);
                    flag = true;
                }
            }
        }
        printf("%d\n", c);
    }

    return 0;
}