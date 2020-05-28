#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int main() {
    char frase[10002], aux;
    int n, t, i;

    cin >> n;
    scanf("\n");
    for (int N = 0; N < n; N++) {
        cin.getline(frase, 10002);
        t = strlen(frase);
        for (i = 0; i < t; i++)
            if (isalpha(frase[i]))
                frase[i] = frase[i] + 3;
        for (i = 0; i < t / 2; i++) {
            aux = frase[i];
            frase[i] = frase[t - i - 1];
            frase[t - i - 1] = aux;
        }

        for (i = t / 2; i < t; i++)
            frase[i] = frase[i] - 1;
        cout << frase << endl;
    }
    // system("PAUSE");
    return EXIT_SUCCESS;
}
