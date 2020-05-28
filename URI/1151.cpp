#include <cstdlib>
#include <iostream>

using namespace std;

int main() {
    int v[47], n;

    v[0] = 0;
    v[1] = 1;
    v[2] = 1;
    v[3] = 2;

    cin >> n;
    for (int i = 2; i < n; i++)
        v[i] = v[i - 1] + v[i - 2];

    for (int i = 0; i < n - 1; i++)
        cout << v[i] << " ";

    cout << v[n - 1] << endl;
    // system ("PAUSE");
    return 0;
}
