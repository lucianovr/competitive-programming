#include <cstdlib>
#include <iomanip>
#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
    cout << fixed << setprecision(2);
    int op, q;

    cin >> op >> q;

    if (op == 1)
        cout << "Total: R$ " << q * 4.00 << endl;
    else if (op == 2)
        cout << "Total: R$ " << q * 4.50 << endl;
    else if (op == 3)
        cout << "Total: R$ " << q * 5.00 << endl;
    else if (op == 4)
        cout << "Total: R$ " << q * 2.00 << endl;
    else if (op == 5)
        cout << "Total: R$ " << q * 1.50 << endl;

    system("PAUSE");
    return EXIT_SUCCESS;
}
