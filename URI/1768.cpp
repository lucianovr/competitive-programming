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
    int n;
    while (cin >> n) {
        int esp, base;
        esp = base = (n - 1) / 2;

        int dot = 1;
        do {
            rep(i, 0, esp) cout << " ";
            rep(i, 0, dot) cout << "*";
            cout << "\n";
            esp--;
            dot += 2;
        } while (esp >= 0);

        rep(i, 0, base) cout << " ";
        cout << "*";
        cout << "\n";
        base--;
        rep(i, 0, base) cout << " ";
        cout << "***";
        cout << "\n";

        cout << "\n";
    }
    return 0;
}
