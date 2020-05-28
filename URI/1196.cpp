#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;

int main() {
    char teclado[200], frase[999999];
    int i, t;

    /* numeros */ /*letras*/
    teclado[(int)'-'] = '0';
    teclado[(int)'W'] = 'Q';
    teclado[(int)'S'] = 'A';
    teclado[(int)'C'] = 'X';
    teclado[(int)'2'] = '1';
    teclado[(int)'E'] = 'W';
    teclado[(int)'D'] = 'S';
    teclado[(int)'V'] = 'C';
    teclado[(int)'3'] = '2';
    teclado[(int)'R'] = 'E';
    teclado[(int)'F'] = 'D';
    teclado[(int)'B'] = 'V';
    teclado[(int)'4'] = '3';
    teclado[(int)'T'] = 'R';
    teclado[(int)'G'] = 'F';
    teclado[(int)'N'] = 'B';
    teclado[(int)'5'] = '4';
    teclado[(int)'Y'] = 'T';
    teclado[(int)'H'] = 'G';
    teclado[(int)'M'] = 'N';
    teclado[(int)'6'] = '5';
    teclado[(int)'U'] = 'Y';
    teclado[(int)'J'] = 'H';
    teclado[(int)','] = 'M';
    teclado[(int)'7'] = '6';
    teclado[(int)'I'] = 'U';
    teclado[(int)'K'] = 'J';
    teclado[(int)'8'] = '7';
    teclado[(int)'O'] = 'I';
    teclado[(int)'L'] = 'K';
    teclado[(int)'9'] = '8';
    teclado[(int)'P'] = 'O';
    teclado[(int)';'] = 'L';
    teclado[(int)'0'] = '9';
    teclado[(int)'['] = 'P';
    teclado[(int)'X'] = 'Z';

    /* ACENTOS */
    teclado[(int)'1'] = '`';
    teclado[(int)']'] = '[';
    teclado[92] = ']';
    teclado[(int)'.'] = ',';
    teclado[(int)'/'] = '.';
    teclado[(int)'='] = '-';
    teclado[39] = ';';

    while (cin.getline(frase, 1000)) {
        t = strlen(frase);
        for (i = 0; i < t; i++)
            if (frase[i] != ' ')
                cout << teclado[(int)frase[i]];
            else
                cout << " ";
        cout << "\n";
    }

    // system("PAUSE");
    return 0;
}
