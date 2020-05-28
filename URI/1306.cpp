#include <cstdlib>
#include <iostream>
using namespace std;

int main() {
    int r, n, j = 0, let, comb;

    while (cin >> r >> n && r != 0 && n != 0) {
        let = -1;
        j++;
        if (26 * n + n < r)
            cout << "Case " << j << ": impossible\n";
        else {
            do {
                let++;
                comb = let * n + n;
            } while (comb < r); // comb>=r
            cout << "Case " << j << ": " << let << endl;
        }
    }
    return 0;
}
