#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(c) (c).begin(), (c).end()
#define F first
#define S second
#define debug(x) cout << __LINE__ << ": " << #x << " = " << x << endl;
#define debug2(x, y) #x << " = " << x << "  " << #y << " = " << y << endl;
#define pb push_back
#define mk make_pair

const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;
typedef long long ll;
typedef pair<int, int> ii;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int R, C;
int m[200][200];
bool dentro(int x, int y) { return (x >= 0 && x < R && y >= 0 && y < C); }

int tam;
void dfs(int x, int y) {
    tam++;
    int cor = m[x][y];
    m[x][y] = -1;
    int a, b;
    rep(i, 0, 4) {
        a = x + dx[i];
        b = y + dy[i];
        if (dentro(a, b) && m[a][b] == cor)
            dfs(a, b);
    }
}

int DFS() {
    int menor = 200 * 200 + 10;
    rep(i, 0, R) {
        rep(j, 0, C) {
            if (m[i][j] != -1) {
                tam = 0;
                dfs(i, j);
                menor = min(menor, tam);
            }
        }
    }
    return menor;
}

int main() {
    while (cin >> R >> C) {
        rep(i, 0, R) rep(j, 0, C) scanf("%d", &m[i][j]);
        printf("%d\n", DFS());
    }
    return 0;
}
