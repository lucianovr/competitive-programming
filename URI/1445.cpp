#include <map>
#include <stdio.h>
using namespace std;
struct CONVIDADOS {
    int a, b;
} C[1002];
int main() {
    map<int, int> M;
    map<int, int>::iterator it;
    int N, cont, i;
    char lixo;
    bool B;

    while (scanf("%d", &N) && N) {
        M.clear();
        for (i = 0; i < N; i++) {
            scanf("\n");
            scanf("%c%d%c%d%c", &lixo, &C[i].a, &lixo, &C[i].b, &lixo);
            M[C[i].a] = M[C[i].b] = false;
        }
        B = M[1] = true;
        cont = 0;
        while (B) {
            B = false;
            for (i = 0; i < N; i++) {
                if (M[C[i].a] ^ M[C[i].b]) {
                    B = M[C[i].a] = M[C[i].b] = true;
                    cont++;
                }
            }
        }

        printf("%d\n", cont + 1);
    }
    return 0;
}
