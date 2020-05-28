#include <map>
#include <stdio.h>

using namespace std;

int main() {
    map<int, int> MAPA;
    map<int, int>::iterator it;
    int n, m, J, P, S, aux;
    while (scanf("%d%d", &n, &m) && n + m) {
        MAPA.clear();
        while (n--) {
            for (int i = 0; i < m; i++) {
                scanf("%d", &J);
                MAPA[J]++;
            }
        }
        P = S = -1;
        for (it = MAPA.begin(); it != MAPA.end(); it++) {
            if (it->second > S)
                S = it->second;
            if (S > P) {
                aux = P;
                P = S;
                S = aux;
            }
        }
        for (it = MAPA.begin(); it != MAPA.end(); it++) {
            if (it->second == S)
                printf("%d ", it->first);
        }
        printf("\n");
    }
    return 0;
}
