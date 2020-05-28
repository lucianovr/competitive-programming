#include <algorithm>
#include <cstring>
#include <iostream>
#include <map>
#include <stdio.h>
#include <string.h>
#include <utility>
#include <vector>
#define f first
#define s second
#define rdi(a) scanf("%d", &a)
#define rdii(a, b) scanf("%d%d", &a, &b)
#define ulli unsigned long long int
using namespace std;

int main() {

    int v, a, b, c, d, A = 50, B = 10, C = 5, D = 1, tst = 1;

    while (rdi(v) && v) {
        a = v / A;
        v %= A;
        b = v / B;
        v %= B;
        c = v / C;
        v %= C;
        d = v;

        cout << "Teste " << tst++ << endl << a << " " << b << " " << c << " " << d << endl << endl;
    }

    return 0;
}
