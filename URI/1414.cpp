#include <stdio.h>

int main() {
    int ntimes, njogos, pontos, soma, maxpontos;
    char nometime[12];

    while (scanf("%d%d", &ntimes, &njogos) && ntimes + njogos) {
        maxpontos = njogos * 3;
        soma = 0;
        for (int i = 0; i < ntimes; i++) {
            scanf("%s%d", nometime, &pontos);
            soma += pontos;
        }
        printf("%d\n", maxpontos - soma);
    }
    return 0;
}
