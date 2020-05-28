#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <ctype.h>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <utility>
#include <vector>
using namespace std;
#define fi first
#define se second
#define rep(i, n) for (int i = 0; i < (n); i = i + 1)
#define tr(it, S) for (typeof(S.begin()) it = S.begin(); it != S.end(); it++)
#define all(S) (S).begin(), (S).end()
#define pb push_back
#define sz size()

bool bissexto(const string s) {
    int p = 1, soma = 0;
    bool bis = false;
    for (int i = s.sz - 1; i >= 0; i--) {
        soma = (soma % 4 + ((s[i] - '0') * p) % 4) % 4;
        p = (p * 10) % 4;
    }
    if (soma % 4 == 0)
        bis = true;

    soma = 0;
    p = 1;
    for (int i = s.sz - 1; i >= 0; i--) {
        soma = (soma % 100 + ((s[i] - '0') * p) % 100) % 100;
        p = (p * 10) % 100;
    }
    if (soma % 100 == 0)
        bis = false;

    if (bis)
        return true;

    soma = 0;
    p = 1;
    for (int i = s.sz - 1; i >= 0; i--) {
        soma = (soma % 400 + ((s[i] - '0') * p) % 400) % 400;
        p = (p * 10) % 400;
    }
    if (soma % 400 == 0)
        bis = true;
    return bis;
}

bool huluculu(const string s) {
    int p = 1, soma = 0;
    int t = s.sz - 1;
    if (s[t] != '5' && s[t] != '0')
        return false;

    for (int i = t; i >= 0; i--) {
        soma = (soma % 3 + ((s[i] - '0') * p) % 3) % 3;
        p = (p * 10) % 3;
    }
    if (soma % 3 == 0)
        return true;
    return false;
}

bool buluculu(const string s) {
    int p = 1, soma = 0;
    int t = s.sz - 1;
    if (s[t] != '5' && s[t] != '0')
        return false;

    for (int i = t; i >= 0; i--) {
        soma = (soma % 11 + ((s[i] - '0') * p) % 11) % 11;
        p = (p * 10) % 11;
    }
    if (soma % 11 == 0)
        return true;
}

int main() {

    string dig;
    bool b1, h1, b2;
    int aux = 0;
    while (cin >> dig) {
        b1 = h1 = b2 = false;

        if (aux)
            cout << "\n";
        else
            aux = 1;

        if (bissexto(dig)) {
            b1 = true;
        }
        if (huluculu(dig)) {
            h1 = true;
        }
        if (b1 && buluculu(dig)) {
            b2 = true;
        }

        if (!(b1 || h1 || b2))
            cout << "This is an ordinary year.\n";
        if (b1)
            cout << "This is leap year.\n";
        if (h1)
            cout << "This is huluculu festival year.\n";
        if (b2)
            cout << "This is bulukulu festival year.\n";
    }
    return 0;
}
