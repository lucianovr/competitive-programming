#include <cstdlib>
#include <iostream>
using namespace std;

int main() {
    short A;
    while (cin >> A) {
        if (A % 6 == 0)
            cout << "Y\n";
        else
            cout << "N\n";
    }

    return 0;
}
