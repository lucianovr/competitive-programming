#include <cmath>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string.h>
using namespace std;
string num;
char map[18] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
int i, r[999], aux, ma;
unsigned long long int n, soma;

void hex_to_dec() {
    float t;
    int k;
    soma = 0ULL;
    t = num.size();
    for (i = 2; i < t; i++) {
        if (isalpha(num[i]))
            k = (tolower(num[i]) - 'a') + 10;
        else
            k = (num[i] - '0');
        soma = soma + k * pow(16.0, (t - i - 1.0));
    }
    cout << soma << endl;
    return;
}

void dec_to_hex() {
    stringstream N(num); // transforma string em numero
    N >> n;              // transferencia...
    i = 0;
    while (n >= 16) {
        r[i] = n % 16;
        n /= 16;
        i++;
    }
    r[i] = n;
    ma = i + 1;
    for (i = 0; i < ma / 2; i++) {
        aux = r[i];
        r[i] = r[ma - i - 1];
        r[ma - i - 1] = aux;
    }
    cout << "0x";
    for (i = 0; i < ma; i++)
        cout << map[r[i]];
    cout << endl;

    return;
}

int main() {
    while (cin >> num && (num[0] != '-')) {
        if (num[1] == 'x')
            hex_to_dec();
        else
            dec_to_hex();
    }

    return 0;
}
