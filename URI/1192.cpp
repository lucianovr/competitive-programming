#include <cstdlib>
#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    for (int k = 0; k < n; k++) {
        string dig;
        cin >> dig;
        if (dig[0] == dig[2])
            cout << (dig[0] - '0') * (dig[2] - '0') << endl;
        else if (dig[1] > 'A' && dig[1] < 'Z' || dig[1] == 'A' || dig[1] == 'Z')
            cout << (dig[2] - '0') - (dig[0] - '0') << endl;
        else
            cout << (dig[0] - '0') + (dig[2] - '0') << endl;
    }

    // system("PAUSE");
    return EXIT_SUCCESS;
}
