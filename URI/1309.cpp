#include <stdio.h>
#define m 1000
using namespace std;

int main() {

    int n, c, i, j, v[10];

    while (scanf("%d", &n) != EOF) {
        scanf("%d", &c);
        i = 0;
        do {
            v[i] = n % m;
            n = n / m;
            i++;
        } while (n);

        printf("$");
        for (int j = i - 1; j >= 0; j--) {

            if (j != i - 1) {
                if (v[j] < 100)
                    printf("0");
                if (v[j] < 10)
                    printf("0");
            }

            printf("%d", v[j]);
            if (j != 0)
                printf(",");
        }

        printf(".");
        if (c > 9)
            printf("%d", c);
        else
            printf("0%d", c);

        printf("\n");
    }
    return 0;
}
