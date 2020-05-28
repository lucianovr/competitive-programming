#include <cstdlib>
#include <iostream>

using namespace std;

int main() {
    int n, aux, i, v[1008];

    aux = 0;
    cin >> n;
    for (i = 0; i < 1000; i++) {
        v[i] = aux;
        cout << "N[" << i << "] = " << v[i] << endl;
        aux++;
        if (aux == n)
            aux = 0;
    }

    // system("PAUSE");
    return 0;
}
