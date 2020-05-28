#include <cstdlib>
#include <iostream>
#include <stdio.h>
using namespace std;

int main() {
    int a, b, c, ma;

    cin >> a >> b >> c;
    ma = a;

    if (b > ma)
        ma = b;
    if (c > ma)
        ma = c;

    cout << ma << " eh o maior" << endl;

    // system("PAUSE");
    return EXIT_SUCCESS;
}
