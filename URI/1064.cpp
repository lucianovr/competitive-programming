#include <cstdlib>
#include <iostream>

using namespace std;

int main() {
    float v[6], media = 0, cont = 0;

    for (int i = 0; i < 6; i++) {
        cin >> v[i];
        if (v[i] > 0) {
            cont++;
            media += v[i];
        }
    }
    cout << cont << " valores positivos\n";
    cout << media / cont << endl;

    // system("PAUSE");
    return EXIT_SUCCESS;
}
