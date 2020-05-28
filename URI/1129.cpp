#include <cstdlib>
#include <iostream>

using namespace std;

int main() {
    int n, v[6], cont, resp;

    while (cin >> n && n) {
        for (int j = 0; j < n; j++) {

            cont = 0;
            for (int i = 0; i < 5; i++) {
                cin >> v[i];
                if (v[i] <= 127) {
                    cont++;
                    resp = i;
                }
            }
            if (cont == 1)
                cout << (char)('A' + resp) << endl;

            else
                cout << "*\n";
        }
    }
    // system("PAUSE");
    return EXIT_SUCCESS;
}
