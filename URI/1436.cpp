#include <iostream>
using namespace std;

int main() {

    int t, n, v[12], i, j;
    cin >> t;
    for (j = 0; j < t; j++) {
        cin >> n;
        for (i = 0; i < n; i++)
            cin >> v[i];
        cout << "Case " << j + 1 << ": " << v[n / 2] << endl;
    }

    return 0;
}
