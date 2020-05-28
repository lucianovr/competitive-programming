#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <stdio.h>
using namespace std;

int main() {

    map<string, int> cargo;
    int i, cargos, ndescricoes, money;
    string word;
    unsigned long long int soma;

    cin >> cargos >> ndescricoes;
    for (i = 0; i < cargos; i++) {
        cin >> word >> money;
        cargo[word] = money;
    }
    for (i = 0; i < ndescricoes; i++) {
        soma = 0ULL;
        while (cin >> word && word != ".") {
            soma += cargo[word];
        }
        cout << soma << endl;
    }

    // system("PAUSE");
    return 0;
}
