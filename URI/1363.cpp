#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <ctype.h>
#include <iostream>
#include <map>
#include <stdio.h>
#include <string.h>
#include <utility>
using namespace std;
#define fi first
#define se second
#define rep(i, n) for (int i = 0; i < (n); i = i + 1)
#define tr(it, S) for (typeof(S.begin()) it = S.begin(); it != S.end(); it++)
#define all(S) (S).begin(), (S).end()
#define pb push_back
#define sz size()

string SM, SI;
map<char, int> M;

long long int C;
long long int to_int_novo(string s);
long long int to_int_velho(string s);
void velho_velho();
void velho_novo();
void novo_novo();

bool check() {
    if (SI == SM)
        return false;
    if (isalpha(SI[3]) && isalpha(SI[4])) {
        char ch;
        rep(i, SI.sz) {
            ch = SI[i];
            if (ch == 'A' || ch == 'C' || ch == 'M' || ch == 'I' || ch == 'P')
                return false;
        }
        return true;
    } else if ((isdigit(SI[3]) && isalpha(SI[4])) || (isalpha(SI[3]) && isdigit(SI[4])))
        return false;
    return true;
}

int main() {
    bool flag;
    M['B'] = 0;
    M['F'] = 3;
    M['J'] = 6;
    M['N'] = 9;
    M['R'] = 12;
    M['U'] = 15;
    M['X'] = 18;
    M['D'] = 1;
    M['G'] = 4;
    M['K'] = 7;
    M['O'] = 10;
    M['S'] = 13;
    M['V'] = 16;
    M['Y'] = 19;
    M['E'] = 2;
    M['H'] = 5;
    M['L'] = 8;
    M['Q'] = 11;
    M['T'] = 14;
    M['W'] = 17;
    M['Z'] = 20;

    while (cin >> SM >> SI >> C && SM[0] != '*' && SI[0] != '*' && C) {
        flag = check();
        if (flag) {
            if (isdigit(SM[3]) && isdigit(SI[3]))
                velho_velho();
            else if (isalpha(SM[3]) && isalpha(SI[3]))
                novo_novo();
            else if (isdigit(SM[3]) && isalpha(SI[3]))
                velho_novo();
            else
                cout << "N\n";
        } else
            cout << "N\n";
    }
    return 0;
}

void velho_velho() {
    long long int VM, VI;
    VM = to_int_velho(SM);
    VI = to_int_velho(SI);
    if (VI <= VM)
        cout << "N\n";
    else if ((VI - VM) <= C)
        cout << "Y\n";
    else
        cout << "N\n";
}

void novo_novo() {
    long long int VM, VI;
    VM = to_int_novo(SM);
    VI = to_int_novo(SI);
    if (VI <= VM)
        cout << "N\n";
    else if ((VI - VM) <= C)
        cout << "Y\n";
    else
        cout << "N\n";
}
void velho_novo() {
    long long int VM, VI;
    VM = to_int_velho("ZZZ9999") - to_int_velho(SM);
    VI = to_int_novo(SI);
    if (VM + VI + 1 <= C)
        cout << "Y\n";
    else
        cout << "N\n";
}

long long int to_int_velho(string s) {
    long long int v;
    v = (s[0] - 'A') * 6760000LL + (s[1] - 'A') * 260000LL + (s[2] - 'A') * 10000LL;
    v += (s[3] - '0') * 1000LL + (s[4] - '0') * 100LL + (s[5] - '0') * 10LL + (s[6] - '0');
    return v;
}

long long int to_int_novo(string s) {
    int v;
    v = M[s[0]] * 19448100LL + M[s[1]] * 926100LL + M[s[2]] * 44100LL + M[s[3]] * 2100LL;
    v += M[s[4]] * 100LL + (s[5] - '0') * 10LL + (s[6] - '0');
    return v;
}