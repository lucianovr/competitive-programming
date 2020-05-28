#include <cstdlib>
#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
    string a, b, c;
    int j, i, t, tam, aa, bb, d;
    char u;

    cin >> t;
    scanf("\n");
    for (j = 0; j < t; j++) {
        while (u = getchar())
            if (u != '\n')
                c += u;
            else
                break;
        while (u = getchar())
            if (u != '\n')
                a += u;
            else
                break;
        while (u = getchar())
            if (u != '\n')
                b += u;
            else
                break;
        tam = c.size();
        aa = bb = d = 0;
        for (i = 0; i < tam; i++) {
            if (a[i] == c[i])
                aa++;
            if (b[i] == c[i])
                bb++;
            if (d == 0) {
                if (a[i] == c[i] && b[i] != c[i])
                    d = 1;
                else if (a[i] != c[i] && b[i] == c[i])
                    d = 2;
            }
        }
        c.clear();
        a.clear();
        b.clear();
        cout << "Instancia " << j + 1 << endl;
        if (d == 0)
            cout << "empate\n";
        else if (aa == bb)
            cout << "time " << d << endl;
        else if (aa > bb)
            cout << "time 1\n";
        else if (aa < bb)
            cout << "time 2\n";
        cout << endl;
    }
    // system("PAUSE");
    return 0;
}
