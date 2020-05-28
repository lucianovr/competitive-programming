#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

int main() {

    int n, i, t, d;
    char com[1001];

    while (scanf("%d", &n) && n) {
        scanf("\n");
        scanf("%s", com);
        d = 0;
        t = strlen(com);
        for (i = 0; i < t; i++)
            if (com[i] == 'D')
                d++;
            else if (com[i] == 'E')
                d--;
        if (d > 0)
            d %= 4;
        else if (d < 0) {
            d *= -1;
            d %= 4;
            if (d == 3)
                d = 1;
            else if (d == 1)
                d = 3;
        }

        if (d == 0)
            printf("N\n");
        else if (d == 1)
            printf("L\n");
        else if (d == 2)
            printf("S\n");
        else if (d == 3)
            printf("O\n");
    }
    return 0;
}