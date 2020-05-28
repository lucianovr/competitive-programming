#include <cmath>
#include <cstdlib>
#include <iostream>
using namespace std;

int main() {
    int t;
    float a, m;

    cin >> t;

    a = floor(t / 365);
    t %= 365;
    m = floor(t / 30);
    t %= 30;

    cout << a << " ano(s)\n";
    cout << m << " mes(es)\n";
    cout << t << " dia(s)\n";

    system("PAUSE");
    return EXIT_SUCCESS;
}
