#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <stdio.h>
using namespace std;

int main() {
    char nome[1000];
    double s = 0.0, c = 0.0, n;

    while (cin.getline(nome, 1000)) {
        cin >> n;
        s += n;
        c = c + 1.0;
        scanf("\n");
    }
    cout << fixed << setprecision(1);
    cout << s / c << endl;

    // system("PAUSE");
    return 0;
}
