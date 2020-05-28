#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, t = 0, d, a, b;

    while (scanf("%d", &n) && n) {
        d = 0;
        printf("Teste %d\n", ++t);
        for (int i = 0; i < n; i++) {
            scanf("%d%d", &a, &b);
            d = a - b + d;
            printf("%d\n", d);
        }
        printf("\n");
    }
    return 0;
}
