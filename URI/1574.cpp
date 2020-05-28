#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <utility>
#include <vector>

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define rep(i, n) for (int i = 0; i < n; ++i)
#define tr(it, S) for (typeof(S.begin()) it = S.begin(); it != S.end(); it++)
#define all(S) S.begin(), S.end()
#define pb push_back
#define debug(x) cout << #x << " = " << x << endl;

#define print_array(arr)                                                                                               \
    rep(j, sizeof(arr) / sizeof(arr[0])) {                                                                             \
        if (j)                                                                                                         \
            cout << " ";                                                                                               \
        cout << arr[j];                                                                                                \
    }                                                                                                                  \
    cout << endl;

#define print_matrix(mat) rep(i, sizeof(mat) / sizeof(mat[0])){print_array(mat[i])};

const int INF = 0x3f3f3f3f;
const int NULO = -1;
const double pi = acos(-1); // 16 casas decimais
const int dx[] = {0, -1, 0, 1};
int dy[] = {-1, 0, 1, 0}; // ENWS

int main() {
    int t, n, k;
    string s;

    int memo[110];
    cin >> t;
    while (t--) {
        int pos = 0;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> s;
            if (s == "LEFT")
                memo[i] = -1;
            else if (s == "RIGHT")
                memo[i] = 1;
            else {
                cin >> s >> k;
                memo[i] = memo[k];
            }
            pos += memo[i];
        }
        printf("%d\n", pos);
    }
    return 0;
}
