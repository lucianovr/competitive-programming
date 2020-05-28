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
#define contem(s, x) (s.find(x) != s.end())

int main() {
    int n;
    while (cin >> n) {
        int m[n][n];
        rep(i, n) rep(j, n) {
            if ((i + j) == n - 1)
                m[i][j] = 2;
            else if (i == j)
                m[i][j] = 1;
            else
                m[i][j] = 3;
        }
        rep(i, n) {
            rep(j, n) cout << m[i][j];
            cout << endl;
        }
    }
    return 0;
}
