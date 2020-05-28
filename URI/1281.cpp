#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <stdio.h>
using namespace std;

int main() {

    int i, N, pd, pc;

    string prod;
    float preco, qtd;
    map<string, float> feira;
    float soma;

    cout << fixed << setprecision(2);
    cin >> N;
    for (int n = 0; n < N; n++) {
        soma = 0;
        cin >> pd;
        for (i = 0; i < pd; i++) {
            cin >> prod >> preco;
            feira[prod] = preco;
        }
        cin >> pc;
        for (i = 0; i < pc; i++) {
            cin >> prod >> qtd;
            soma += feira[prod] * qtd;
        }
        cout << "R$ " << soma << endl;
        feira.clear();
    }

    // system("PAUSE");
    return 0;
}
