#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <ctype.h>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <utility>
#include <vector>
using namespace std;
#define fi first
#define se second
#define rep(i, n) for (int i = 0; i < (n); i = i + 1)
#define tr(it, S) for (typeof(S.begin()) it = S.begin(); it != S.end(); it++)
#define all(S) (S).begin(), (S).end()
#define pb push_back
#define sz size()
int main() {

    unsigned long long int c, p, q, r, s, x, y, a, b, A[100001], B[100001];
    int n;

    while (cin >> n) {
        cin >> p >> q >> r >> s >> x >> y >> a >> b;
        c = 0;
        for (int i = a, j = 1; j <= n; j++)
            A[j] = ((p * i) % x + (q * j) % x) % x;
        for (int i = 1, j = b; i <= n; i++)
            B[i] = ((r * i) % y + (s * j) % y) % y;

        for (int i = 1; i <= n; i++)
            c += A[i] * B[i];
        cout << c << "\n";
    }
    return 0;
}
