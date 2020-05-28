#include <cstdlib>
#include <iostream>
using namespace std;

int main() {
    int v[21], aux;

    for (int i = 0; i < 20; i++)
        cin >> v[i];

    for (int i = 0; i < 10; i++) {
        aux = v[i];
        v[i] = v[20 - i - 1];
        v[20 - i - 1] = aux;
    }

    for (int i = 0; i < 20; i++)
        cout << "N[" << i << "] = " << v[i] << endl;

    // system("PAUSE");
    return 0;
}