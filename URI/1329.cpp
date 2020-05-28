#include <cstdlib>
#include <iostream>

using namespace std;

int main() {

    int n, maria, joao;
    short b;
    while (cin >> n && n) {
        maria = 0;
        joao = 0;
        for (int i = 0; i < n; i++) {
            cin >> b;
            if (b)
                joao++;
            else
                maria++;
        }
        cout << "Mary won " << maria << " times and John won " << joao << " times\n";
    }

    // system("pause");
    return 0;
}