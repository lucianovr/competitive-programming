#include <iostream>
#include <map>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

int compare(const void *a, const void *b);

struct camiseta {
    char aluno[1000], cor[1000], tamanho[2];
} c[61];

map<string, int> mapa;

int main() {
    int N, i;
    bool flag = false;
    mapa["branco"] = 1;
    mapa["vermelho"] = 2;
    mapa["P"] = 3;
    mapa["M"] = 4;
    mapa["G"] = 5;
    while (scanf("%d", &N) && N) {
        // scanf("\n");
        if (flag)
            printf("\n");
        else
            flag = true;

        for (i = 0; i < N; i++) {
            scanf("\n");
            gets(c[i].aluno);
            scanf("%s", c[i].cor);
            scanf("%s", c[i].tamanho);
        }

        qsort(c, N, sizeof(camiseta), compare);

        for (i = 0; i < N; i++)
            cout << c[i].cor << " " << c[i].tamanho << " " << c[i].aluno << endl;
    }
    // system("PAUSE");
    return 0;
}
//             -1                  1
int compare(const void *a, const void *b) {

    camiseta pa = *(camiseta *)a;
    camiseta pb = *(camiseta *)b;

    if (mapa[pa.cor] < mapa[pb.cor])
        return -1;
    if (mapa[pa.cor] > mapa[pb.cor])
        return 1;

    if (mapa[pa.tamanho] < mapa[pb.tamanho])
        return -1;
    if (mapa[pa.tamanho] > mapa[pb.tamanho])
        return 1;

    if (strcmp(pa.aluno, pb.aluno) == 0)
        return 1;
    else
        return strcmp(pa.aluno, pb.aluno);
}
