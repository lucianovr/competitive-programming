#include <stdio.h>
#include <string.h>

int main() {
    int Q;
    char L[110];
    char lamp[110];
    int N, K, M;

    while (scanf("%d%d", &N, &Q) && N != 0 && Q != 0) {
        scanf("%s", lamp);

        while (Q--) {
            scanf("%d%d", &K, &M);

            strcpy(L, lamp);
            int i = 0, t = 1;
            L[i] = (L[i] == 'x' ? 'o' : 'x');
            while (strcmp(L, lamp) != 0) {
                i = (i + K) % N;
                L[i] = (L[i] == 'x' ? 'o' : 'x');
                t++;
            }

            M = M % t;
            i = 0;
            while (M--) {
                L[i] = (L[i] == 'x' ? 'o' : 'x');
                i = (i + K) % N;
            }
            printf("%s\n", L);
        }
    }
    return 0;
}