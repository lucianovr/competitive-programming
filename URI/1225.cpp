#include <algorithm>
#include <cmath>
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
int vet[10001];
long long int sum, n;

void func() {
    int media;
    if (sum % n == 0LL) {
        media = sum / n;
        sum = 0LL;
        for (int i = 0; i < n && vet[i] <= media; i++)
            sum += media - vet[i];
        cout << sum + 1 << endl;
    } else
        cout << "-1\n";
}

int main() {

    while (cin >> n) {
        sum = 0LL;
        for (int i = 0; i < n; i++) {
            rdi(vet[i]);
            sum += vet[i];
        }
        func();
    }
    return 0;
}
