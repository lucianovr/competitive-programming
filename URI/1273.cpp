#include <cstdlib>
#include <cstring>
#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
    int n, tam[55], max, i, j, k, aux = 0;
    char word[55][55];

    while (cin >> n && n) {
        if (aux != 0)
            cout << endl;
        else
            aux = 1;

        max = -999;
        for (i = 0; i < n; i++) {
            scanf("\n");
            cin.getline(word[i], sizeof(word[i]));
            tam[i] = strlen(word[i]);
            if (tam[i] > max)
                max = tam[i];
        }
        for (i = 0; i < n; i++) {
            k = max - tam[i];
            if (k != 0) {
                for (j = 0; j < k; j++)
                    cout << " ";
                cout << word[i] << endl;
            } else
                cout << word[i] << endl;
        }
    }
    // system("PAUSE");
    return 0;
}