#include <cctype>
#include <cstring>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
int cont, x, y, s, l, c, t;
char m[101][101];

void anda(char ac) {
    if (ac == 'F') {
        if (s == 0 && x - 1 >= 0 && m[x - 1][y] != '#')
            x--;
        else if (s == 1 && y + 1 < c && m[x][y + 1] != '#')
            y++;
        else if (s == 2 && x + 1 < l && m[x + 1][y] != '#')
            x++;
        else if (s == 3 && y - 1 >= 0 && m[x][y - 1] != '#')
            y--;
        if (m[x][y] == '*') {
            m[x][y] = '.';
            cont++;
        }

    } else {
        if (ac == 'D')
            s = (s + 1) % 4;
        else if (ac == 'E')
            s = (s - 1 + 4) % 4;
    }
}

int main() {

    string com;
    int i, j;
    while (cin >> l >> c >> t && l + c + t) {
        scanf("\n");
        for (i = 0; i < l; i++)
            for (j = 0; j < c; j++) {
                cin >> m[i][j];
                if (isalpha(m[i][j])) {
                    x = i;
                    y = j;
                    if (m[i][j] == 'N')
                        s = 0;
                    else if (m[i][j] == 'L')
                        s = 1;
                    else if (m[i][j] == 'S')
                        s = 2;
                    else
                        s = 3;
                }
            }
        cont = 0;
        cin >> com;

        for (i = 0; i < t; i++)
            anda(com[i]);
        cout << cont << endl;
    }
    return 0;
}