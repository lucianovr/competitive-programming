#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#define MAX 10001
using namespace std;

int compare(const void *a, const void *b);

struct numero {
    long int val;
    int mod, ip;
} n[MAX];

int main() {
    int N, M, a, i;

    while (scanf("%d%d", &N, &M) && N + M) {

        for (i = 0; i < N; i++) {
            scanf("%ld", &a);
            n[i].val = a;
            n[i].mod = (int)(a % M);
            if ((int)(abs(a) % 2) == 0)
                n[i].ip = 1;
            else
                n[i].ip = 0;
        }

        qsort(n, N, sizeof(numero), compare);
        printf("%d %d\n", N, M);
        for (i = 0; i < N; i++)
            printf("%ld\n", n[i].val);
    }
    printf("0 0\n");

    return 0;
}

int compare(const void *a, const void *b) {

    numero pa = *(numero *)a;
    numero pb = *(numero *)b;

    if (pa.mod < pb.mod)
        return -1;
    if (pa.mod > pb.mod)
        return 1;
    if (pa.ip == 1 && pb.ip == 0)
        return 1;
    if (pa.ip == 0 && pb.ip == 1)
        return -1;
    if (pa.ip == 0 && pb.ip == 0) {
        if (pa.val > pb.val)
            return -1;
        if (pa.val < pb.val)
            return 1;
    }
    if (pa.ip == 1 && pb.ip == 1) {
        if (pa.val > pb.val)
            return 1;
        if (pa.val < pb.val)
            return -1;
    }
    return -1;
}
