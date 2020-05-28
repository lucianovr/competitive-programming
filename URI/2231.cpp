#include <algorithm>
#include <cstring>
#include <iostream>
#include <map>
#include <stdio.h>
#include <string.h>
#include <utility>
#include <vector>
#define f first
#define s second
#define rdi(a) scanf("%d", &a)
#define rdii(a, b) scanf("%d%d", &a, &b)
#define ulli unsigned long long int
using namespace std;

int main() {

    int n, m, vet[10001], tc = 1, sum, me, ma, aux;

    while (rdii(n, m) && n + m) {
        sum = 0;
        for (int i = 0; i < n; i++)
            rdi(vet[i]);
        for (int i = 0; i < m; i++)
            sum += vet[i];
        me = ma = sum / m;
        for (int i = 0, j = m; j < n; i++, j++) {
            sum = sum - vet[i] + vet[j];
            aux = sum / m;
            if (aux > ma)
                ma = aux;
            if (aux < me)
                me = aux;
        }
        printf("Teste %d\n%d %d\n\n", tc++, me, ma);
    }
    return 0;
}
