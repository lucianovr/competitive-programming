#include <iostream>
#include <stdio.h>
using namespace std;

int main() {
    int N, L, C, K, i, j, A[100][100], B[100][100], v, nv;
    while (scanf("%d%d%d%d", &N, &L, &C, &K) && N + L + C + K) {
        for (i = 0; i < L; i++)
            for (j = 0; j < C; j++) {
                scanf("%d", &A[i][j]);
                B[i][j] = A[i][j];
            }
        while (K--) {
            for (i = 0; i < L; i++)
                for (j = 0; j < C; j++) {
                    v = B[i][j];
                    nv = (v + 1) % N;
                    if (j + 1 < C && B[i][j + 1] == nv)
                        A[i][j + 1] = v;
                    if (j - 1 >= 0 && B[i][j - 1] == nv)
                        A[i][j - 1] = v;
                    if (i + 1 < L && B[i + 1][j] == nv)
                        A[i + 1][j] = v;
                    if (i - 1 >= 0 && B[i - 1][j] == nv)
                        A[i - 1][j] = v;
                }
            for (i = 0; i < L; i++)
                for (j = 0; j < C; j++)
                    B[i][j] = A[i][j];
        }
        for (i = 0; i < L; i++) {
            printf("%d", A[i][0]);
            for (j = 1; j < C; j++)
                printf(" %d", A[i][j]);
            printf("\n");
        }
    }

    // system("PAUSE");
    return 0;
}
