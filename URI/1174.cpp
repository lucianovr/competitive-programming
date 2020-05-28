#include <cstdlib>
#include <iostream>

using namespace std;

int main() {
    float a[101];

    for (int i = 0; i < 100; i++) {
        cin >> a[i];
        if (a[i] <= 10)
            cout << "A[" << i << "] = " << a[i] << endl;
    }
    // system("PAUSE");
    return EXIT_SUCCESS;
}
