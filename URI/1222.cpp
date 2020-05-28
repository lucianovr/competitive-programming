#include <math.h>
#include <stdio.h>
#include <string.h>

int main() {
    int N, C;
    char word[72];
    int spc = 1, soma, wsz, i; // soma de caracteres na lina
    float nl, L;               // numero de linhas no total

    while (scanf("%d%f%d", &N, &L, &C) != EOF) {
        soma = 0;
        nl = 0.0;
        scanf("\n");
        for (i = 0; i < N; i++) {
            scanf("%s", word);
            wsz = strlen(word);

            if (soma + wsz == C || soma + wsz + spc == C) {
                soma = 0;
                nl++;
            } else if (soma + wsz + spc < C) {
                soma = soma + wsz + spc;
            } else if (soma + wsz > C) {
                nl++;
                soma = wsz;
                if (soma == C) {
                    soma = 0;
                    nl++;
                } else if (soma < C)
                    soma++;
            }
        }
        if (soma > 0)
            nl++;
        printf("%d\n", (int)ceil(nl / L));
    }

    return 0;
}
