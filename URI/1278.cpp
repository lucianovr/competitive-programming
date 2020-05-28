#include <cstring>
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int main() {
    int n, tam, nspc, aux = 0;
    char frase[55];
    char *pch;
    bool flag;

    while (cin >> n && n) {
        if (aux)
            cout << "\n";
        aux = 1;
        string s[n];
        int vet[n];
        cin.ignore();
        tam = 0;
        for (int i = 0; i < n; i++) {
            cin.getline(frase, 55);
            pch = strtok(frase, " ");
            flag = false;
            while (pch != NULL) {
                if (flag)
                    s[i] += " ";
                flag = true;
                s[i] += pch;
                pch = strtok(NULL, " ");
            }
            vet[i] = s[i].size();
            if (vet[i] > tam)
                tam = vet[i];
        }
        for (int i = 0; i < n; i++) {
            nspc = tam - vet[i];
            while (nspc--)
                cout << " ";
            cout << s[i] << "\n";
        }
    }
    return 0;
}
