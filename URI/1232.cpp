#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <string.h>
#include <utility>
#include <vector>

using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define rep(i, n) for (int i = 0; i < (n); i = i + 1)
#define tr(it, S) for (typeof(S.begin()) it = S.begin(); it != S.end(); it++)
#define all(S) (S).begin(), (S).end()
#define pb push_back
#define contem(s, x) (s.find(x) != s.end())
int cont;
char FRONT[3][3], LEFT[3][3], RIGHT[3][3], BACK[3][3], UP[3][3], DOWN[3][3];

int igual(char up[3][3], char left[3][3], char front[3][3], char down[3][3], char right[3][3], char back[3][3]) {
    rep(i, 3) rep(j, 3) if (up[i][j] != UP[i][j]) return 0;
    rep(i, 3) rep(j, 3) if (left[i][j] != LEFT[i][j]) return 0;
    rep(i, 3) rep(j, 3) if (front[i][j] != FRONT[i][j]) return 0;
    rep(i, 3) rep(j, 3) if (down[i][j] != DOWN[i][j]) return 0;
    rep(i, 3) rep(j, 3) if (right[i][j] != RIGHT[i][j]) return 0;
    rep(i, 3) rep(j, 3) if (back[i][j] != BACK[i][j]) return 0;

    return 1;
}

void lerFaces(char up[3][3], char left[3][3], char front[3][3], char down[3][3], char right[3][3], char back[3][3]) {
    char a = 'a', b = 'b', c = 'c', d = 'd', e = 'e', f = 'f';

    rep(i, 3) rep(j, 3) up[i][j] = UP[i][j] = a;
    rep(i, 3) {
        rep(j, 3) left[i][j] = LEFT[i][j] = b;
        rep(j, 3) front[i][j] = FRONT[i][j] = c;
        rep(j, 3) right[i][j] = RIGHT[i][j] = d;
        rep(j, 3) back[i][j] = BACK[i][j] = e;
    }
    rep(i, 3) rep(j, 3) down[i][j] = DOWN[i][j] = f;
}

void Rotate(char m[3][3], int x) {
    if (x > 0) {
        int aux = m[0][0];
        m[0][0] = m[2][0];
        m[2][0] = m[2][2];
        m[2][2] = m[0][2];
        m[0][2] = aux;

        aux = m[1][0];
        m[1][0] = m[2][1];
        m[2][1] = m[1][2];
        m[1][2] = m[0][1];
        m[0][1] = aux;
    } else {
        int aux = m[0][0];
        m[0][0] = m[0][2];
        m[0][2] = m[2][2];
        m[2][2] = m[2][0];
        m[2][0] = aux;

        aux = m[1][0];
        m[1][0] = m[0][1];
        m[0][1] = m[1][2];
        m[1][2] = m[2][1];
        m[2][1] = aux;
    }
}

void func1(int x, char up[3][3], char left[3][3], char front[3][3], char down[3][3], char right[3][3],
           char back[3][3]) {
    int aux[3];
    if (x < 0) {
        rep(i, 3) aux[i] = up[i][0];
        rep(i, 3) up[i][0] = front[i][0];
        rep(i, 3) front[i][0] = down[i][0];
        rep(i, 3) down[i][0] = back[2 - i][2];
        rep(i, 3) back[2 - i][2] = aux[i];
    } else {
        rep(j, 3) {
            rep(i, 3) aux[i] = up[i][0];
            rep(i, 3) up[i][0] = front[i][0];
            rep(i, 3) front[i][0] = down[i][0];
            rep(i, 3) down[i][0] = back[2 - i][2];
            rep(i, 3) back[2 - i][2] = aux[i];
        }
    }
}

void func2(int x, char up[3][3], char left[3][3], char front[3][3], char down[3][3], char right[3][3],
           char back[3][3]) {
    int aux[3];

    if (x < 0) {
        rep(i, 3) aux[i] = up[2][i];
        rep(i, 3) up[2][i] = right[i][0];
        rep(i, 3) right[i][0] = down[0][2 - i];
        rep(i, 3) down[0][i] = left[i][2];
        rep(i, 3) left[2 - i][2] = aux[i];
    } else {
        rep(j, 3) {
            rep(i, 3) aux[i] = up[2][i];
            rep(i, 3) up[2][i] = right[i][0];
            rep(i, 3) right[i][0] = down[0][2 - i];
            rep(i, 3) down[0][i] = left[i][2];
            rep(i, 3) left[2 - i][2] = aux[i];
        }
    }
}

