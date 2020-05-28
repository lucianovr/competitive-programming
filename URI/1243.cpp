#include <algorithm>
#include <iostream>
#include <string.h>
using namespace std;

int main() {
    int n, soma, word, dot, leng;
    char frase[55], *pch;
    bool ehpalavra;

    while (cin.getline(frase, 55)) {
        soma = word = 0;
        pch = strtok(frase, " ");
        while (pch != NULL) {
            dot = 0;
            ehpalavra = true;
            leng = strlen(pch);
            for (int i = 0; i < leng; i++) {
                if (pch[i] == '.') {
                    if (dot) {
                        ehpalavra = false;
                        break;
                    } else
                        dot++;
                } else if (isdigit(pch[i])) {
                    ehpalavra = false;
                    break;
                }
            }
            if (ehpalavra) {
                if (dot == 0) {
                    word++;
                    soma += leng;
                } else if (pch[leng - 1] == '.') {
                    word++;
                    soma += leng - 1;
                }
            }
            pch = strtok(NULL, " ");
        }
        if (!word)
            cout << 250;
        else {
            int k = soma / word;
            if (k <= 3)
                cout << 250;
            else if (k <= 5)
                cout << 500;
            else
                cout << 1000;
        }
        cout << endl;
    }
    return 0;
}
