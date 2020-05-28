#include <stdio.h>

int main() {
    int a[20001], i, l, r, pv, h, max, f;
    for (i = 0; i < 20000; i++)
        a[i] = 0;
    max = 0;
    while (scanf("%d%d%d", &l, &h, &r) != EOF) {
        if (l == -1)
            break;
        for (i = l; i < r; i++) {
            if (a[i] < h)
                a[i] = h;
            if (r > max)
                max = r;
        }
    }

    for (i = 0, pv = 0, f = 1; i <= max + 1; i++) {
        if (pv != a[i]) {
            pv = a[i];
            if (f) {
                printf("%d %d", i, pv);
                f = 0;
            } else
                printf(" %d %d", i, pv);
        }
    }
    printf("\n");

    return 0;
}