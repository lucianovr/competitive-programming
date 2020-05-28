#include <cmath>
#include <cstdlib>
#include <iostream>

using namespace std;

int main() {
    int x, y, i, me, ma, soma = 0;

    cin >> x;
    cin >> y;

    ma = x;
    me = y;
    if (y > ma) {
        ma = y;
        me = x;
    }

    for (i = (me + 1); i <= (ma - 1); i++) {
        if (i % 2 != 0)
            soma += i;
    }

    cout << soma << endl;

    // system("PAUSE");
    return EXIT_SUCCESS;
}