void func3(int x, char up[3][3], char left[3][3], char front[3][3], char down[3][3], char right[3][3],
           char back[3][3]) {
    int aux[3];
    if (x < 0) {
        rep(i, 3) aux[i] = front[i][2];
        rep(i, 3) front[i][2] = up[i][2];
        rep(i, 3) up[i][2] = back[2 - i][0];
        rep(i, 3) back[i][0] = down[2 - i][2];
        rep(i, 3) down[i][2] = aux[i];
    } else {
        rep(j, 3) {
            rep(i, 3) aux[i] = front[i][2];
            rep(i, 3) front[i][2] = up[i][2];
            rep(i, 3) up[i][2] = back[2 - i][0];
            rep(i, 3) back[i][0] = down[2 - i][2];
            rep(i, 3) down[i][2] = aux[i];
        }
    }
}
void func4(int x, char up[3][3], char left[3][3], char front[3][3], char down[3][3], char right[3][3],
           char back[3][3]) {
    int aux[3];
    if (x < 0) {
        rep(i, 3) aux[i] = right[i][2];
        rep(i, 3) right[i][2] = up[0][i];
        rep(i, 3) up[0][2 - i] = left[i][0];
        rep(i, 3) left[i][0] = down[2][i];
        rep(i, 3) down[2][2 - i] = aux[i];
    } else {
        rep(j, 3) {
            rep(i, 3) aux[i] = right[i][2];
            rep(i, 3) right[i][2] = up[0][i];
            rep(i, 3) up[0][2 - i] = left[i][0];
            rep(i, 3) left[i][0] = down[2][i];
            rep(i, 3) down[2][2 - i] = aux[i];
        }
    }
}

void func5(int x, char up[3][3], char left[3][3], char front[3][3], char down[3][3], char right[3][3],
           char back[3][3]) {
    int aux[3];
    if (x < 0) {
        rep(i, 3) aux[i] = back[0][i];
        rep(i, 3) back[0][i] = right[0][i];
        rep(i, 3) right[0][i] = front[0][i];
        rep(i, 3) front[0][i] = left[0][i];
        rep(i, 3) left[0][i] = aux[i];
    } else {
        rep(j, 3) {
            rep(i, 3) aux[i] = back[0][i];
            rep(i, 3) back[0][i] = right[0][i];
            rep(i, 3) right[0][i] = front[0][i];
            rep(i, 3) front[0][i] = left[0][i];
            rep(i, 3) left[0][i] = aux[i];
        }
    }
}

void func6(int x, char up[3][3], char left[3][3], char front[3][3], char down[3][3], char right[3][3],
           char back[3][3]) {
    int aux[3];
    if (x < 0) {
        rep(i, 3) aux[i] = front[2][i];
        rep(i, 3) front[2][i] = right[2][i];
        rep(i, 3) right[2][i] = back[2][i];
        rep(i, 3) back[2][i] = left[2][i];
        rep(i, 3) left[2][i] = aux[i];
    } else {
        rep(j, 3) {
            rep(i, 3) aux[i] = front[2][i];
            rep(i, 3) front[2][i] = right[2][i];
            rep(i, 3) right[2][i] = back[2][i];
            rep(i, 3) back[2][i] = left[2][i];
            rep(i, 3) left[2][i] = aux[i];
        }
    }
}

int main() {
    char up[3][3], left[3][3], front[3][3], right[3][3], down[3][3], back[3][3];
    lerFaces(up, left, front, down, right, back);
    string mov;
    while (cin >> mov) {
        cont = 0;
        int size = mov.size(), x;
        char face;
        do {
            rep(i, size) {
                if (mov[i] >= 'a' && mov[i] <= 'z')
                    x = -1;
                else
                    x = 1;

                face = toupper(mov[i]);

                if (face == 'L') {
                    Rotate(left, x);
                    func1(x, up, left, front, down, right, back);
                } else if (face == 'F') {
                    Rotate(front, x);
                    func2(x, up, left, front, down, right, back);
                } else if (face == 'R') {
                    Rotate(right, x);
                    func3(x, up, left, front, down, right, back);
                } else if (face == 'B') {
                    Rotate(back, x);
                    func4(x, up, left, front, down, right, back);
                } else if (face == 'U') {
                    Rotate(up, x);
                    func5(x, up, left, front, down, right, back);
                } else {
                    Rotate(down, x);
                    func6(x, up, left, front, down, right, back);
                }
            }
            cont++;
        } while (igual(up, left, front, down, right, back) != 1);

        cout << cont << endl;
    }
    return 0;
}
