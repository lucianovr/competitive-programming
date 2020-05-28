#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a, c = b; i < c; ++i)

struct tipo {
    int digrafo;
    int cnt;
} vet[9320];

bool comp(tipo a, tipo b) {
    if (a.cnt > b.cnt)
        return true;
    else if (b.cnt > a.cnt)
        return false;
    else
        return a.digrafo < b.digrafo;
}

int main() {
    char text[6000], aux[100];
    int t, tot, len, val;

    while (scanf("%d", &t) && t) {
        scanf("\n");
        memset(vet, 0, sizeof vet);
        for (int i = 0; i <= 9319; i++)
            vet[i].digrafo = i;

        text[0] = '\0';
        while (t--) {
            gets(aux);
            strcat(text, aux);
        }

        len = strlen(text);
        tot = 0;
        for (int i = 0; i < len - 1; i++) {
            val = (text[i] - 32) * 96 + (text[i + 1] - 32);
            vet[val].cnt++;
            tot++;
        }

        sort(vet, vet + 9320, comp);
        rep(i, 0, 5) {
            int a, b;
            a = vet[i].digrafo / 96;
            b = vet[i].digrafo % 96;
            printf("%c%c %d %.6lf\n", a + 32, b + 32, vet[i].cnt, (double(vet[i].cnt)) / (double)tot);
        }
        printf("\n");
    }
    return 0;
}