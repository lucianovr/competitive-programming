#include <algorithm>
#include <stdio.h>
using namespace std;

int main() {
    int T, N, i, j, c, aux, v[10005];
    bool B;

    scanf("%d", &T);
    for (int t = 0; t < T; t++) {
        scanf("%d", &N);

        for (i = 1; i <= N; i++)
            scanf("%d", &v[i]);
        B = true;
        c = 0;
        while (B) {
            B = false;
            for (i = 1; i <= N; i++)
                if (v[i] != i) {
                    B = true;
                    j = v[i];
                    swap(v[i], v[j]);
                    c++;
                }
        }
        printf("%d\n", c);
    }
    return 0;
}
