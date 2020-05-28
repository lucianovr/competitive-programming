#include <iostream>
using namespace std;
int n, t, T, f, c;

int fib(int t) {

    if (t == 1)
        return 1;
    else if (t == 0)
        return 0;
    else {
        c += 2;
        return fib(t - 1) + fib(t - 2);
    }

    return 0;
}

int main() {

    cin >> n;
    for (int i = 0; i < n; i++) {
        c = 0;
        cin >> T;
        cout << "fib(" << T << ") = " << c << " calls = " << fib(T) << endl;
    }

    return 0;
}
