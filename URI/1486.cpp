#include <stdio.h>

int main() {
    int P, N, C, V[1001], palitos, aux, i, j;

    while (scanf("%d%d%d", &P, &N, &C) && (P + N + C)) {
        palitos = 0;
        for (j = 0; j < P; j++)
            V[j] = 0;

        for (i = 0; i < N; i++)
            for (j = 0; j < P; j++) {
                scanf("%d", &aux);
                if (aux == 1)
                    V[j]++;
                else if (aux == 0) {
                    if (V[j] >= C)
                        palitos++;
                    V[j] = 0;
                }
                if (i == N - 1 && aux != 0) {
                    if (V[j] >= C)
                        palitos++;
                    V[j] = 0;
                }
            }
        printf("%d\n", palitos);
    }

    return 0;
}
