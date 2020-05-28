#include <stdio.h>
#include <string.h>
using namespace std;
char linha[10000];

int main() {

    int numero, tam, cpares, cfem, cmasc, teste = 1, i;
    while (scanf("%d", &numero) != EOF) {
        if (teste != 1)
            printf("\n");
        scanf("\n");
        gets(linha);
        tam = strlen(linha);
        cpares = cfem = cmasc = 0;
        for (i = 0; i < tam - 3; i = i + 5) {
            if ((linha[i] - '0') * 10 + (linha[i + 1] - '0') == numero) {
                cpares++;
                if (linha[i + 3] == 'F')
                    cfem++;
                else
                    cmasc++;
            }
        }
        printf("Caso %d:\n", teste++);
        printf("Pares Iguais: %d\n", cpares);
        printf("F: %d\n", cfem);
        printf("M: %d\n", cmasc);
    }
    return 0;
}
