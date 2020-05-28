#include <iomanip>
#include <iostream>

using namespace std;
int main() {

    long long int x;
    int in = 0, out = 0, n;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (x >= 10 && x <= 20)
            in++;
        else
            out++;
    }
    cout << in << " in\n" << out << " out\n";

    return 0;
}