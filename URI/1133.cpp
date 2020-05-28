#include <cstdlib>
#include <iostream>
using namespace std;

void calcula(int a, int b) {

    for (int i = b + 1; i < a; i++)
        if (i % 5 == 2 || i % 5 == 3)
            cout << i << endl;
}

int main() {
    int x, y;
    cin >> x;
    cin >> y;

    if (x > y)
        calcula(x, y);
    else
        calcula(y, x);

    // system("PAUSE");
    return 0;
}
