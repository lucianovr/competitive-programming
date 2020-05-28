#include <cstdlib>
#include <iostream>
#include <stdio.h>
using namespace std;

int main() {
    int n, tot;

    while (cin >> n && n) {
        tot = 0;
        for (int i = n; i >= 1; i--)
            tot += i * i;
        cout << tot << endl;
    }
    // system("PAUSE");
    return 0;
}
