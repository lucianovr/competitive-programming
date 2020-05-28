#include <algorithm>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <utility>
#include <vector>
using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define rep(i, a, b) for (int i = a; i < b; i++)
#define tr(it, S) for (typeof(S.begin()) it = S.begin(); it != S.end(); it++)
#define all(S) S.begin(), S.end()
#define STD std::ios::sync_with_stdio(false)

int main() {
    int m[20][20];

    int n;
    m[0][0] = 1;
    while (cin >> n && n) {
        for (int i = 1; i < n; i++)
            m[i][0] = m[i - 1][0] * 2;

        for (int i = 0; i < n; i++)
            for (int j = 1; j < n; j++)
                m[i][j] = m[i][j - 1] * 2;

        int spc = 0;
        int val = m[n - 1][n - 1];
        while (val) {
            val /= 10;
            spc++;
        }

        rep(i, 0, n) {
            rep(j, 0, n) {
                if (j != 0)
                    cout << " ";
                cout << setw(spc) << m[i][j];
            }
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}
