#include <stdio.h>

int main() {

    int v[10001], i, j, n, r;

    while (scanf("%d%d", &n, &r) != EOF) {
        if (n != r)
            for (i = 1; i <= n; i++)
                v[i] = 1;

        for (i = 0; i < r; i++) {
            scanf("%d", &j);
            v[j] = 0;
        }

        if (n == r)
            printf("*");
        else
            for (i = 1; i <= n; i++)
                if (v[i])
                    printf("%d ", i);
        printf("\n");
    }
    return 0;
}
