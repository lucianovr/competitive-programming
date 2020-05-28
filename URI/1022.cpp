#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctype.h>
#include <iostream>
#include <queue>
#include <set>
#include <utility>
#include <vector>

using namespace std;

int GCD(int a, int b) {
    if (b == 0)
        return a;
    else
        return GCD(b, a % b);
}
int main() {
    int t, a, b, c, d, N, D;
    char op;
    scanf("%d", &t);

    while (t--) {
        scanf("%d / %d %c %d / %d", &a, &b, &op, &c, &d);
        if (op == '+' || op == '-') {
            N = (a * d + (op == '-' ? -1 : 1) * c * b);
            D = b * d;
        } else if (op == '*') {
            N = a * c;
            D = b * d;
        } else {
            N = a * d;
            D = b * c;
        }

        if (D < 0) {
            N *= -1;
            D *= -1;
        }
        int gcd = GCD(abs(N), abs(D));

        cout << N << "/" << D << " = " << N / gcd << "/" << D / gcd << "\n";
    }
}