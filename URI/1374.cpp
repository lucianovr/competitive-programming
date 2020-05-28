#include <algorithm>
#include <cstring>
#include <iostream>
#include <map>
#include <stdio.h>
#include <string.h>
#include <utility>
#include <vector>
#define f first
#define s second
#define rdi(a) scanf("%d", &a)
#define rdii(a, b) scanf("%d%d", &a, &b)
#define ulli unsigned long long int
using namespace std;

int soma, cont;

struct date {
    int dia, mes, ano, consumo;
} atual[1001];

void IsEqual(int j, date amanha) {
    date prox = atual[j];
    if (prox.dia == amanha.dia && prox.mes == amanha.mes && prox.ano == amanha.ano) {
        cont++;
        soma += prox.consumo - atual[j - 1].consumo;
    }
}
bool IsBissexto(int ano) {
    if (ano % 4 == 0 && ano % 100 != 0)
        return true;
    return false;
}
void func(int i) {
    date amanha = atual[i];

    if (atual[i].mes == 2) {
        if (atual[i].dia < 28)
            amanha.dia++;
        else if (atual[i].dia == 28) {
            if (IsBissexto(atual[i].ano))
                amanha.dia++;
            else {
                amanha.dia = 1;
                amanha.mes++;
            }
        } else {
            amanha.dia = 1;
            amanha.mes++;
        }
    } else if (atual[i].dia < 30)
        amanha.dia++;
    else if (atual[i].dia == 30) {
        if (atual[i].mes == 4 || atual[i].mes == 6 || atual[i].mes == 9 || atual[i].mes == 11) {
            amanha.dia = 1;
            amanha.mes++;
        } else {
            amanha.dia++;
        }
    } else if (atual[i].dia == 31) {
        if (atual[i].mes == 1 || atual[i].mes == 3 || atual[i].mes == 5 || atual[i].mes == 7 || atual[i].mes == 8 ||
            atual[i].mes == 10) {
            amanha.dia = 1;
            amanha.mes++;
        } else if (atual[i].mes == 12) {
            amanha.dia = 1;
            amanha.mes = 1;
            amanha.ano++;
        }
    }
    IsEqual(i + 1, amanha);
}

int main() {

    int n;
    while (rdi(n) && n) {
        soma = cont = 0;
        for (int i = 0; i < n; i++)
            scanf("%d%d%d%d", &atual[i].dia, &atual[i].mes, &atual[i].ano, &atual[i].consumo);

        for (int i = 0; i < n - 1; i++)
            func(i);
        cout << cont << " " << soma << endl;
    }

    return 0;
}
