#include <cstdlib>
#include <iostream>
#include <map>
#include <stdlib.h>
using namespace std;

struct CARTAS {
    char face, naipe, z;
} C[3], aux[3], p;
map<char, int> NAIPE;
map<char, int> FACE;
int compar(const void *a, const void *b);

int main() {

    NAIPE['H'] = 1;
    NAIPE['C'] = 2;
    NAIPE['D'] = 3;
    NAIPE['S'] = 4;

    FACE['1'] = 0;
    FACE['2'] = 1;
    FACE['3'] = 2;
    FACE['4'] = 3;
    FACE['5'] = 4;
    FACE['6'] = 5;
    FACE['7'] = 6;
    FACE['8'] = 7;
    FACE['9'] = 8;
    FACE['T'] = 9;
    FACE['J'] = 10;
    FACE['Q'] = 11;
    FACE['K'] = 12;

    int n, i, j, a, b, c, fator;
    char v[13];
    v[0] = '1';
    v[1] = '2';
    v[2] = '3';
    v[3] = '4';
    v[4] = '5';
    v[5] = '6';
    v[6] = '7';
    v[7] = '8';
    v[8] = '9';
    v[9] = 'T';
    v[10] = 'J';
    v[11] = 'Q';
    v[12] = 'K';
    cin >> n;
    while (n--) {
        scanf("\n");
        cin >> p.face >> p.naipe;
        for (i = 0; i < 3; i++) {
            cin >> C[i].face >> C[i].naipe;
            aux[i].face = C[i].face;
            aux[i].naipe = C[i].naipe;
        }
        qsort(aux, 3, sizeof(CARTAS), compar);
        for (i = 0; i < 3; i++)
            aux[i].z = i + 1;

        for (i = 0; i < 3; i++)
            for (j = 0; j < 3; j++)
                if (C[i].face == aux[j].face && C[i].naipe == aux[j].naipe)
                    C[i].z = aux[j].z;

        a = C[0].z;
        b = C[1].z;
        c = C[2].z;
        if (a == 1 && b == 2 && c == 3)
            fator = 1;
        else if (a == 1 && b == 3 && c == 2)
            fator = 2;
        else if (a == 2 && b == 1 && c == 3)
            fator = 3;
        else if (a == 2 && b == 3 && c == 1)
            fator = 4;
        else if (a == 3 && b == 1 && c == 2)
            fator = 5;
        else if (a == 3 && b == 2 && c == 1)
            fator = 6;

        cout << v[(FACE[p.face] + fator) % 13] << p.naipe << endl;
    }
    return 0;
}
int compar(const void *a, const void *b) {
    CARTAS pa = *(CARTAS *)a;
    CARTAS pb = *(CARTAS *)b;
    if (NAIPE[pa.naipe] < NAIPE[pb.naipe])
        return -1;
    if (NAIPE[pa.naipe] > NAIPE[pb.naipe])
        return 1;
    if (FACE[pa.face] < FACE[pb.face])
        return -1;
    else
        return 1;
}
