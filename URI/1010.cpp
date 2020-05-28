#include <cstdio>

using namespace std;

int main() {
    double c1, c2, q1, q2, p1, p2;

    scanf("%lf %lf %lf", &c1, &q1, &p1);
    scanf("%lf %lf %lf", &c2, &q2, &p2);

    printf("VALOR A PAGAR: R$ %.2lf\n", q1 * p1 + q2 * p2);

    return 0;
}