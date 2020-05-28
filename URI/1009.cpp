#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <stdio.h>
using namespace std;

int main(int argc, char *argv[]) {
    char nome[20];
    float sb, v;

    cin.getline(nome, 20);
    cin >> sb;
    cin >> v;

    cout << fixed << setprecision(2);
    cout << "TOTAL = R$ " << sb + v * 0.15 << endl;

    //    system("PAUSE");
    return EXIT_SUCCESS;
}
