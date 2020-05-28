#include <stdio.h>
#include <string.h>

int josephus(int n, int k) {
    int r = 0;
    int i = 2;
    while (i <= n) {
        r = (r + k) % i;
        i += 1;
    }
    return r + 1;
}

int main() {

    int NC, N, K;
    scanf("%d", &NC);
    for (int nc = 0; nc < NC; nc++) {
        scanf("%d%d", &N, &K);
        printf("Case %d: %d\n", nc + 1, josephus(N, K));
    }
    return 0;
}
