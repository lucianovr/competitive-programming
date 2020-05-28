#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i(a); i < (b); i++)
#define debug(x) cout << #x << " = " << x << "\n";

#define ALL(c) c.begin(), c.end()
#define SORT(c) sort(ALL(c))
#define UNIQUE(c)                                                                                                      \
    {                                                                                                                  \
        SORT(c);                                                                                                       \
        (c).resize(unique(ALL(c)) - c.begin());                                                                        \
    }
#define pb push_back
#define sz size()
#define D(x)                                                                                                           \
    if (1)                                                                                                             \
        cout << __LINE__ << " " << #x " = " << (x) << endl;
#define D2(x, y)                                                                                                       \
    if (1)                                                                                                             \
        cout << __LINE__ << " " << #x " = " << (x) << ", " << #y " = " << (y) << endl;

typedef pair<int, int> ii;
typedef vector<int> VI;
typedef vector<ii> VII;
typedef long long LL;

int m[1010][1010], row, col;

int d[][2] = {
    {0, 0},   {-1, 0}, // 1
    {-1, 1},           // 2
    {0, 1},            // 3
    {1, 1},            // 4
    {1, 0},            // 5
    {1, -1},           // 6
    {0, -1},           // 7
    {-1, -1},          // 8
};

int func(int x = 0, int y = 0) {
    int cont = 0;
    while (m[x][y]) {
        cont++;
        int a = x + d[m[x][y]][0];
        int b = y + d[m[x][y]][1];
        m[x][y] = 0;

        x = a;
        y = b;
        if (x < 0 || y < 0 || x == row || y == col)
            break;
    }
    return cont;
}
int main() {
    int inst = 1;
    while (scanf("%d %d", &row, &col) == 2) {
        if (row == 0 && col == 0)
            break;
        rep(i, 0, row) rep(j, 0, col) scanf("%d", &m[i][j]);

        int cont = func();

        printf("Instancia %d\n", inst++);
        if (cont == row * col)
            printf("sim\n\n");
        else
            printf("nao\n\n");
    }
    return 0;
}
