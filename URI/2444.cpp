#include <stdio.h>
int main() {
    int v, r, x;

    scanf("%d%d", &v, &r);
    while (r--) {
        scanf("%d", &x);
        v += x;
        if (v > 100)
            v = 100;
        else if (v < 0)
            v = 0;
    }
    printf("%d\n", v);
    return 0;
}
