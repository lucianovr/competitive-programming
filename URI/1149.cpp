#include <cstdlib>
#include <iostream>

using namespace std;

int main() {
    int a, n, soma = 0;
    cin >> a >> n;

    while (n <= 0)
        cin >> n;

    for (int i = a; i < n + a; i++)
        soma += i;
    cout << soma << endl;

    // system ("PAUSE");
    return 0;
}
