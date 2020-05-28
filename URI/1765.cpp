#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
#define pb push_back
#define rep(i, a, b) for (int i(a); i < (b); i++)
#define debgu(x) cout << #x << " = " << x;
#define nl cout << "\n";

int main() {
    int t;
    double q, a, b, area;

    while (scanf("%d", &t) && t) {

        rep(i, 0, t) {
            scanf("%lf %lf %lf", &q, &a, &b);
            area = q * (a + b) * 2.5;

            printf("Size #%d:\n", i + 1);
            printf("Ice Cream Used: %.2lf cm2\n", area);
        }
        printf("\n");
    }
    return 0;
}
