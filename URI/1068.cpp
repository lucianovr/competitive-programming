#include <cctype>
#include <iostream>
#include <string>
using namespace std;

int tam, i, cright, cleft; // tamanho da string
string ch;                 // caracteres

bool VERIFICA() {
    cright = cleft = 0;
    for (i = 0; i < tam; i++) {
        if (ch[i] == '(')
            cright++;
        else if (ch[i] == ')')
            cleft++;

        if (cleft > cright)
            return false;
    }

    if (cleft == cright)
        return true;
    else
        return false;
}

int main() {

    while (cin >> ch) {
        tam = ch.size();

        if (VERIFICA())
            cout << "correct\n";
        else
            cout << "incorrect\n";
    }

    // system ("pause");
    return 0;
}
