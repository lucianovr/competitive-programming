#include <cstdlib>
#include <iostream>

using namespace std;

int main() {
    long int n;

    cin >> n;
    for (int i = 1; i <= n; i++)
        cout << i << " " << i * i << " " << i * i * i << endl;

    // system("PAUSE");
    return EXIT_SUCCESS;
}
