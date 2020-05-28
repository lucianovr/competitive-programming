#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <stdio.h>
using namespace std;
#define pb push_back
#define rep(i, a, b) for (int i(a); i < (b); i++)
#define debug(x) cout << #x << " = " << x << " ";
#define nl cout << "\n";

int main() {
    int casos, q, cont, P;
    map<string, double> MP;
    double peso, Cap, soma = 0;
    string nome;

    scanf("%d", &casos);
    while (casos--) {
        MP.clear();

        scanf("%d", &P);
        while (P--) {
            scanf("\n");
            getline(cin, nome);
            scanf("%lf", &peso);
            MP[nome] = peso;
        }

        soma = 0;
        scanf("%lf", &Cap);
        while (1) {
            scanf("\n");
            getline(cin, nome);
            scanf("%d", &q);
            if (nome == "-")
                break;

            if (MP[nome] == 0.0)
                cout << "NAO LISTADO: " << nome << "\n";
            else
                soma += q * MP[nome];
        }

        printf("Peso total: %.2lf kg\n", soma);
        cont = (int)ceil(soma / Cap);
        printf("Numero de trenos: %d\n\n", cont);
    }
    return 0;
}
