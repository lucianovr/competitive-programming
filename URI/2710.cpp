#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i(a); i < (b); i++)

typedef pair<int, int> ii;
typedef long long ll;

const int NN = 500;
ll bit[501][501];
void update(int x, int y, ll v) {
    for (; x <= 500; x += x & (-x))
        for (int yy = y; yy <= 500; yy += yy & (-yy))
            bit[x][yy] += v;
}

ll query(int x, int y) {
    ll sum = 0;
    for (; x; x -= x & (-x))
        for (int yy = y; yy; yy -= yy & (-yy))
            sum += bit[x][yy];
    return sum;
}

void add(int x1, int y1, int x2, int y2, ll v) {
    update(x1, y1, v);
    update(x2 + 1, y1, -v);
    update(x1, y2 + 1, -v);
    update(x2 + 1, y2 + 1, v);
}

int main() {

    int Q, x1, y1, x2, y2;
    ll v;
    char op;

    for (int i = 0; i <= NN; i++)
        for (int j = 0; j <= NN; j++)
            bit[i][j] = 0;
    cin >> Q;
    while (Q--) // numero de operacoes
    {
        cin >> op;
        if (op == 'U') {
            cin >> x1 >> y1 >> x2 >> y2 >> v;
            add(x1, y1, x2, y2, v);
        } else {
            cin >> x1 >> y1;
            cout << query(x1, y1) << endl;
        }
    }
    return 0;
}