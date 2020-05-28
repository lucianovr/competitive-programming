#include <stdio.h>

int main() {

    int a, b, c, me;

    while (scanf("%d%d", &a, &b) && a + b) {

        me = 2000000001;
        c = 2 * a - b;
        if (c < me)
            me = c;
        c = 2 * b - a;
        if (c < me)
            me = c;
        c = (a + b) / 2;
        if (c < me)
            me = c;

        printf("%d\n", me);
    }
    return 0;
}
