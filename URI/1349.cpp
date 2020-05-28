#include <algorithm>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <stdio.h>
using namespace std;

float n, ma, cont;
int N;

void Read(int tok[][401], int ass[][401]) {
    int i, j;
    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
            scanf("%d", &tok[i][j]);
    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
            scanf("%d", &ass[i][j]);
}

int ABS(int x) {
    if (x > 0)
        return x;
    return -x;
}

void Rotate_Test(int tok[][401], int ass[][401]) {
    int i, j, l, k;
    cont = 0;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++)
            if (ABS(tok[i][j] - ass[i][j]) <= 100)
                cont++;
    }
    ma = max(ma, cont);
    cont = 0;

    for (i = 0; i < N; i++) {
        l = (int)n - 1;
        for (j = 0; j < N; j++)
            if (ABS(tok[i][j] - ass[l - j][i]) <= 100)
                cont++;
    }
    ma = max(ma, cont);
    cont = 0;

    for (i = 0; i < N; i++) {
        k = N - 1;
        l = N - 1 - i;
        for (j = 0; j < N; j++)
            if (ABS(tok[i][j] - ass[l][k - j]) <= 100)
                cont++;
    }
    ma = max(ma, cont);
    cont = 0;

    for (i = 0; i < N; i++) {
        k = N - 1 - i;
        l = 0;
        for (j = 0; j < N; j++)
            if (ABS(tok[i][j] - ass[j][k]) <= 100)
                cont++;
    }
    ma = max(ma, cont);
    cont = 0;
}

void Inverte(int ass[][401]) {

    int i, j, me, aux;
    me = N / 2;
    for (i = 0; i < me; i++)
        for (j = 0; j < N; j++)
            swap(ass[i][j], ass[N - 1 - i][j]);
}

int main() {
    int tok[401][401], ass[401][401];
    while (scanf("%d", &N) && N) {
        n = N;
        ma = 0;
        Read(tok, ass);
        Rotate_Test(tok, ass);
        Inverte(ass);
        Rotate_Test(tok, ass);
        cout << fixed << setprecision(2);
        cout << (ma / (n * n)) * 100 << endl;
    }
    return 0;
}
