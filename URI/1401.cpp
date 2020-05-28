#include <iostream>
#include <map>
#include <string>
using namespace std;

char aux;
string word;
map<string, bool> mapa;
map<string, bool>::iterator T;

void ListPermutations();
void RecursivePermute(int k);
void ExchangeCharacteres(int p1, int p2);

int main() {
    int n;
    cin >> n;
    for (int t = 0; t < n; t++) {
        mapa.clear();
        cin >> word;
        ListPermutations();
        for (T = mapa.begin(); T != mapa.end(); T++)
            cout << T->first << endl;
        cout << endl;
    }

    return 0;
}

void ListPermutations() {
    RecursivePermute(0);
    return;
}

void RecursivePermute(int k) {
    int i, tam;
    tam = word.size();
    if (k == tam)
        mapa[word] = true;
    else
        for (i = k; i < tam; i++) {
            ExchangeCharacteres(k, i);
            RecursivePermute(k + 1);
            ExchangeCharacteres(i, k);
        }
    return;
}

void ExchangeCharacteres(int p1, int p2) {
    aux = word[p1];
    word[p1] = word[p2];
    word[p2] = aux;
    return;
}
