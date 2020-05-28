#include <cstdlib>
#include <iostream>

using namespace std;

int main() {
    int m;

    cin >> m;

    if (m == 1)
        cout << "January\n";
    else if (m == 2)
        cout << "February\n";
    else if (m == 3)
        cout << "March\n";
    else if (m == 4)
        cout << "April\n";
    else if (m == 5)
        cout << "May\n";
    else if (m == 6)
        cout << "June\n";
    else if (m == 7)
        cout << "July\n";
    else if (m == 8)
        cout << "August\n";
    else if (m == 9)
        cout << "September\n";
    else if (m == 10)
        cout << "October\n";
    else if (m == 11)
        cout << "November\n";
    else
        cout << "December\n";
    system("PAUSE");
    return EXIT_SUCCESS;
}