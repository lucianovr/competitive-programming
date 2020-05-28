#include <stdio.h>

int c, B[100000], A[100000], N; // global

void conta_e_intercala(int p, int q, int r) {
    int i, j;

    for (i = p; i <= q; i++)
        B[i] = A[i];
    for (j = q + 1; j <= r; j++)
        B[r + q + 1 - j] = A[j];
    i = p;
    j = r;
    for (int k = p; k <= r; k++)
        if (B[i] <= B[j]) {
            A[k] = B[i];
            i++;
        } else {
            A[k] = B[j];
            j--;
            c = c + (q - i + 1);
        }
    return;
}

void conta_e_ordena(int p, int r) {
    int q;

    if (p >= r)
        return;
    else {
        q = (p + r) / 2;
        conta_e_ordena(p, q);
        conta_e_ordena(q + 1, r);
        conta_e_intercala(p, q, r);
    }
}

int main() {

    while (scanf("%d", &N) && N) {
        for (int n = 0; n < N; n++)
            scanf("%d", &A[n]);
        c = 0;
        conta_e_ordena(0, N - 1);
        if (c % 2)
            printf("Marcelo\n");
        else
            printf("Carlos\n");
    }
    return 0;
}
