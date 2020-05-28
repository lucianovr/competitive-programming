#include <stdio.h>
#define max 1001
int main() {
    int n, c[max], p[max], r[max], i;
    bool flag;
    while (scanf("%d", &n) && n) {

        for (i = 0; i < n; i++) {
            r[i] = 0;
            scanf("%d%d", &c[i], &p[i]);
        }
        flag = true;
        for (i = 0; i < n; i++) {
            if (i + p[i] >= 0 && i + p[i] < n && !r[i + p[i]])
                r[i + p[i]] = c[i];
            else {
                printf("-1");
                flag = false;
                break;
            }
        }

        if (flag) {
            printf("%d", r[0]);
            for (i = 1; i < n; i++)
                printf(" %d", r[i]);
        }
        printf("\n");
    }
    return 0;
}