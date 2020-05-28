#include <cstdlib>
#include <iostream>
using namespace std;
int main() {
    int m, n, v8[8], v4[4], v2[2], i;
    for (i = 0; i < 8; i++) {
        cin >> m >> n;
        if (m > n)
            v8[i] = 'A' + i * 2;
        else
            v8[i] = 'A' + i * 2 + 1;
    }
    for (i = 0; i < 4; i++) {
        cin >> m >> n;
        if (m > n)
            v4[i] = v8[i * 2];
        else
            v4[i] = v8[i * 2 + 1];
    }
    for (i = 0; i < 2; i++) {
        cin >> m >> n;
        if (m > n)
            v2[i] = v4[i * 2];
        else
            v2[i] = v4[i * 2 + 1];
    }
    cin >> m >> n;
    if (m > n)
        cout << (char)v2[0] << endl;
    else
        cout << (char)v2[1] << endl;

    return 0;
}