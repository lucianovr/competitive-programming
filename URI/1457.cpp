#include <stdio.h>
#include <string.h>

int main() {

    unsigned long long int N, F, K, i;
    int T, n;
    char exc[25];
    scanf("%d", &T);
    for (n = 0; n < T; n++) {

        scanf("%llu", &N);
        scanf("%s", exc);
        K = strlen(exc);
        F = N;

        for (i = 1ULL; i <= N; i++)
            if (i * K >= N)
                break;
            else
                F = F * (N - i * K);

        printf("%llu\n", F);
    }

    return 0;
}