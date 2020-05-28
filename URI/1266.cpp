#include <stdio.h>
#define MAX 5001
using namespace std;
int poste;
int main() {

    int n, poste[MAX], i, id, c, npostes;
    bool achou;

    while (scanf("%d", &n) && n) {
        achou = false;
        for (i = 0; i < n; i++) {
            scanf("%d", &poste[i]);
            if (!achou && poste[i]) {
                id = i;
                achou = true;
            }
        }
        npostes = c = 0;
        if (achou) {
            for (i = (id + 1) % n; i < MAX + 2; i = (i + 1) % n) {
                if (poste[i] == 0)
                    c++;
                else {
                    npostes = npostes + c / 2;
                    c = 0;
                }
                if (i == id)
                    break;
            }
        } else {
            npostes = int(n / 2);
            if (n % 2 == 1)
                npostes++;
        }

        printf("%d\n", npostes);
    }
    return 0;
}
