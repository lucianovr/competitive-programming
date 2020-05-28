#include <iomanip>
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int main() {

    double V;
    int M, N, m[5], n[5], i, j, k, vet[100], bm, bn;

    j = 100, k = 0;
    i = 1;
    while (j--) {
        if ((i - 1) % 4 == 0)
            k++;
        vet[i++] = k;
    }
    vet[0] = 25;

    while (cin >> V >> M >> N && V + M + N) {
        cout << fixed << setprecision(2);
        bm = M % 100;
        bn = N % 100;
        i = 0;
        while (i < 4) {
            m[i++] = M % 10;
            M /= 10;
        }
        i = 0;
        while (i < 4) {
            n[i++] = N % 10;
            N /= 10;
        }

        if (m[0] == n[0] && m[1] == n[1] && m[2] == n[2] && m[3] == n[3])
            cout << V * 3000.00;
        else if (m[0] == n[0] && m[1] == n[1] && m[2] == n[2])
            cout << V * 500.00;
        else if (m[0] == n[0] && m[1] == n[1])
            cout << V * 50.00;
        else if (vet[bm] == vet[bn])
            cout << V * 16.00;
        else
            cout << 0.00;

        cout << "\n";
    }
    return 0;
}
