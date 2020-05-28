#include <stdio.h>
#include <string.h>

int main() {
    int c, p, t, i, a;
    char r[55];

    while (scanf("%s", r) != EOF) {
        scanf("%d", &p);
        c = 0;
        t = strlen(r);
        for (i = 0; i < t; i++) {
            if (r[i] == 'W')
                c++;
            else {
                c++;
                a = 0;
                while (i < t && r[i] == 'R' && a < p) {
                    i++;
                    a++;
                }
                i--;
            }
        }
        printf("%d\n", c);
    }
    return 0;
}
