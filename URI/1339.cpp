#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <string.h>
#include <string>
#include <utility>
#include <vector>
using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define rep(i, n) for (int i = 0; i < (n); i = i + 1)
#define tr(it, S) for (typeof(S.begin()) it = S.begin(); it != S.end(); it++)
#define all(S) (S).begin(), (S).end()
#define setar(S, x) memset(S, x, sizeof(S))
#define pb push_back
#define sz size()
#define contem(s, x) (s.find(x) != s.end())

void lerFaces(char up[3][3], char left[3][3], char mid[3][3], char dow[3][3], char right[3][3], char other[3][3]) {
    rep(i, 3) rep(j, 3) cin >> up[i][j];
    rep(i, 3) {
        rep(j, 3) cin >> left[i][j];
        rep(j, 3) cin >> mid[i][j];
        rep(j, 3) cin >> right[i][j];
        rep(j, 3) cin >> other[i][j];
    }

    rep(i, 3) rep(j, 3) cin >> dow[i][j];
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

void func1(int x, char up[3][3], char left[3][3], char mid[3][3], char dow[3][3], char right[3][3], char other[3][3]) {
    int aux[3];
    if (x < 0) {
        rep(i, 3) aux[i] = up[i][0];
        rep(i, 3) up[i][0] = mid[i][0];
        rep(i, 3) mid[i][0] = dow[i][0];
        rep(i, 3) dow[i][0] = other[2 - i][2];
        rep(i, 3) other[2 - i][2] = aux[i];
    } else {
        rep(j, 3) {
            rep(i, 3) aux[i] = up[i][0];
            rep(i, 3) up[i][0] = mid[i][0];
            rep(i, 3) mid[i][0] = dow[i][0];
            rep(i, 3) dow[i][0] = other[2 - i][2];
            rep(i, 3) other[2 - i][2] = aux[i];
        }
    }
}

void func2(int x, char up[3][3], char left[3][3], char mid[3][3], char dow[3][3], char right[3][3], char other[3][3]) {
    int aux[3];

    if (x < 0) {
        rep(i, 3) aux[i] = up[2][i];
        rep(i, 3) up[2][i] = right[i][0];
        rep(i, 3) right[i][0] = dow[0][2 - i];
        rep(i, 3) dow[0][i] = left[i][2];
        rep(i, 3) left[2 - i][2] = aux[i];
    } else {
        rep(j, 3) {
            rep(i, 3) aux[i] = up[2][i];
            rep(i, 3) up[2][i] = right[i][0];
            rep(i, 3) right[i][0] = dow[0][2 - i];
            rep(i, 3) dow[0][i] = left[i][2];
            rep(i, 3) left[2 - i][2] = aux[i];
        }
    }
}

void func3(int x, char up[3][3], char left[3][3], char mid[3][3], char dow[3][3], char right[3][3], char other[3][3]) {
    int aux[3];
    if (x < 0) {
        rep(i, 3) aux[i] = mid[i][2];
        rep(i, 3) mid[i][2] = up[i][2];
        rep(i, 3) up[i][2] = other[2 - i][0];
        rep(i, 3) other[i][0] = dow[2 - i][2];
        rep(i, 3) dow[i][2] = aux[i];
    } else {
        rep(j, 3) {
            rep(i, 3) aux[i] = mid[i][2];
            rep(i, 3) mid[i][2] = up[i][2];
            rep(i, 3) up[i][2] = other[2 - i][0];
            rep(i, 3) other[i][0] = dow[2 - i][2];
            rep(i, 3) dow[i][2] = aux[i];
        }
    }
}
void func4(int x, char up[3][3], char left[3][3], char mid[3][3], char dow[3][3], char right[3][3], char other[3][3]) {
    int aux[3];
    if (x < 0) {
        rep(i, 3) aux[i] = right[i][2];
        rep(i, 3) right[i][2] = up[0][i];
        rep(i, 3) up[0][2 - i] = left[i][0];
        rep(i, 3) left[i][0] = dow[2][i];
        rep(i, 3) dow[2][2 - i] = aux[i];
    } else {
        rep(j, 3) {
            rep(i, 3) aux[i] = right[i][2];
            rep(i, 3) right[i][2] = up[0][i];
            rep(i, 3) up[0][2 - i] = left[i][0];
            rep(i, 3) left[i][0] = dow[2][i];
            rep(i, 3) dow[2][2 - i] = aux[i];
        }
    }
}

void func5(int x, char up[3][3], char left[3][3], char mid[3][3], char dow[3][3], char right[3][3], char other[3][3]) {
    int aux[3];
    if (x < 0) {
        rep(i, 3) aux[i] = other[0][i];
        rep(i, 3) other[0][i] = right[0][i];
        rep(i, 3) right[0][i] = mid[0][i];
        rep(i, 3) mid[0][i] = left[0][i];
        rep(i, 3) left[0][i] = aux[i];
    } else {
        rep(j, 3) {
            rep(i, 3) aux[i] = other[0][i];
            rep(i, 3) other[0][i] = right[0][i];
            rep(i, 3) right[0][i] = mid[0][i];
            rep(i, 3) mid[0][i] = left[0][i];
            rep(i, 3) left[0][i] = aux[i];
        }
    }
}

void func6(int x, char up[3][3], char left[3][3], char mid[3][3], char dow[3][3], char right[3][3], char other[3][3]) {
    int aux[3];
    if (x < 0) {
        rep(i, 3) aux[i] = mid[2][i];
        rep(i, 3) mid[2][i] = right[2][i];
        rep(i, 3) right[2][i] = other[2][i];
        rep(i, 3) other[2][i] = left[2][i];
        rep(i, 3) left[2][i] = aux[i];
    } else {
        rep(j, 3) {
            rep(i, 3) aux[i] = mid[2][i];
            rep(i, 3) mid[2][i] = right[2][i];
            rep(i, 3) right[2][i] = other[2][i];
            rep(i, 3) other[2][i] = left[2][i];
            rep(i, 3) left[2][i] = aux[i];
        }
    }
}

bool func(char up[3][3], char left[3][3], char mid[3][3], char dow[3][3], char right[3][3], char other[3][3]) {
    char c = up[0][0];
    rep(i, 3) rep(j, 3) if (up[i][j] != c) return false;

    c = left[0][0];
    rep(i, 3) rep(j, 3) if (left[i][j] != c) return false;

    c = mid[0][0];
    rep(i, 3) rep(j, 3) if (mid[i][j] != c) return false;

    c = right[0][0];
    rep(i, 3) rep(j, 3) if (right[i][j] != c) return false;

    c = dow[0][0];
    rep(i, 3) rep(j, 3) if (dow[i][j] != c) return false;

    c = other[0][0];
    rep(i, 3) rep(j, 3) if (other[i][j] != c) return false;
    return true;
}

int main() {
    int x;
    char up[3][3], left[3][3], mid[3][3], right[3][3], dow[3][3], other[3][3];

    int casos;
    cin >> casos;
    while (casos--) {
        lerFaces(up, left, mid, dow, right, other);
        while (cin >> x && x) {
            int r = x;
            if (x < 0)
                r = -x;

            if (r == 1) {
                Rotate(left, x);
                func1(x, up, left, mid, dow, right, other);
            } else if (r == 2) {
                Rotate(mid, x);
                func2(x, up, left, mid, dow, right, other);
            } else if (r == 3) {
                Rotate(right, x);
                func3(x, up, left, mid, dow, right, other);
            } else if (r == 4) {
                Rotate(other, x);
                func4(x, up, left, mid, dow, right, other);
            } else if (r == 5) {
                Rotate(up, x);
                func5(x, up, left, mid, dow, right, other);
            } else {
                Rotate(dow, x);
                func6(x, up, left, mid, dow, right, other);
            }
        }

        if (func(up, left, mid, dow, right, other))
            cout << "Yes, grandpa!\n";
        else
            cout << "No, you are wrong!\n";
    }

    return 0;
}