#include <iostream>

using namespace std;

int main() {

    int n, a;
    bool ok = true;
    cin >> n;
    cin >> a;
    for (int i = 1; i < n; i++) {
        int x;
        cin >> x;
        if (x > a)
            ok = false;
    }

    if (ok)
        puts("S");
    else
        puts("N");

    return 0;
}