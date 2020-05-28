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

int knapsack01(const vector<int> v, const vector<int> w, int W) {
    int m = v.sz;
    int A[m + 1][W + 1];
    for (int i = 0; i <= m; i++)
        A[i][0] = 0;
    for (int j = 0; j <= W; j++)
        A[0][j] = 0;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= W; j++) {
            if (w[i - 1] > j)
                A[i][j] = A[i - 1][j];
            else
                A[i][j] = max(A[i - 1][j], v[i - 1] + A[i - 1][j - w[i - 1]]);
        }
    return A[m][W];
}

int main() {
    int n, W;
    vi v, w;
    while (cin >> n && n) {
        v.resize(n);
        w.resize(n);
        cin >> W;
        rep(i, n) cin >> v[i] >> w[i];
        cout << knapsack01(v, w, W) << " min." << endl;
    }
    return 0;
}