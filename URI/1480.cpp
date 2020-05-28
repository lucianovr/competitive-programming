#include <cctype>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

int main() {

    int MA[23][33], MD[23][33], MB[23][33], N, M, K, i, j, l, c, adjCob, adjSin;
    int k, dica, cont;
    bool B;
    char casa;
    while (scanf("%d%d%d", &N, &M, &K) && N + M + K) {
        for (i = 0; i <= N + 1; i++)
            for (j = 0; j <= M + 1; j++)
                MA[i][j] = MD[i][j] = MB[i][j] = 0;

        for (i = 1; i <= N; i++)
            for (j = 1; j <= M; j++) {
                scanf("\n");
                scanf("%c", &casa);
                if (casa != '.')
                    MA[i][j] = (casa - '0');
                else
                    MA[i][j] = -1;
            }
        k = K;
        while (k--) {
            scanf("%d%d", &i, &j);
            MD[i][j] = -2;
        }

        for (i = 1; i <= N; i++)
            for (j = 1; j <= M; j++)
                if (MD[i][j] == -2)
                    for (l = i - 1; l <= i + 1; l++)
                        for (c = j - 1; c <= j + 1; c++)
                            if (MD[l][c] != -2)
                                MD[l][c]++;

        B = true;
        while (B) {
            B = false;
            for (i = 1; i <= N; i++)
                for (j = 1; j <= M; j++) {
                    dica = MA[i][j];
                    if (dica >= 0 && MB[i][j] == 0) {
                        adjCob = adjSin = 0;
                        for (l = i - 1; l <= i + 1; l++)
                            for (c = j - 1; c <= j + 1; c++) {
                                if (MA[l][c] == -1)
                                    adjCob++;
                                if (MA[l][c] == -2)
                                    adjSin++;
                            }
                        if (adjCob && adjCob + adjSin == dica) {
                            B = true;
                            MB[i][j] = 1;
                            for (l = i - 1; l <= i + 1; l++)
                                for (c = j - 1; c <= j + 1; c++)
                                    if (MA[l][c] == -1)
                                        MA[l][c] = -2;

                        } else if (adjSin == dica) {
                            MB[i][j] = 1;
                            B = true;
                            for (l = i - 1; l <= i + 1; l++)
                                for (c = j - 1; c <= j + 1; c++)
                                    if (MA[l][c] == -1)
                                        MA[l][c] = MD[l][c];
                        }

                    } // if
                }     // for
        }             // while
        cont = 0;
        for (i = 1; i <= N; i++)
            for (j = 1; j <= M; j++)
                if (MA[i][j] == -2)
                    cont++;

        if (cont == K)
            printf("Possivel\n");
        else
            printf("Impossivel\n");
    }
    return 0;
}
