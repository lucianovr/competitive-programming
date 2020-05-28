#include <iostream>
using namespace std;
int main() {
    int n, a, b, ca, cb, i;

    while (cin >> n && n) {
        ca = cb = 0;
        for (i = 0; i < n; i++) {
            cin >> a >> b;
            if (a > b)
                ca++;
            else if (a < b)
                cb++;
        }
        cout << ca << " " << cb << endl;
    }
    return 0;
}
