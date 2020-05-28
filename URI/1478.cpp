#include <stdio.h>

int main() {
    int n, m[101][101], i, j, k, I, J, aux = 0;
    ;
    while (scanf("%d", &n) && n) {

        for (j = 0; j < n; j++) {
            k = m[0][j] = j + 1;
            I = 1;
            J = j + 1;
            while (I < n && J < n)
                m[I++][J++] = k;
        }
        for (i = 0; i < n; i++) {
            k = m[i][0] = i + 1;
            I = i + 1;
            J = 1;
            while (I < n && J < n)
                m[I++][J++] = k;
        }

        // printando
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                k = m[i][j];
                if (j == 0) {
                    if (k < 10)
                        printf("  ");
                    else if (k < 100)
                        printf(" ");
                } else if (m[i][j] < 10)
                    printf("   ");
                else if (m[i][j] < 100)
                    printf("  ");
                else
                    printf(" ");
                printf("%d", m[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}
