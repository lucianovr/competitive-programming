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

int seg[262150];

void update(int p, int a, int b, int i, int v) {
    if (a > i || b < i)
        return;
    if (a == b) {
        seg[p] = v;
        return;
    }
    update(p * 2, a, (a + b) / 2, i, v);
    update(p * 2 + 1, (a + b) / 2 + 1, b, i, v);
    seg[p] = seg[p * 2] * seg[p * 2 + 1];
}

int query(int p, int a, int b, int i, int j) {
    if (a > j || b < i)
        return 1;
    if (a >= i && b <= j)
        return seg[p];
    int x = query(p * 2, a, (a + b) / 2, i, j);
    int y = query(p * 2 + 1, (a + b) / 2 + 1, b, i, j);
    return x * y;
}

int main() {
    int n, q, a, b, v, p;
    char op;
    char resp[100010];
    int j;
    while (scanf("%d%d", &n, &q) == 2) {

        j = 0;
        rep(i, n) {
            scanf("%d", &v);
            if (v > 0)
                p = 1;
            else if (v < 0)
                p = -1;
            else
                p = 0;

            update(1, 0, n - 1, i, p);
        }
        while (q--) {
            scanf(" %c", &op);
            if (op == 'C') {
                scanf("%d%d", &a, &v);
                a--;
                if (v > 0)
                    p = 1;
                else if (v < 0)
                    p = -1;
                else
                    p = 0;
                update(1, 0, n - 1, a, p);
            } else {
                scanf("%d%d", &a, &b);
                a--;
                b--;
                a = query(1, 0, n - 1, a, b);
                if (a == 0)
                    resp[j] = '0';
                else if (a > 0)
                    resp[j] = '+';
                else if (a < 0)
                    resp[j] = '-';
                j++;
            }
        }
        resp[j] = '\0';
        printf("%s\n", resp);
    }
}
