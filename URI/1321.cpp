#include <algorithm>
#include <map>
#include <stdio.h>
using namespace std;
int a, b, c, x, y, z, aux[3], k;
bool flag;
map<int, bool> mapa;

int main() {

    while (scanf("%d%d%d%d%d", &aux[0], &aux[1], &aux[2], &a, &b) && (aux[0] + aux[1] + aux[2] + a + b)) {
        mapa.clear();
        x = min(a, b);
        y = max(a, b);
        sort(aux, aux + 3);
        a = aux[0];
        b = aux[1];
        c = aux[2];
        mapa[x] = mapa[y] = mapa[a] = mapa[b] = mapa[c] = true;
        // testando uma jogada no pior caso
        if (y > a) {
            if (b > x)
                k = c + 1;
            else if (c > x)
                k = b + 1;
            else
                k = 1;
        } else
            k = -1;
        flag = true;
        if (k != -1) {
            if (k > y) {
                if (y < c) {
                    flag = false;
                    printf("-1");
                }
            } else
                while (mapa[k])
                    k = (k + 1) % 53;
        }
        if (flag) {
            if (k == 0) {
                printf("-1");
            } else
                printf("%d", k);
        }
        printf("\n");
    }
    return 0;
}
