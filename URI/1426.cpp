#include <stdio.h>

int main() {

    int T, i, j, mat[10][10];

    scanf("%d", &T);
    for (int t = 0; t < T; t++) {
        for (i = 0; i < 9; i++)
            for (j = 0; j < 9; j++)
                mat[i][j] = 0;

        for (i = 0; i < 9; i += 2)
            for (j = 0; j <= i; j += 2)
                scanf("%d", &mat[i][j]);

        for (j = 1; j <= 7; j += 2)
            mat[8][j] = (mat[6][j - 1] - (mat[8][j - 1] + mat[8][j + 1])) / 2;

        for (i = 7; i > 0; i--)
            for (j = 0; j <= i; j++)
                mat[i][j] = mat[i + 1][j] + mat[i + 1][j + 1];

        for (i = 0; i < 9; i++)
            for (j = 0; j <= i; j++) {
                printf("%d", mat[i][j]);
                if (j != i)
                    printf(" ");
                else
                    printf("\n");
            }
    }
    // system("PAUSE");
    return 0;
}