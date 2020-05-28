#include <iostream>
using namespace std;

void func(int n, int count);

int main() {
    int a, c;
    while (cin >> a && a) {
        if (a == 1)
            cout << 0 << endl;
        else {
            c = 0;
            func(a, c);
        }
    }

    return 0;
}

void func(int n, int count) {
    if (n == 3 || n == 2) {
        count++;
        cout << count << endl;
    } else if (n % 3 == 0) {
        n = n / 3;
        count += n;
        func(n, count);
    } else {
        n = n / 3 + 1;
        count += n;
        func(n, count);
    }
}
