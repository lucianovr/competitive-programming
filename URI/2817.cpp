#include <bits/stdc++.h>

using namespace std;

/*Retorna o somatorio dos elementos de uma submatriz em O(1).
 * Submatriz definida por canto superior esquerdo (x1,y1) e  canto
 * inferior direito (x2,y2) .: x1 <= x2 && y1 <= y2 */
#define MAXN 1000

int N, M;                            // linhas colunas
long long Moto[MAXN + 2][MAXN + 2];  // matriz de valores
long long Carro[MAXN + 2][MAXN + 2]; // matriz de valores

// precomputa as somas em O(N*M)
void precalMoto() {
    for (int x = 0; x < N; x++)
        for (int y = 0; y < M; y++) {
            if (x > 0)
                Moto[x][y] += Moto[x - 1][y];
            if (y > 0)
                Moto[x][y] += Moto[x][y - 1];
            if (x > 0 && y > 0)
                Moto[x][y] -= Moto[x - 1][y - 1];
        }
}

void precalCarro() {
    for (int x = 0; x < N; x++)
        for (int y = 0; y < M; y++) {
            if (x > 0)
                Carro[x][y] += Carro[x - 1][y];
            if (y > 0)
                Carro[x][y] += Carro[x][y - 1];
            if (x > 0 && y > 0)
                Carro[x][y] -= Carro[x - 1][y - 1];
        }
}

// retorna a soma da submatriz em O(1)
long long sumMoto(int x1, int y1, int x2, int y2) {
    long long soma = Moto[x2][y2];
    if (x1 > 0)
        soma -= Moto[x1 - 1][y2];
    if (y1 > 0)
        soma -= Moto[x2][y1 - 1];
    if (x1 > 0 && y1 > 0)
        soma += Moto[x1 - 1][y1 - 1];
    return soma;
}

// retorna a soma da submatriz em O(1)
long long sumCarro(int x1, int y1, int x2, int y2) {
    long long soma = Carro[x2][y2];
    if (x1 > 0)
        soma -= Carro[x1 - 1][y2];
    if (y1 > 0)
        soma -= Carro[x2][y1 - 1];
    if (x1 > 0 && y1 > 0)
        soma += Carro[x1 - 1][y1 - 1];
    return soma;
}

int main(int argc, char **argv) {
    cin >> N >> M;

    memset(Carro, 0, sizeof(Carro));
    memset(Moto, 0, sizeof(Moto));

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++) {
            char ch;
            cin >> ch;
            if (ch == 'M')
                Moto[i][j] = 1;
            else if (ch == 'C')
                Carro[i][j] = 1;
        }
    /*
    cout << "motos\n";
    for (int i = 0; i < N; i++){
            for (int j = 0; j < M; j++){
                    cout << Moto[i][j] << " ";
            } cout << endl;
    }
    
    cout << "carros\n";
    for (int i = 0; i < N; i++){
            for (int j = 0; j < M; j++){
                    cout << Carro[i][j] << " ";
            } cout << endl;
    }
    */

    precalMoto();
    precalCarro();

    int L;
    cin >> L;

    long long resp = -1;

    for (int i = 0; i <= N - L; i++) {
        for (int j = 0; j <= M - L; j++) {
            int x1 = i, y1 = j;
            int x2 = i + L - 1, y2 = j + L - 1;

            long long motos = sumMoto(x1, y1, x2, y2);
            long long carros = sumCarro(x1, y1, x2, y2);
            long long valor = motos * 12 + carros * 25;

            if (valor > resp && motos > 0 && carros > 0) {
                resp = valor;
            }
        }
    }

    cout << resp << endl;

    return 0;
}
