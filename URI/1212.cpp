#include <stdio.h>
#define mod 10

int main() {
    int A, B, C, cont, aux;

    while (scanf("%d%d", &A, &B) && A + B) {
        cont = C = 0;
        if (B > A) {
            aux = A;
            A = B;
            B = aux;
        }
        while (A) {
            if ((A % mod + B % mod + C) > 9) {
                cont++;
                C = 1;
            } else
                C = 0;
            A = A / mod;
            B = B / mod;
        }

        if (cont == 0)
            printf("No carry operation.\n");
        else if (cont == 1)
            printf("1 carry operation.\n");
        else
            printf("%d carry operations.\n", cont);
    }
    return 0;
}
