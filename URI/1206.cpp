#include <iostream>
#include <stdio.h>
using namespace std;
// FUNCOES
void imprime();
int testa_casa(int i, int y);
int PEAO(int i, int y);
int TORRE_RAINHA(int i, int y);
int BISPO_RAINHA(int i, int y);
int REI(int i, int y);

// VAR GLOBAIS
bool testa_flag;
int m[10][10];
void cria_matriz_m() {
    int i, j;
    for (j = 0; j < 10; j++) {
        m[0][j] = m[9][j] = 0;
    }
    for (i = 0; i < 10; i++) {
        m[i][0] = m[i][9] = 0;
    }
    for (i = 1; i < 9; i++)
        for (j = 1; j < 9; j++)
            m[i][j] = 1;
}

struct pos {
    int a, b; // linha, coluna
    pos() {}
    pos(int aa, int bb) {
        a = aa;
        b = bb;
    }
} mov[] = {pos(0, 0), pos(0, 1), pos(-1, 1), pos(-1, 0), pos(-1, -1), pos(0, -1), pos(1, -1), pos(1, 0), pos(1, 1)};

int main() {
    int npecas, i, j;
    string PECA;
    while (cin >> npecas) {
        cria_matriz_m();
        while (npecas--) {
            cin >> PECA;
            i = 9 - (PECA[2] - '0');
            j = (PECA[1] - 'a' + 1);
            if (PECA[0] == 'P')
                m[i][j] = 2;
            else if (PECA[0] == 'T')
                m[i][j] = 3;
            else if (PECA[0] == 'B')
                m[i][j] = 4;
            else if (PECA[0] == 'R')
                m[i][j] = 5;
            else if (PECA[0] == 'W')
                m[i][j] = 6;
        }
        cin >> PECA;
        i = 9 - (PECA[2] - '0');
        j = (PECA[1] - 'a' + 1);
        // imprime();
        testa_flag = true;
        for (int k = 0; k < 9; k++) {
            if (testa_casa(i + mov[k].a, j + mov[k].b) == 1) {
                testa_flag = false;
                printf("NAO\n");
                break;
            }
        }
        if (testa_flag)
            printf("SIM\n");
    }
    return 0;
}

int testa_casa(int i, int j) {

    if (m[i][j] == 0)
        return 0;
    else if (PEAO(i, j))
        return 0;
    else if (TORRE_RAINHA(i, j))
        return 0;
    else if (BISPO_RAINHA(i, j))
        return 0;
    else if (REI(i, j))
        return 0;
    // printf("casa livre %d %d\n", i, j);
    return 1;
}

int PEAO(int i, int j) {
    if (m[i - 1][j - 1] == 2)
        return 1; // tem peao
    if (m[i - 1][j + 1] == 2)
        return 1;
    return 0;
}

int TORRE_RAINHA(int i, int j) {
    int y, x;
    // anda na vertical e horizontal
    for (x = j + 1; x < 9; x++) { // horizontal direita
        if (m[i][x] == 0)
            break;
        if (m[i][x] == 3 || m[i][x] == 5)
            return 1;
        else if (m[i][x] != 1)
            break;
    }
    for (x = j - 1; x > 0; x--) { // horizontal esquerda
        if (m[i][x] == 0)
            break;
        if (m[i][x] == 3 || m[i][x] == 5)
            return 1;
        else if (m[i][x] != 1)
            break;
    }
    for (y = i + 1; y < 9; y++) { // vertical descendo
        if (m[y][j] == 0)
            break;
        if (m[y][j] == 3 || m[y][j] == 5)
            return 1;
        else if (m[y][j] != 1)
            break;
    }
    for (y = i - 1; y > 0; y--) { // vertical subindo
        if (m[y][j] == 0)
            break;
        if (m[y][j] == 3 || m[y][j] == 5)
            return 1;
        else if (m[y][j] != 1)
            break;
    }
    return 0;
}

int BISPO_RAINHA(int i, int j) {
    int y, x;
    // anda nas diagonais;
    y = i - 1;
    x = j + 1;
    for (x = j + 1; x < 9; x++) // direita subindo
    {
        if (m[y][x] == 0)
            break;
        else if (m[y][x] == 4 || m[y][x] == 5)
            return 1;
        else if (m[y][x] != 1)
            break;
        y--;
    }
    y = i + 1;
    x = j + 1;
    for (x = j + 1; x < 9; x++) // direita descendo
    {
        if (m[y][x] == 0)
            break;
        else if (m[y][x] == 4 || m[y][x] == 5)
            return 1;
        else if (m[y][x] != 1)
            break;
        y++;
    }
    y = i - 1;
    x = j - 1;
    for (x = j - 1; x > 0; x--) // esquerda subindo
    {
        if (m[y][x] == 0)
            break;
        else if (m[y][x] == 4 || m[y][x] == 5)
            return 1;
        else if (m[y][x] != 1)
            break;
        y--;
    }
    y = i + 1;
    x = j - 1;
    for (x = j - 1; x > 0; x--) // esquerda descendo
    {
        if (m[y][x] == 0)
            break;
        else if (m[y][x] == 4 || m[y][x] == 5)
            return 1;
        else if (m[y][x] != 1)
            break;
        y++;
    }
    return 0;
}

int REI(int i, int j) {
    int k, casa;
    for (k = 1; k < 9; k++) {
        casa = m[i + mov[k].a][j + mov[k].b];
        if (casa != 0) {
            if (casa == 6)
                return 1;
        }
    }
    return 0;
}
void imprime() {
    int i, j;
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++)
            printf("%d ", m[i][j]);
        printf("\n");
    }
}
