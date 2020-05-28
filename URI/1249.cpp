#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;

int main() {
    char frase[52], aux2;
    int t, i, rot = 13, aux;

    while (cin.getline(frase, 52)) {
        string resp;
        t = strlen(frase);
        for (i = 0; i < t; i++) {
            if (!(isalpha(frase[i])))
                resp += frase[i];

            else if (isupper(frase[i])) {
                aux = (frase[i] - 'A' + 1 + rot);
                if ((aux) > 26)
                    aux = (aux - 26);
                aux2 = (char)(aux + 'A' - 1);
                resp += aux2;
            } else {
                aux = (frase[i] - 'a' + 1 + rot);
                if ((aux) > 26)
                    aux = (aux - 26);
                aux2 = (char)(aux + 'a' - 1);
                resp += aux2;
            }
        }
        cout << resp << endl;
    }
    //  system("PAUSE");
    return 0;
}
