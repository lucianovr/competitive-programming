#include <cstdlib>
#include <iostream>

using namespace std;

int main() {
    int i, B, N, p[20009], tot;

    while (cin >> B >> N && B + N) {
        int c[10009];
        for (i = 0; i <= B + 3; i++)
            c[i] = 0;
        for (i = 0; i < N; i++) { // leitura
            cin >> p[i];
        }
        for (i = 0; i < N; i++)
            c[p[i]]++;
        tot = 0;
        for (i = 1; i <= B; i++)
            if (c[i] > 1)
                tot++;
        cout << tot << endl;

    } // while
    // system("PAUSE");
    return 0;
}