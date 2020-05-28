#include <stdio.h>
using namespace std;

int main() {
    int t, n, m;

    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        scanf("%d%d", &n, &m);
        printf("%d\n", (n / 3) * (m / 3));
    }

    return 0;
}
