#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <ctype.h>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;
#define f first
#define s second
#define rep(i, n) for (int i = 0; i < (n); i = i + 1)
#define tr(it, S) for (typeof(S.begin()) it = S.begin(); it != S.end(); it++)
#define all(S) (S).begin(), (S).end()
#define pb push_back
#define max 101
int main() {
    int n, m, mat[max][max], sx = 0, sy = 0, x, mx = 0, my = 0;

    cin >> n >> m;
    rep(i, n) {
        rep(j, m) {
            cin >> x;
            sx += x;
            mat[i][j] = x;
        }
        if (sx > mx)
            mx = sx;
        sx = 0;
    }
    rep(j, m) {
        rep(i, n) { sy += mat[i][j]; }
        if (sy > my)
            my = sy;
        sy = 0;
    }
    int resp = my;
    if (mx > my)
        resp = mx;
    cout << resp << endl;

    return 0;
}
