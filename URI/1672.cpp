#include <bits/stdc++.h>

using namespace std;

int main() {

    char x, y, z;
    while (scanf(" %c%ce%c", &x, &y, &z) > 0) {
        int N = (x - '0') * 10 + (y - '0');
        while (z - '0' > 0) {
            N *= 10;
            z--;
        }
        if (N == 0)
            break;

        int m = 0;
        while ((1 << m) <= N)
            m++;

        while ((1 << m) > N)
            m--;

        int _2M = 1 << m;
        int l = N % _2M;
        printf("%d\n", 2 * l + 1);
    }
    return 0;
}
