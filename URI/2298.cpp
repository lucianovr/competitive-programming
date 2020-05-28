#include <algorithm>
#include <cstdlib>
#include <iostream>
using namespace std;

int main() {
    int n, v[5], i, a, b, c, d, e;
    cin >> n;
    for (int j = 0; j < n; j++) {
        cout << "Teste " << j + 1 << endl;
        for (i = 0; i < 5; i++)
            cin >> v[i];
        sort(v, v + 5);
        a = v[0];
        b = v[1];
        c = v[2];
        d = v[3];
        e = v[4];
        if (a == b - 1 && b == c - 1 && c == d - 1 && d == e - 1)
            cout << a + 200; // x x+1 x+2 x+3 x+4
        else if (a == b && a == c && a == d || b == c && b == d && d == e)
            cout << c + 180; // x x x x y  ||  x y y y y
        else if (a == b && a == c && d == e)
            cout << a + 160; // x x x y y
        else if (a == b && c == d && c == e)
            cout << c + 160; // x x y y y
        else if ((a == b && a == c) || (b == c && b == d) || (c == d && c == e))
            cout << c + 140; // x x x y z  || x y y y z || x y z z z
        else if (a == b && c == d)
            cout << 3 * max(a, c) + 2 * min(a, c) + 20; // x x y y z
        else if (a == b && d == e)
            cout << 3 * max(a, d) + 2 * min(a, d) + 20; // x x y z z
        else if (b == c && d == e)
            cout << 3 * max(b, d) + 2 * min(b, d) + 20; // x y y z z
        else if (a == b)
            cout << a;
        else if (b == c)
            cout << b;
        else if (c == d)
            cout << c;
        else if (d == e)
            cout << d;
        else
            cout << 0;
        cout << "\n\n";
    }
}
