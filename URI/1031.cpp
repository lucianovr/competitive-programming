#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

int main() {

    vector<int> vect;
    int del, i, n, m, tam;

    while (scanf("%d", &n) && n) {
        m = 1;
        while (true) {
            vect.clear();
            for (i = 0; i < n; i++)
                vect.push_back(i + 1);
            tam = n;
            vect.erase(vect.begin() + 0);
            tam--;
            del = 0;
            while (tam > 1) {
                del = (del + m - 1) % tam--;
                vect.erase(vect.begin() + del);
            }
            if (vect[0] == 13)
                break;
            else
                m++;
        }
        printf("%d\n", m);
    }
    return 0;
}
