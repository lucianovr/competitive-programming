#include <cstdlib>
#include <iomanip>
#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
    cout << fixed << setprecision(2);
    int num, ht;
    float vh;

    cin >> num;
    cin >> ht;
    cin >> vh;

    cout << "NUMBER = " << num << endl;

    cout << "SALARY = U$ " << (ht * vh) << endl;

    system("PAUSE");
    return EXIT_SUCCESS;
}
