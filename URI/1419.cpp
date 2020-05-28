#include <cstdlib>
#include <iostream>

using namespace std;

int main() {
    int st, sm, r, i, vm[11], vt[11];
    while (cin >> r && r) {
        sm = st = 0;
        for (i = 0; i < r; i++) {
            cin >> vm[i];
            sm += vm[i];
        }
        for (i = 0; i < r; i++) {
            cin >> vt[i];
            st += vt[i];
        }
        for (i = 0; i <= r - 3; i++) {
            if (vm[i] == vm[i + 1] && vm[i] == vm[i + 2] && (vt[i] != vt[i + 1] || vt[i] != vt[i + 2])) {
                sm += 30;
                break;
            }
            if ((vm[i] != vm[i + 1] || vm[i] != vm[i + 2]) && vt[i] == vt[i + 1] && vt[i] == vt[i + 2]) {
                st += 30;
                break;
            }
            if (vm[i] == vm[i + 1] && vm[i] == vm[i + 2] && vt[i] == vt[i + 1] && vt[i] == vt[i + 2])
                break;
        }
        if (sm > st)
            cout << "M\n";
        else if (st > sm)
            cout << "L\n";
        else if (st == sm)
            cout << "T\n";
    }

    return 0;
}
