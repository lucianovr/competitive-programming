#include <algorithm>
#include <stdio.h>
#define MAX 10001
using namespace std;

int main() {

    int v[MAX], A, C, i, aux, soma;

    while (scanf("%d%d", &A, &C) && A + C) {
        for (i = 0; i < C; i++) {
            scanf("%d", &aux);
            v[i] = A - aux;
        }
        soma = max(v[0], v[1]);

        for (i = 1; i < C - 1; i++)
            if (v[i] < v[i + 1])
                soma += (v[i + 1] - v[i]);

        printf("%d\n", soma);
    }
    return 0;
}
