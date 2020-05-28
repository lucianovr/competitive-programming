#include <iostream>
#include <map>
#include <stdio.h>
#include <string.h>
using namespace std;
int D, mat[4][4];
char op, *pt1, *pt2, fline[310], sline[310], buffer[310], num[110];
map<string, int> bn;
string up, mid, baixo = "..";
map<int, string> cima, meio;

void extrair_braile(int tam);
void extrair_num(int tam);

int main() {
    mat[1][0] = 1;
    mat[1][1] = 2;
    mat[3][0] = 3;
    mat[3][2] = 4;
    mat[1][2] = 5;
    mat[3][1] = 6;
    mat[3][3] = 7;
    mat[1][3] = 8;
    mat[2][1] = 9;
    mat[2][3] = 0;

    bn[".."] = 0;
    bn["*."] = 1;
    bn[".*"] = 2;
    bn["**"] = 3;
    cima[0] = ".*";
    cima[1] = "*.";
    cima[2] = "*.";
    cima[3] = "**";
    cima[4] = "**";
    cima[5] = "*.";
    cima[6] = "**";
    cima[7] = "**";
    cima[8] = "*.";
    cima[9] = ".*";
    meio[0] = "**";
    meio[1] = "..";
    meio[2] = "*.";
    meio[3] = "..";
    meio[4] = ".*";
    meio[5] = ".*";
    meio[6] = "*.";
    meio[7] = "**";
    meio[8] = "**";
    meio[9] = "*.";

    while (cin >> D && D) {
        cin >> op;
        if (op == 'S') {
            scanf("\n");
            cin.getline(num, 110);
            extrair_braile(strlen(num));
        } else if (op == 'B') {
            scanf("\n");
            cin.getline(fline, 310);
            scanf("\n");
            cin.getline(sline, 310);
            scanf("\n");
            cin.getline(buffer, 310);
            extrair_num(strlen(fline));
        }
    }
    return 0;
}

void extrair_braile(int tam) {
    int j;
    cout << cima[num[0] - '0'];
    for (j = 1; j < tam; j++)
        cout << " " << cima[num[j] - '0'];
    cout << endl;
    cout << meio[num[0] - '0'];
    for (j = 1; j < tam; j++)
        cout << " " << meio[num[j] - '0'];
    cout << endl;
    cout << baixo;
    for (j = 1; j < tam; j++)
        cout << " " << baixo;
    cout << endl;

    return;
}

void extrair_num(int tam) {
    int j;
    up.clear();
    mid.clear();
    for (j = 0; j < tam; j++)
        if (fline[j] != ' ') {
            while (j < tam && fline[j] != ' ') {
                up += fline[j];
                mid += sline[j];
                j++;
            }
            cout << mat[bn[up]][bn[mid]];
            up.clear();
            mid.clear();
        }
    cout << endl;
    return;
}
