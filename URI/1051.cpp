#include <cstdlib>
#include <iomanip>
#include <iostream>

using namespace std;
float n, a, b, c;

void caseone() {
    a = n - 2000;
    cout << "R$ " << a * 0.08 << endl;
    return;
}

void casetwo() {
    a = 0.08 * 1000;
    b = n - 3000;
    cout << "R$ " << a + b * 0.18 << endl;
    return;
}
void casethre() {
    a = 0.08 * 1000;
    b = 0.18 * 1500;
    c = n - 4500;
    cout << "R$ " << a + b + c * 0.28 << endl;
    return;
}

int main() {
    cout << fixed << setprecision(2);
    cin >> n;
    if (n <= 2000)
        cout << "Isento\n";
    else if (n <= 3000)
        caseone();
    else if (n <= 4500)
        casetwo();
    else
        casethre();

    // system("PAUSE");
    return 0;
}