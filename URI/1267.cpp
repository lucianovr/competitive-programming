#include <stdio.h>

int main() {
    int n, d, i, j, v[110], aluno;
    bool flag;

    while (scanf("%d%d", &n, &d) && n + d) {
        for (i = 0; i < n; i++)
            v[i] = 0;
        flag = true;
        for (j = 0; j < d; j++)
            for (i = 0; i < n; i++) {
                scanf("%d", &aluno);
                if (aluno)
                    v[i]++;
            }

        for (i = 0; i < n; i++) {
            if (v[i] == d) {
                printf("yes\n");
                flag = false;
                break;
            }
        }
        if (flag)
            printf("no\n");
    }
    return 0;
}
