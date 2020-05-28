#include <stdio.h>
using namespace std;

int main() {

    int B, N, D, C, V, res[21], deb[21], i;
    bool flag;

    while (scanf("%d%d", &B, &N) && B + N) {

        for (i = 1; i <= B; i++) {
            res[i] = deb[i] = 0;
            scanf("%d", &res[i]);
        }

        for (i = 0; i < N; i++) {
            scanf("%d%d%d", &D, &C, &V);
            deb[D] += V;
            res[C] += V;
        }
        flag = true;
        for (i = 1; i <= B; i++)
            if (res[i] - deb[i] < 0) {
                printf("N\n");
                flag = false;
                break;
            }
        if (flag)
            printf("S\n");
    }

    return 0;
}
