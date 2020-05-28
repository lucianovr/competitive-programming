#include <cstdlib>
#include <iostream>

using namespace std;

int main() {
    int a, b, ma, me;

    cin >> a >> b;

    if (a > b) {
        ma = a;
        me = b;
    } else {
        ma = b;
        me = a;
    }
    if (ma % me == 0)
        cout << "Sao Multiplos\n";
    else
        cout << "Nao sao Multiplos\n";

    system("PAUSE");
    return EXIT_SUCCESS;
}