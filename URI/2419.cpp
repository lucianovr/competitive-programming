#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;
typedef long long int ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define rep(i, a, b) for (int _i = a, __i = b, i = _i; i < __i; i++)
#define Rep(i, a) rep(i, 0, a)
#define tr(it, S) for (typeof(S.begin()) it = S.begin(); it != S.end(); it++)
#define all(S) S.begin(), S.end()
#define pb push_back

int main() {
    int n, m, x, y;
    int c = 0;

    while (scanf("%d%d", &n, &m) != EOF) {
        c = 0;
        char grid[n + 5][m + 5];
        getchar();
        Rep(i, n) gets(grid[i]);
        int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
        Rep(i, n) Rep(j, m) {
            if (grid[i][j] == '#') {
                if (i == 0 || i == n - 1 || j == 0 || j == m - 1) {
                    c++;
                } else
                    Rep(k, 4) {
                        x = i + dx[k];
                        y = j + dy[k];
                        if (x >= 0 && x < n && y >= 0 && y < m) {
                            if (grid[x][y] == '.') {
                                c++;
                                break;
                            }
                        }
                    }
            }
        }

        cout << c << endl;
    }
    return 0;
}
