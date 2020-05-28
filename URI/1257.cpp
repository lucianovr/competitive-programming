#include <stdio.h>
#include <string.h>
int main() {

    int N, i, m, M, tam, s;
    char text[55];

    scanf("%d", &N);
    for (int n = 0; n < N; n++) {
        s = 0;
        scanf("%d\n", &M);
        for (m = 0; m < M; m++) {
            scanf("%s", text);
            tam = strlen(text);
            for (i = 0; i < tam; i++)
                s += text[i] - 'A' + i + m;
        }
        printf("%d\n", s);
    }
    return 0;
}
