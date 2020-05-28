#include <iostream>
#include <map>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

int compare(const void *a, const void *b);

struct ASC {
    int v, f;
} letra[200];

int main() {
    map<char, bool> mapa;
    char frase[1001];
    int i, t;
    bool aux = false;

    while (cin.getline(frase, 1001)) {

        if (aux)
            cout << endl;
        else
            aux = true;

        mapa.clear();
        for (i = 0; i < 200; i++) {
            letra[i].f = 0;
        }

        t = strlen(frase);
        for (i = 0; i < t; i++) {
            mapa[frase[i]] = true;
            letra[(int)frase[i]].f = letra[(int)frase[i]].f + 1;
            letra[(int)frase[i]].v = (int)frase[i];
        }
        qsort(letra, 200, sizeof(ASC), compare);

        for (i = 0; i < 200; i++)
            if (letra[i].f)
                cout << letra[i].v << " " << letra[i].f << endl;
    }
    return 0;
}

int compare(const void *a, const void *b) {
    ASC pa = *(ASC *)a;
    ASC pb = *(ASC *)b;
    if (pa.f < pb.f)
        return -1;
    if (pa.f > pb.f)
        return 1;
    if (pa.v > pb.v)
        return -1;
    if (pa.v < pb.v)
        return 1;
}
