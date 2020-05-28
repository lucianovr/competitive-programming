#include <cstdlib>
#include <iostream>

using namespace std;

int main() {
    int n[100], ma = -1, pos_ma = 0;

    for (int i = 0; i < 100; i++) {
        cin >> n[i];
        if (n[i] > ma) {
            ma = n[i];
            pos_ma = i;
        }
    }
    cout << ma << endl;
    cout << pos_ma + 1 << endl;

    // system ("PAUSE");
    return 0;
}
