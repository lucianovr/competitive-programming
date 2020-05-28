#include <cstdlib>
#include <iostream>

using namespace std;

int main() {
    int a = 1, i, j, n;
    cin >> n;

    for (j = 0; j < n; j++)
        for (i = 0; i < 4; i++) {
            if (a % 4 == 0)
                cout << "PUM\n";
            else
                cout << a << " ";
            a++;
        }

    // system("PAUSE");
    return EXIT_SUCCESS;
}
