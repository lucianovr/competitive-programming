#include <stdio.h>
using namespace std;

bool m[1001][1001];

int main() {
    int nvertices, nrelacoes, k, I, J, nconexoes[10001], a, b, cont;
    bool flag, f;

    while (scanf("%d%d%d", &nvertices, &nrelacoes, &k) != EOF) {
        for (I = 1; I <= nvertices; I++) {
            nconexoes[I] = 0;
            for (J = 1; J <= nvertices; J++)
                m[I][J] = false;
        }

        for (I = 0; I < nrelacoes; I++) {
            scanf("%d%d", &a, &b);
            m[a][b] = true;
            m[b][a] = true;
            nconexoes[a]++;
            nconexoes[b]++;
        }
        flag = true;

        while (flag) {
            flag = false;
            for (I = 1; I < nvertices; I++)
                if (nconexoes[I] && nconexoes[I] < k) {
                    flag = true;
                    nconexoes[I] = 0;
                    for (J = 1; J <= nvertices; J++)
                        if (m[I][J]) {
                            m[I][J] = false;
                            m[J][I] = false;
                            nconexoes[J]--;
                        }
                }
        }
        f = true;
        for (I = 1; I <= nvertices; I++)
            if (nconexoes[I] >= k) {
                f = false;
                printf("%d", I);
                for (J = I + 1; J <= nvertices; J++) {
                    if (nconexoes[J] >= k)
                        printf(" %d", J);
                }
                break;
            }

        if (f)
            printf("0");
        printf("\n");
    }
    return 0;
}
