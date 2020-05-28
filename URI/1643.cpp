#include <algorithm>
#include <stdio.h>
#include <string.h>
using namespace std;

int main() {
    int t, i, x;
    int f[100000];
    f[0] = 1;
    f[1] = 2;
    int b[30];

    for (i = 2; f[i - 1] <= 25000; i++)
        f[i] = f[i - 1] + f[i - 2];
    int tam = i;

    scanf("%d", &t);
    while (t--) {
        scanf("%d", &x);
        memset(b, 0, sizeof b);
        int p = lower_bound(f, f + tam, x) - f;

        while (x && p >= 0) {
            if (x >= f[p]) {
                b[p] = 1;
                x -= f[p];
            }
            p--;
        }

        int milhas = 0;
        for (int i = 0; i < 22; i++) {
            // b[i] = b[i+1];
            milhas += b[i + 1] * f[i];
        }
        printf("%d\n", milhas);
    }

    return 0;
}