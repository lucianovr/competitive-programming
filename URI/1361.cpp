#include <math.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int compare(const void *a, const void *b) { return (abs(*(int *)a) - abs(*(int *)b)); }

int main() {

    int T, N, V[500001], i, a, b, cont;

    scanf("%d", &T);
    while (T--) {
        cont = 0;
        scanf("%d", &N);
        for (i = 0; i < N; i++)
            scanf("%d", &V[i]);
        qsort(V, N, sizeof(int), compare);

        V[0] > 0 ? a = 1 : a = 0;
        for (i = 1; i < N; i++) {
            V[i] > 0 ? b = 1 : b = 0;
            cont += a ^ b;
            a = b;
        }
        printf("%d\n", cont + 1);
    }

    return 0;
}
