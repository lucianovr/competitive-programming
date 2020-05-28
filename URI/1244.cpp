#include <iostream>
#include <map>
#include <stdio.h>
#include <string.h>
using namespace std;

int compare(const void *a, const void *b);

struct palavra {
    int tam, pos;
    string str;
} w[51];

int main() {
    int n, i, p, t, k;
    char frase[2505];
    char *pch;

    scanf("%d", &n);
    scanf("\n");
    for (t = 0; t < n; t++) {
        k = 0;
        gets(frase);
        pch = strtok(frase, " ");
        while (pch != NULL) {
            w[k].tam = strlen(pch);
            w[k].pos = k;
            w[k].str = pch;
            k++;
            pch = strtok(NULL, " ");
        }
        qsort(w, k, sizeof(palavra), compare);
        cout << w[0].str;
        for (i = 1; i < k; i++)
            cout << " " << w[i].str;
        cout << endl;
    }
    // system("PAUSE");
    return 0;
}

int compare(const void *a, const void *b) {
    palavra pa = *(palavra *)a;
    palavra pb = *(palavra *)b;

    if (pa.tam > pb.tam)
        return -1;
    if (pa.tam < pb.tam)
        return 1;
    if (pa.pos < pb.pos)
        return -1;
    if (pa.pos > pb.pos)
        return 1;
}
