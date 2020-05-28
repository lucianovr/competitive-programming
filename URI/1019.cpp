#include <cmath>
#include <cstdlib>
#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
    int t, h, m;

    cin >> t;

    h = floor(t / 3600);
    t %= 3600;
    m = floor(t / 60);
    t %= 60;

    cout << h << ":" << m << ":" << t << endl;

    system("PAUSE");
    return EXIT_SUCCESS;
}
