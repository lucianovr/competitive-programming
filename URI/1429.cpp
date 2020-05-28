#include <stdio.h>
#include <string.h>

int main() {

    char n[6];
    int i, s, j, fat, t;

    while (scanf("%s", &n) && n[0] - '0') {
        s = 0;
        t = strlen(n);
        fat = 1;
        j = t - 1;
        for (i = 1; i <= t; i++) {
            fat = fat * i;
            s += (n[j] - '0') * fat;
            j--;
        }
        printf("%d\n", s);
    }
    return 0;
}
