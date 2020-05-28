#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <stdio.h>
#include <string.h>
using namespace std;

int main() {

    int i, j, n, t, ma;
    char frase[210];
    map<char, int> mapa;
    map<char, int>::iterator it;

    cin >> n;
    scanf("\n");
    for (i = 0; i < n; i++) {
        cin.getline(frase, 210);
        t = strlen(frase);
        for (j = 0; j < t; j++)
            if (isalpha(frase[j]) || isdigit(frase[j]))
                mapa[(int)(tolower(frase[j]))]++;
        ma = -1;
        for (it = mapa.begin(); it != mapa.end(); it++)
            if (it->second > ma)
                ma = it->second;
        for (it = mapa.begin(); it != mapa.end(); it++)
            if (it->second == ma)
                cout << it->first;
        cout << "\n";
        mapa.clear();
    }
    // system("PAUSE");
    return 0;
}
