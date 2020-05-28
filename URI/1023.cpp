#include <bits/stdc++.h>
using namespace std;
#define pi 3.1415926535897932384626433832795028841971693993751058209
#define rep(a, b, n) for (int a = b; a < n; a++)

typedef pair<int, int> ii;
typedef vector<ii> vii;

int consumo[300];

int main() {
    int n, t = 1, P, G, sumG, sumP;

    while (scanf("%d", &n) && n) {
        if (t != 1)
            printf("\n");
        memset(consumo, 0, sizeof consumo);

        sumP = sumG = 0;
        rep(i, 0, n) {
            scanf("%d %d", &P, &G);
            consumo[G / P] += P;
            sumP += P;
            sumG += G;
        }
        printf("Cidade# %d:\n", t++);

        bool ok = false;
        rep(i, 0, 201) {
            if (consumo[i]) {
                if (ok)
                    printf(" ");
                ok = true;
                printf("%d-%d", consumo[i], i);
            }
        }
        printf("\nConsumo medio: %.2lf m3.\n", ((double)(int(100 * ((double)sumG) / ((double)sumP)))) / 100);
    }
    return 0;
}
