#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int N, n;
bool flag;
map<int, string> mapa;
struct PLAYER {
    int c; // carta
    int a; // ativo? 1-sim, 0-nao
} p[21];
queue<int> F;

bool distribuir(int k);
void saida();

int main() {

    string nome;
    int carta;
    while (scanf("%d", &n) && n) {
        N = n;
        mapa.clear();
        while (!F.empty())
            F.pop();
        for (int i = 0; i < n; i++) {
            cin >> nome;
            mapa[i] = nome;
            p[i].a = 1;
        }
        for (int i = 0; i < 52; i++) {
            scanf("%d", &carta);
            F.push(carta);
        }
        flag = true;
        while (n != 1) {
            if (F.size() < n)
                break;
            else if (distribuir(n) == true)
                break;
        }
        if (flag == true)
            saida();
    }
    return 0;
}

bool distribuir(int k) {
    int i, j, me = 60, cont = 0, v[n + 1];
    for (i = 0; i < N; i++) {
        if (cont == n)
            break;
        if (p[i].a == 1) {
            cont++;
            p[i].c = F.front();
            F.pop();
            if (p[i].c < me)
                me = p[i].c;
        }
    }
    j = cont = 0;
    for (i = 0; i < N; i++) {
        if (p[i].a == 1 && p[i].c == me) {
            v[j++] = i;
            n--;
        }
    }
    if (n == 0) {
        flag = false;
        saida();
        return true;
    } else
        for (i = 0; i < j; i++)
            p[v[i]].a = 0;

    return false;
}

void saida() {
    int i;
    for (i = 0; i < N; i++)
        if (p[i].a == 1)
            cout << mapa[i] << " ";
    printf("\n");
}