#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int func(char f[], int tf, char s[], int ts) {
    int i, j, k, l, u, ma = 0, cont, maxx;

    for (i = 0; i < ts; i++) {
        for (j = ts - 1; j >= i; j--) {
            maxx = tf - (j - i + 1);
            for (k = 0; k <= maxx; k++) {
                u = cont = 0;
                for (l = i; l <= j; l++) {
                    if (f[k + u] == s[l])
                        cont++;
                    else
                        break;
                    u++;
                }
                ma = max(ma, cont);
            }
        }
    }
    return ma;
}

int main() {

    char fi[100], se[100];
    int lenf, lens;

    while (cin.getline(fi, 100)) {
        cin.getline(se, 100);
        lenf = strlen(fi);
        lens = strlen(se);
        if (lenf > lens)
            printf("%d\n", func(fi, lenf, se, lens));
        else
            printf("%d\n", func(se, lens, fi, lenf));
    }
}
