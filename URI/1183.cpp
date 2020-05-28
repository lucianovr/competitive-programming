#include <cstdlib>
#include <iomanip>
#include <iostream>
using namespace std;

int main() {
    float m[13][13], s = 0;
    string op;

    cin >> op;
    for (int i = 0; i < 12; i++)
        for (int j = 0; j < 12; j++)
            cin >> m[i][j];

    int k = 1;

    for (int i = 0; i < 11; i++) {
        for (int j = k; j < 12; j++)
            s += m[i][j];
        k++;
    }

    cout << fixed << setprecision(1);

    if (op[0] == 'S')
        cout << s << endl;
    else if (op[0] == 'M')
        cout << s / 66.0 << endl;

    // system("PAUSE");
    return EXIT_SUCCESS;
}