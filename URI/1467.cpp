#include <stdio.h>

int main() {

    int a, b, c;

    while (scanf("%d%d%d", &a, &b, &c) != EOF) {

        if (a == b && a == c)
            printf("*");
        else if (a == b)
            printf("C");
        else if (b == c)
            printf("A");
        else if (a == c)
            printf("B");
        printf("\n");
    }
    return 0;
}
