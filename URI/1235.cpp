#include <cstdlib>
#include <cstring>
#include <iostream>
#include <stdio.h>

using namespace std;

int main() {

    int n, tam, i, j, k;
    char frase[1002];
    cin >> n;
    getchar();
    for (int l = 0; l < n; l++) {

        cin.getline(frase, 1002);
        tam = strlen(frase);

        j = tam / 2 - 1;
        k = tam / 2;

        for (i = j; i >= 0; i--)
            cout << frase[i];
        for (i = tam - 1; i >= k; i--)
            cout << frase[i];
        cout << endl;
    } // for
    // system("PAUSE");
    return 0;
}