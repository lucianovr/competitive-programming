#include <stdio.h>

#define MAX 105

using namespace std;

int main()

{

    struct pessoa {

        int ordem;

    } p[MAX];

    int P, R, i, ni, k, comando, acao, T = 1;

    while (scanf("%d%d", &P, &R) && P + R)

    {

        for (i = 1; i <= P; i++) {
            p[i].ordem = 0;

            scanf("%d", &p[i].ordem);
        }

        for (k = 0; k < R; k++)

        {

            ni = 1;

            scanf("%d%d", &P, &comando);

            for (i = 1; i <= P; i++)

            {

                scanf("%d", &acao);

                if (acao == comando)

                {

                    p[ni++].ordem = p[i].ordem;
                }
            }
        }

        printf("Teste %d\n", T++);

        printf("%d\n\n", p[1].ordem);
    }

    return 0;
}