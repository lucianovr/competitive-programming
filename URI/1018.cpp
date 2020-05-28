#include <cmath>
#include <cstdlib>
#include <iostream>
using namespace std;

int main() {
    int n, lido;
    float cem, cinq, vin, dez, cinco, dois, um;

    cin >> n;
    lido = n;

    cem = floor(n / 100);
    n %= 100;
    cinq = floor(n / 50);
    n %= 50;
    vin = floor(n / 20);
    n %= 20;
    dez = floor(n / 10);
    n %= 10;
    cinco = floor(n / 5);
    n %= 5;
    dois = floor(n / 2);
    n %= 2;

    cout << lido << endl;
    cout << cem << " nota(s) de R$ 100,00\n";
    cout << cinq << " nota(s) de R$ 50,00\n";
    cout << vin << " nota(s) de R$ 20,00\n";
    cout << dez << " nota(s) de R$ 10,00\n";
    cout << cinco << " nota(s) de R$ 5,00\n";
    cout << dois << " nota(s) de R$ 2,00\n";
    cout << n << " nota(s) de R$ 1,00\n";

    system("PAUSE");
    return EXIT_SUCCESS;
}
