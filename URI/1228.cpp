#include <stdio.h>
#define MAX 25
using namespace std;

int main() {

    int n, largada[MAX], chegada[MAX], pos_id, i, c, aux;
    bool B;

    while (scanf("%d", &n) != EOF) {
        for (i = 1; i <= n; i++)
            scanf("%d", &largada[i]);

        for (i = 1; i <= n; i++) {
            scanf("%d", &pos_id);
            chegada[pos_id] = i; /* crio um vetor invertido, chegada[valor] = i */
        }
        for (i = 1; i <= n; i++)
            largada[i] = chegada[largada[i]]; /*construo um vetor equivalente, q pode ser ordenado e resultar numa
                                                 contagem de trocas*/

        B = true;
        c = 0;
        while (B) {
            B = false;
            for (i = 1; i <= n - 1; i++)
                if (largada[i] > largada[i + 1]) {
                    B = true;
                    aux = largada[i];
                    largada[i] = largada[i + 1];
                    largada[i + 1] = aux;
                    c++;
                }
        }
        printf("%d\n", c);
    }
    return 0;
}
