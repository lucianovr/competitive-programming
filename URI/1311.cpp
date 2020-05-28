#include <stdio.h>
#define MAX 100003
using namespace std;

int main() {
    struct VETOR {
        int L, R;
    } SOLDADO[MAX];
    int NS, NB, left, right, i;

    while (scanf("%d%d", &NS, &NB) && NS + NB) {
        for (i = 1; i <= NS; i++) {
            SOLDADO[i].L = i - 1;
            SOLDADO[i].R = i + 1;
        }
        SOLDADO[1].L = SOLDADO[NS].R = 0;

        while (NB--) {
            scanf("%d%d", &left, &right);
            SOLDADO[SOLDADO[left].L].R = SOLDADO[right].R;
            SOLDADO[SOLDADO[right].R].L = SOLDADO[left].L;

            if (SOLDADO[left].L)
                printf("%d ", SOLDADO[left].L);
            else
                printf("* ");
            if (SOLDADO[right].R)
                printf("%d\n", SOLDADO[right].R);
            else
                printf("*\n");
        }
        printf("-\n");
    }
    return 0;
}
