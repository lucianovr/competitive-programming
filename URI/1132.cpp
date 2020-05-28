
#include <cstdlib>
#include <iostream>
using namespace std;
int main() {
    int x, y, ma, me, soma = 0;

    cin >> x;
    cin >> y;

    ma = x;
    me = y;
    if (y > x) {
        ma = y;
        me = x;
    }

    for (int i = me; i <= ma; i++)
        if (i % 13 != 0)
            soma += i;
    cout << soma << endl;

    return 0;
}
