#include <cmath>
#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
    int n, x, y, me, ma, soma;

    while (cin >> x >> y && (x > 0 && y > 0)) {
        soma = 0;
        ma = x;
        me = y;
        if (y > ma) {
            ma = y;
            me = x;
        }

        for (int i = me; i <= ma; i++) {
            cout << i << " ";
            soma += i;
        }
        cout << "Sum=" << soma << endl;
    }

    system("PAUSE");
}