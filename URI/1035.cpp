#include <cmath>
#include <cstdlib>
#include <iostream>
using namespace std;

int main() {
    int a, b, c, d;

    cin >> a >> b >> c >> d;

    if ((b > c) && (d > a) && (c + d > a + b) && (d >= 0) && (c >= 0) && (a % 2 == 0))
        cout << "Valores aceitos\n";
    else
        cout << "Valores nao aceitos\n";

    // system("PAUSE");
    return 0;
}
