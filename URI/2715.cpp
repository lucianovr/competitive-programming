#include <cmath>
#include <iostream>

using namespace std;

long long int vetor1[1000001];
long long int vetor2[1000001];
long long int x[1000001];
int main() {
    std::ios::sync_with_stdio(false);
    int i;
    int n;
    long long int soma;
    long long int menor_diferenca;

    while (cin >> n) {
        soma = 0;

        for (i = 0; i < n; i++) {
            cin >> x[i];
            soma += x[i];
            vetor1[i] = soma;
        }

        soma = 0;
        for (i = n - 1; i >= 0; i--) {
            soma += x[i];
            vetor2[i] = soma;
        }

        menor_diferenca = abs(vetor2[1] - vetor1[0]);
        for (i = 2; i < n; i++)
            if (abs(vetor2[i] - vetor1[i - 1]) < menor_diferenca)
                menor_diferenca = abs(vetor2[i] - vetor1[i - 1]);

        cout << menor_diferenca << endl;
    }

    return 0;
}