#include <cstdlib>
#include <iomanip>
#include <iostream>
using namespace std;

int main() {
    float soma = 0, n, cont = 0;
    float med;

    while (cin >> n && n >= 0) {
        soma += n;
        cont++;
    }
    med = soma / cont;
    cout << fixed << setprecision(2);
    cout << med << endl;
    // system("PAUSE");
    return 0;
}
