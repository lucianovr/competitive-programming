#include <cstdlib>
#include <cstring>
#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

int main(int argc, char *argv[]) {

    char frase[51];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        scanf("\n");
        cin.getline(frase, 51);
        string resp;
        bool teste = true;
        int tam = strlen(frase);
        for (int j = 0; j <= tam - 1; j++) {
            if (frase[j] >= 'a' && frase[j] <= 'z') {
                if (teste) {
                    resp += frase[j];
                    teste = false;
                }
            } else
                teste = true;
        }
        cout << resp << endl;
    }

    // system("PAUSE");
    return EXIT_SUCCESS;
}
