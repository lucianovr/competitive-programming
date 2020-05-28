#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, c, qtd = 0, s, e;
    scanf("%d%d", &n, &c);
    bool flag = true;

    for (int i = 0; i < n; i++) {
        scanf("%d%d", &s, &e);
        qtd = qtd - s + e;
        if (flag && qtd > c) {
            flag = false;
        }
    }
    if (flag)
        printf("N\n");
    else
        printf("S\n");

    return 0;
}
