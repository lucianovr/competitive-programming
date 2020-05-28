#include <iostream>

using namespace std;
int a[100000], b[100000], ca, cb, n, A, B, i, ma;

void func();

int main() {

    while (cin >> A >> B && A + B) {
        for (i = 1; i <= 100000; i++) {
            a[i] = 0;
            b[i] = 0;
        }
        ca = cb = ma = 0;
        for (i = 0; i < A; i++) {
            cin >> n;
            a[n]++;
            if (n > ma)
                ma = n;
        }
        for (i = 0; i < B; i++) {
            cin >> n;
            b[n]++;
            if (n > ma)
                ma = n;
        }
        func();
    }
    return 0;
}

void func() {

    for (int k = 1; k <= ma; k++)
        if (a[k] > 0 && b[k] == 0)
            ca++;
        else if (a[k] == 0 && b[k] > 0)
            cb++;

    if (ca > cb)
        cout << cb;
    else
        cout << ca;
    cout << endl;

    return;
}
