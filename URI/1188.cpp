#include <cstdlib>
#include <iomanip>
#include <iostream>
using namespace std;
int main() {
    double m[13][13], s = 0;
    string op;

    cin >> op;

    for (int i = 0; i < 12; i++)
        for (int j = 0; j < 12; j++)
            cin >> m[i][j];
    int k = 0;
    int cont = 0;

    for (int i = 11; i >= 7; i--) {
        for (int j = 1 + k; j <= 10 - k; j++)
            s += m[i][j];
        k++;
    }
    cout << fixed << setprecision(1);

    if (op[0] == 'S')
        cout << s << endl;
    else if (op[0] == 'M')
        cout << s / 30.0 << endl;

    // system("PAUSE");
    return 0;
}
