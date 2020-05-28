#include <iostream>
#include <stdio.h>
using namespace std;

int main() {

    int h, ma;

    while (scanf("%d", &h) && h) {
        ma = h;
        while (h != 1) {
            if (h % 2 == 0)
                h /= 2;
            else
                h = h * 3 + 1;

            if (h > ma)
                ma = h;
        }
        printf("%d\n", ma);
    }
    return 0;
}
