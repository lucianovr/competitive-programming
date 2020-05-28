#include <bits/stdc++.h>
using namespace std;
#define pi 3.1415926535897932384626433832795028841971693993751058209
#define rep(a, b, n) for (int a = b; a < n; a++)
#define debug(x) cout << #x << " = " << x << "\n";

typedef pair<int, int> ii;
typedef vector<ii> vii;

struct carro {
    int tamanho, pos;
} car[10010];

char vet[5000];
int C;
char Carro[5000];

int procura(int T) {
    for (int i = 0; i < T; i++)
        Carro[i] = '0';
    Carro[T] = '\0';

    int p = strstr(vet, Carro) - vet;
    return p;
}

// coloca o carro ou remove, carro com placa P que esta estacionado com inicio em i
void func(int P, char c) {
    for (int j = car[P].pos; j < car[P].pos + car[P].tamanho; ++j)
        vet[j] = c;
}

int main() {
    int n;
    int placa, tam, receita;
    char op;

    while (scanf("%d %d", &C, &n) != EOF) {
        receita = 0;

        memset(vet, '*', sizeof vet);
        for (int i = 0; i < C; i++)
            vet[i] = '0';
        for (int i = 0; i < 10010; i++)
            car[i].pos = -1;

        for (int k = 0; k < n; k++) {

            scanf(" %c %d", &op, &placa);

            if (op == 'C') {
                scanf("%d", &tam);
                car[placa].tamanho = tam;
                car[placa].pos = -1;
            }

            if (op == 'C') {
                int ret = procura(tam);
                // debug(ret);
                if (ret >= 0 && ret < C) {
                    car[placa].pos = ret;
                    receita += 10;
                    func(placa, '*');
                }
            }
            if (op == 'S')
                if (car[placa].pos != -1) {
                    func(placa, '0');
                    car[placa].pos = -1;
                }
        }
        printf("%d\n", receita);
    }
    return 0;
}