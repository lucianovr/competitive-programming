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

    int n, x, tst = 1, flag;
    while (rdi(n) && n) {
        flag = 1;
        for (int i = 1; i <= n; i++) {
            rdi(x);
            if (flag && x == i) {
                cout << "Teste " << tst++ << endl << x << "\n\n";
                flag = 0;
            }
        }
    }
    return 0;
}