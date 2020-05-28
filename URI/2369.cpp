#include <stdio.h>
#include <stdlib.h>

int main() {
    int consumo;
    int preco;
    while (scanf("%d", &consumo) != EOF) {
        if (consumo <= 10)
            preco = 7;

        else if (consumo > 10 && consumo <= 30)
            preco = (consumo - 10) * 1 + 7;

        else if (consumo > 30 && consumo <= 100)
            preco = (consumo - 30) * 2 + 27;

        else if (consumo > 100)
            preco = (consumo - 100) * 5 + 167;

        printf("%d\n", preco);
    }
    return 0;
}
