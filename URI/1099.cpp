#include <cmath>
#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
    int n, x, y, me, ma, soma;

    cin >> n;

    for (int j = 0; j < n; j++)

    {
        soma = 0;
        cin >> x >> y;
        ma = x;
        me = y;
        if (y > ma) {
            ma = y;
            me = x;
        }
        for (int i = (me + 1); i <= (ma - 1); i++)
            if (i % 2 != 0)
                soma += i;

        cout << soma << endl;
    }

    // system("PAUSE");
    return EXIT_SUCCESS;
}
