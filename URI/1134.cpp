
#include <cstdlib>
#include <iostream>
using namespace std;
int main() {
    int a, alc = 0, gas = 0, die = 0;

    do {
        cin >> a;

        if (a == 1)
            alc++;
        if (a == 2)
            gas++;
        if (a == 3)
            die++;
    } while (a != 4); // se a==4, ele sai

    cout << "MUITO OBRIGADO\n";
    cout << "Alcool: " << alc << endl;
    cout << "Gasolina: " << gas << endl;
    cout << "Diesel: " << die << endl;

    // stem("PAUSE");
    return 0;
}
