#include <stdio.h>
using namespace std;
int M[301][301], L, C, i, j, a, b, aux, cont, menor, linha, coluna;
bool flag;

int main() {
    while (scanf("%d%d", &L, &C) != EOF) {
        for (i = 0; i < L; i++)
            for (j = 0; j < C; j++) {
                scanf("%d", &M[i][j]);
                if (M[i][j] == 1) {
                    a = i;
                    b = j;
                }
            }
        cont = 0;
        if (a != 0) {
            cont++;
            for (j = 0; j < C; j++) {
                aux = M[0][j];     // primeira linha
                M[0][j] = M[a][j]; //  M[a][j] eh a linha onde esta o '1'
                M[a][j] = aux;
            }
        }
        if (b != 0) {
            cont++;
            for (i = 0; i < L; i++) {
                aux = M[i][0];     // primeira coluna
                M[i][0] = M[i][b]; // M[i][b] eh a coluna onde esta o '1'
                M[i][b] = aux;
            }
        }

        int menor, coluna;
        for (j = 1; j < C; j++) {
            menor = M[0][j];
            for (int k = j + 1; k < C; k++)
                if (M[0][k] < menor) {
                    menor = M[0][k];
                    coluna = k;
                }
            if (menor != M[0][j]) {
                cont++;
                for (i = 0; i < L; i++) {
                    aux = M[i][j];
                    M[i][j] = M[i][coluna];
                    M[i][coluna] = aux;
                }
            }
        }

        for (i = 1; i < L; i++) {
            menor = M[i][0];
            for (int k = i + 1; k < L; k++)
                if (M[k][0] < menor) {
                    menor = M[k][0];
                    linha = k;
                }
            if (menor != M[i][0]) {
                cont++;
                for (j = 0; j < C; j++) {
                    aux = M[i][j];
                    M[i][j] = M[linha][j];
                    M[linha][j] = aux;
                }
            }
        }

        flag = true;
        for (i = 0; i < L; i++) {
            if (!flag)
                break;
            for (j = 0; j < C - 1; j++)
                if (M[i][j] != (M[i][j + 1] - 1)) {
                    printf("*\n");
                    flag = false;
                    break;
                }
        }

        if (flag)
            printf("%d\n", cont);
    }
    return 0;
}
