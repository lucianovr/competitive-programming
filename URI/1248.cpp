#include <algorithm>
#include <iostream>
#include <string.h>
using namespace std;

int n, d, c, a;
char diet[30], cof[30], alm[30];
bool flag;

int func(char ch) {
    for (int j = 0; j < d; j++) {
        if (diet[j] == ch) {
            diet[j] = '*';
            return 1;
        }
    }
    return 0;
}

int main() {

    cin >> n;
    scanf("\n");
    while (n--) {
        cin.getline(diet, 30);
        cin.getline(cof, 30);
        cin.getline(alm, 30);
        if (diet[0] == '\0')
            d = 0;
        else
            d = strlen(diet);
        if (cof[0] == '\0')
            c = 0;
        else
            c = strlen(cof);
        if (alm[0] == '\0')
            a = 0;
        else
            a = strlen(alm);
        if ((d + c + a) == 0)
            cout << endl;
        else if (d == 0)
            cout << "CHEATER\n";
        else if (d < (c + a))
            cout << "CHEATER\n";
        else {
            flag = true;
            for (int i = 0; i < c; i++)
                if (!func(cof[i])) {
                    flag = false;
                    break;
                }
            if (flag)
                for (int i = 0; i < a; i++)
                    if (!func(alm[i])) {
                        flag = false;
                        break;
                    }
            if (flag) {
                sort(diet, diet + d);
                for (int i = 0; i < d; i++)
                    if (diet[i] != '*')
                        cout << diet[i];
                cout << endl;
            } else
                cout << "CHEATER\n";
        }
    }
    return 0;
}