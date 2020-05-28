#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
    cout << fixed << setprecision(4);

    double x1, y1, x2, y2;

    cin >> x1 >> y1;
    cin >> x2 >> y2;

    cout << pow((pow((x1 - x2), 2.0) + pow((y1 - y2), 2.0)), (0.5)) << endl;

    system("PAUSE");
    return EXIT_SUCCESS;
}
