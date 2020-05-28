#include <cstdlib>
#include <iomanip>
#include <iostream>
using namespace std;

int main() {

    int n;
    float x, y;

    cin >> n;
    cout << fixed << setprecision(1);
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        if (y == 0)
            cout << "divisao impossivel\n";
        else
            cout << x / y << endl;
    }

    return 0;
}
