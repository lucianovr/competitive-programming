#include <bits/stdc++.h>
using namespace std;

bool f(char ch) {
    if (ch == 'G' || ch == 'Q' || ch == 'a' || ch == 'k' || ch == 'u') {
        cout << 0;
        return true;
    } else if (ch == 'I' || ch == 'S' || ch == 'b' || ch == 'l' || ch == 'v') {
        cout << 1;
        return true;
    } else if (ch == 'E' || ch == 'O' || ch == 'Y' || ch == 'c' || ch == 'm' || ch == 'w') {
        cout << 2;
        return true;
    } else if (ch == 'F' || ch == 'P' || ch == 'Z' || ch == 'd' || ch == 'n' || ch == 'x') {
        cout << 3;
        return true;
    } else if (ch == 'J' || ch == 'T' || ch == 'e' || ch == 'o' || ch == 'y') {
        cout << 4;
        return true;
    } else if (ch == 'D' || ch == 'N' || ch == 'X' || ch == 'f' || ch == 'p' || ch == 'z') {
        cout << 5;
        return true;
    } else if (ch == 'A' || ch == 'K' || ch == 'U' || ch == 'g' || ch == 'q') {
        cout << 6;
        return true;
    } else if (ch == 'C' || ch == 'M' || ch == 'W' || ch == 'h' || ch == 'r') {
        cout << 7;
        return true;
    } else if (ch == 'B' || ch == 'L' || ch == 'V' || ch == 'i' || ch == 's') {
        cout << 8;
        return true;
    } else if (ch == 'H' || ch == 'R' || ch == 'j' || ch == 't') {
        cout << 9;
        return true;
    }
    return false;
}

int main() {
    char n[100];
    char texto[100];
    int t;

    cin.getline(n, 100);
    t = atoi(n);
    while (t--) {
        cin.getline(texto, 100);
        //		cout << texto << "  " << strlen(texto) << endl;
        int tam = strlen(texto);
        for (int i = 0, cc = 0; i < tam && cc < 12; i++) {
            if (f(texto[i])) {
                cc++;
            }
        }
        cout << endl;
    }
    return 0;
}