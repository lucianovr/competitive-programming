#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a, c = b; i < c; ++i)
#define debug(x) cout << #x << " = " << x << "\n";
#define all(v) v.begin(), v.end()

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int bit[1010][1010];
int n, m;

unsigned int query(int x, int y0) {
    unsigned int r = 0;
    while (x > 0) {
        int y = y0;
        while (y > 0) {
            r += bit[x][y];
            y -= y & -y;
        }
        x -= x & -x;
    }
    return r;
}

void update(int x, int y0, unsigned int v) {
    while (x <= n) {
        int y = y0;
        while (y <= m) {
            bit[x][y] += v;
            y += y & -y;
        }
        x += x & -x;
    }
}

int main() {
    int p, x1, x2, y2, y1;
    unsigned int v;
    char op;
    while (scanf("%d %d %d", &n, &m, &p) && n != 0 && m != 0 && p != 0) {
        int consultas;
        scanf("%d", &consultas);

        for (int i = 0; i <= n; i++)
            for (int j = 0; j <= m; j++)
                bit[i][j] = 0;

        while (consultas--) {
            scanf(" %c", &op);
            if (op == 'A') {
                cin >> v;
                scanf("%d %d", &x1, &y1);
                x1++;
                y1++;
                update(x1, y1, v);
            } else {
                scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
                x1++;
                y1++;
                x2++;
                y2++;
                if (x1 > x2)
                    swap(x1, x2);
                if (y1 > y2)
                    swap(y1, y2);
                cout << (query(x2, y2) - query(x2, y1 - 1) - query(x1 - 1, y2) + query(x1 - 1, y1 - 1)) * p << "\n";
            }
        }
        printf("\n");
    }

    return 0;
}
