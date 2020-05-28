#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <stack>
#include <vector>
#define rep(i, a, b) for (int i = a; i < b; i++)

using namespace std;

int pset[100002], sz[100002];

int findS(int i) {
    if (i != pset[i])
        pset[i] = findS(pset[i]);
    return pset[i];
}

int unio(int A, int B) {
    if (A != B) {
        if (sz[A] < sz[B]) {
            pset[A] = B;
            sz[B] += sz[A];
        } else {
            pset[B] = A;
            sz[A] += sz[B];
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    rep(i, 1, n + 1) {
        pset[i] = i;
        sz[i] = 1;
    }
    char op;
    int a, b, A, B;
    while (k--) {
        cin >> op >> a >> b;
        A = findS(a);
        B = findS(b);
        if (op == 'F') {
            unio(A, B);
        } else {
            if (A == B)
                cout << "S\n";
            else
                cout << "N\n";
        }
    }
}
