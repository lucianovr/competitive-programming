#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;

int main() {
    int N, n, i, c, t, r, aux;
    string frase;

    cin >> n;
    scanf("\n");
    for (N = 0; N < n; N++) {
        frase.clear();
        cin >> frase;
        t = frase.size();
        cin >> c;
        for (i = 0; i < t; i++) {
            aux = (int)(frase[i] - 'A');
            if ((aux - c) >= 0)
                cout << (char)(aux - c + 'A');
            else {
                r = abs(aux - c);
                cout << (char)(26 - r + 'A');
            }
        }
        cout << endl;
    }

    // system("PAUSE");
    return 0;
}
