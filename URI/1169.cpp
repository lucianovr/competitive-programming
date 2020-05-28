#include <cmath>
#include <cstdlib>
#include <iostream>
using namespace std;

int main() {
    int n, c;
    unsigned long long int soma = 0ULL;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> c;
        if (c == 64) {
            cout << "1537228672809129 kg\n";
        } else {
            soma = 0ULL;
            for (double j = 0; j < c; j++)
                soma += pow(2, j);

            cout << (soma / 12000) << " kg\n";
        }
    }

    // system("PAUSE");
    return EXIT_SUCCESS;
}