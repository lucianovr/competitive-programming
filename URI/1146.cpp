#include <cstdlib>
#include <iostream>

using namespace std;

int main() {
    int n;

    while (cin >> n && n) {
        for (int i = 1; i < n; i++)
            cout << i << " ";
        cout << n << endl;
    }

    // system ("PAUSE");
    return 0;
}
