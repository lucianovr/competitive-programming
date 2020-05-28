#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <map>
#include <stdio.h>
#include <string.h>
using namespace std;

int main() {
    map<string, int> mapa;
    map<string, int>::iterator T;
    int n, i;
    double tam;
    char tree[35];

    cin >> n;
    ;
    cout << fixed << setprecision(4);
    scanf("\n");
    for (i = 0; i < n; i++) {
        tam = 0;
        while (cin.getline(tree, 35) && tree[0] != 0) {
            mapa[tree]++;
            tam++;
        }

        for (T = mapa.begin(); T != mapa.end(); T++)
            cout << T->first << " " << ((T->second) / tam) * 100.0000 << endl;
        if (i != n - 1)
            cout << endl;
        mapa.clear();
    }

    // system("PAUSE");
    return EXIT_SUCCESS;
}
