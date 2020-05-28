#include <cstdlib>
#include <iostream>

using namespace std;

int main() {
    int v[11];

    for (int i = 0; i < 10; i++) {
        cin >> v[i];
        if (v[i] <= 0)
            v[i] = 1;
        cout << "X[" << i << "] = " << v[i] << endl;
    }

    // system("PAUSE");
    return EXIT_SUCCESS;
}