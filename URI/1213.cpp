#include <iostream>
using namespace std;

int n;
int c, s, d = 10, u = 1; // contador, soma, dezena e unidade

void func(int s) {
    if (s % n == 0) {
        cout << c << endl;
        return;
    } else {
        c++;
        return func((((((s % n) * (d % n)) % n) % n) + (u % n)) % n);
    }
    return;
}

int main() {
    while (cin >> n) {
        c = 1;
        func(1);
    }
    return 0;
}
