#include <iostream>
#include <map>
#include <stack>
#include <stdio.h>
#include <utility>
#define MAX 1000000
using namespace std;
struct FOCO {
    int a, b;
} F[MAX];

int main() {
    map<pair<int, int>, bool> M;
    map<pair<int, int>, bool>::iterator it;
    pair<int, int> foco;
    int n, i, c, d, cont, f;

    while (scanf("%d", &n) != EOF) {
        M.clear();
        while (n--) {
            scanf("%d%d", &c, &d);
            foco = make_pair(c, d);
            M[foco] = true;
        }

        it = M.begin();
        f = (it->first).second; // foco inicial
        i = 0;
        for (it = M.begin(); it != M.end(); it++) {
            F[i].a = (it->first).first;
            F[i].b = (it->first).second;
            i++;
        }
        n = i;
        cont = 1; // pelo menos uma foto
        for (i = 1; i < n; i++) {
            if (F[i].a > f) {
                cont++;
                f = F[i].b;
            } else if (F[i].b <= f)
                f = F[i].b;
        }
        printf("%d\n", cont);
    }
    return 0;
}
