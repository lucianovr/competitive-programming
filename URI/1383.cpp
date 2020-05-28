#include <algorithm>
#include <cstring>
#include <iostream>
#include <map>
#include <stdio.h>
#include <string.h>
#include <utility>
#include <vector>
#define f first
#define s second
#define rdi(a) scanf("%d", &a)
#define rdii(a, b) scanf("%d%d", &a, &b)
#define ulli unsigned long long int
using namespace std;

int main() {

    map<int, bool> mp;
    int n, mat[10][10];
    bool flag;

    rdi(n);
    for (int k = 1; k <= n; k++) {
        cout << "Instancia " << k << endl;
        for (int i = 0; i < 9; i++)
            for (int j = 0; j < 9; j++)
                cin >> mat[i][j];
        flag = true;
        for (int i = 0; i < 9; i++) {
            mp.clear();
            for (int j = 0; j < 9; j++)
                mp[mat[i][j]] = true;
            if (mp.size() != 9) {
                flag = false;
                break;
            }
        }
        if (flag) {
            for (int j = 0; j < 9; j++) {
                mp.clear();
                for (int i = 0; i < 9; i++)
                    mp[mat[i][j]] = true;
                if (mp.size() != 9) {
                    flag = false;
                    break;
                }
            }
        }

        if (flag) {
            for (int i = 0; i < 7 && flag; i += 3) {
                for (int j = 0; j < 7 && flag; j += 3) {
                    mp.clear();
                    for (int l = i; l < i + 3; l++) {
                        for (int k = j; k < j + 3; k++)
                            mp[mat[l][k]] = true;
                    }
                    if (mp.size() != 9) {
                        flag = false;
                        break;
                    }
                }
            }
        }

        if (flag)
            cout << "SIM\n\n";
        else
            cout << "NAO\n\n";
    }
    return 0;
}
