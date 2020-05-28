#include <stdio.h>
int main() {

    double pi = 3.14159, a, r;

    scanf("%lf", &r);
    a = (4.0 * pi * r * r * r) / 3.0;
    printf("VOLUME = %.3lf\n", a);

    return 0;
}
