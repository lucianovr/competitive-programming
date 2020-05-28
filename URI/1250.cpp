#include <cstdlib>
#include <iostream>

using namespace std;

int main() {
    int n, t, cont, i /*indice*/;
    cin >> n;
    for (int k = 0; k < n; k++) {
        cin >> t;
        int tiros[t];
        string movimentos;
        for (i = 0; i < t; i++)
            cin >> tiros[i];
        cin >> movimentos;
        cont = 0;
        for (i = 0; i < t; i++) {
            if (movimentos[i] == 'J' && tiros[i] > 2)
                cont++;
            else if (movimentos[i] == 'S' && tiros[i] < 3)
                cont++;
        }
        cout << cont << endl;
    }
    // system("PAUSE");
    return EXIT_SUCCESS;
}
