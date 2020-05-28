#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <string.h>
#include <string>
#include <utility>
#include <vector>
using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define rep(i, n) for (int i = 0; i < (n); i = i + 1)
#define tr(it, S) for (typeof(S.begin()) it = S.begin(); it != S.end(); it++)
#define all(S) (S).begin(), (S).end()
#define setar(S, x) memset(S, x, sizeof(S))
#define pb push_back
#define sz size()
bool pd[101][101][101];
int a[101], b[101], c[101];
int n;

bool func(int i, int j, int k) {
    if (pd[i][j][k] == true)
        return false;
    if (i == j && j == k && k == n)
        return true;

    if (i < n && a[i] % 3 == 0 && func(i + 1, j, k))
        return true;
    if (j < n && b[j] % 3 == 0 && func(i, j + 1, k))
        return true;
    if (k < n && c[k] % 3 == 0 && func(i, j, k + 1))
        return true;
    if (i < n && j < n && (a[i] + b[j]) % 3 == 0 && func(i + 1, j + 1, k))
        return true;
    if (i < n && k < n && (a[i] + c[k]) % 3 == 0 && func(i + 1, j, k + 1))
        return true;
    if (j < n && k < n && (b[j] + c[k]) % 3 == 0 && func(i, j + 1, k + 1))
        return true;
    if (i < n && j < n && k < n && (a[i] + b[j] + c[k]) % 3 == 0 && func(i + 1, j + 1, k + 1))
        return true;
    pd[i][j][k] = true;
    return false;
}

int main() {
    while (cin >> n && n) {
        rep(i, n) cin >> a[i] >> b[i] >> c[i];
        rep(i, 101) rep(j, 101) rep(k, 101) pd[i][j][k] = false;
        if (func(0, 0, 0))
            cout << 1 << endl;
        else
            cout << 0 << endl;
    }
    return 0;
}