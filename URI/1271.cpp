#include <stdio.h>
using namespace std;
int N, R, Q, ri, rj, g, G[50001], GG[50001];
void Swap(int a, int b) {
    int aux, f = b;
    for (int k = a; k <= (b + a) / 2; k++) {
        aux = G[k];
        G[k] = G[f];
        G[f] = aux;
        f--;
    }
    return;
}

int main() {
    int i, j, caso = 0;

    while (scanf("%d", &N) && N) {
        caso++;
        for (i = 0; i <= N; i++)
            G[i] = i;
        scanf("%d", &R);
        for (i = 0; i < R; i++) {
            scanf("%d%d", &ri, &rj);
            Swap(ri, rj);
        }
        for (i = 1; i <= N; i++)
            GG[G[i]] = i;

        printf("Genome %d\n", caso);
        scanf("%d", &Q);
        for (i = 0; i < Q; i++) {
            scanf("%d", &g);
            printf("%d\n", GG[g]);
        }
    }
    return 0;
}
