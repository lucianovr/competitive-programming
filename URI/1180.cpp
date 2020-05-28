#include <cstdlib>
#include <iostream>

using namespace std;

int main() {
    int v[1001], n, me, pos;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    me = v[0];
    pos = 0;
    for (int i = 1; i < n; i++) {
        if (v[i] < me) {
            me = v[i];
            pos = i;
        }
    }

    cout << "Menor valor: " << me << endl;
    cout << "Posicao: " << pos << endl;

    // system("PAUSE");
    return 0;
}