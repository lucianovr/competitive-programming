#include <iostream>
#include <stdio.h>
#include <string>
#define m 131071
using namespace std;

string dig;
void func() {
    int p = 1, prod = 0, soma = 0, len = dig.size();

    for (int i = len - 1; i >= 0; i--) {
        prod = (dig[i] - '0') * p;
        soma = (soma % m + prod % m) % m;
        p = (p % m * 2) % m;
    }
    if (soma % m == 0)
        cout << "YES\n";
    else
        cout << "NO\n";
}

int main() {
    char c;
    int j = 0;

    while ((c = getchar()) != EOF) {
        if (c == '#') {
            func();
            dig.clear();
        } else if (c != '\n')
            dig += c;
    }
    return 0;
}
