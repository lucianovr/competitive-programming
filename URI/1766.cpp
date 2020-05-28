#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
#define pb push_back
#define rep(i, a, b) for (int i(a); i < (b); i++)
#define debgu(x) cout << #x << " = " << x;
#define nl cout << "\n";

struct rena {
    string nome;
    int peso, idade;
    double altura;

    // rena(){}
    rena(string n = "", int p = 0, int i = 0, double a = 0.0) : nome(n), peso(p), idade(i), altura(a) {}
};

rena v[1100];

bool comp(rena A, rena B) {
    if (A.peso > B.peso)
        return true;
    if (A.peso < B.peso)
        return false;

    if (A.idade < B.idade)
        return true;
    if (A.idade > B.idade)
        return false;

    if (A.altura < B.altura)
        return true;
    if (A.altura > B.altura)
        return false;

    return A.nome < B.nome;
}

int main() {
    int N, M;
    int T;
    string nome;
    int peso, idade;
    double altura;

    scanf("%d", &T);
    rep(t, 1, T + 1) {
        scanf("%d %d", &N, &M);

        rep(i, 0, N) {
            cin >> nome >> peso >> idade >> altura;
            v[i] = rena(nome, peso, idade, altura);
        }

        sort(v, v + N, comp);

        printf("CENARIO {%d}\n", t);
        rep(i, 0, M) {
            printf("%d - ", i + 1);
            cout << v[i].nome << "\n";
        }
    }
    return 0;
}
