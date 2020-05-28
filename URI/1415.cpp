#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <string.h>
#include <utility>
#include <vector>

using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define rep(i, n) for (int i = 0; i < (n); i = i + 1)
#define tr(it, S) for (typeof(S.begin()) it = S.begin(); it != S.end(); it++)
#define all(S) (S).begin(), (S).end()
#define pb push_back
#define contem(s, x) (s.find(x) != s.end())
#define x first
#define y second

int dx[] = {-1, 1, 0, 0, 1, -1};
int dy[] = {0, 0, -1, 1, -1, 1};
int r, c;

char rot[100][100], m[100][100];

bool dentro(ii pos) { return (pos.x >= 0 && pos.x < r && pos.y >= 0 && pos.y < c); }

void func(ii pos, char s) {
    if (rot[pos.x][pos.y] == s)
        return;

    if (rot[pos.x][pos.y] == '.')
        rot[pos.x][pos.y] = s;
    else if (s == 'B' || rot[pos.x][pos.y] != s)
        rot[pos.x][pos.y] = 'B';

    char dir;
    s = rot[pos.x][pos.y];
    dir = s;
    if (s == ')')
        dir = '(';
    if (s == '(')
        dir = ')';

    rep(i, 6) {
        ii p = ii(pos.x + dx[i], pos.y + dy[i]);
        if (dentro(p) && m[p.x][p.y] != '.') // se p eh uma engrenagem
        {
            char rotacao = rot[p.x][p.y];

            if (rotacao == '.')
                func(p, dir);

            else if (rotacao == 'B' && dir != 'B')
                func(p, 'B');

            else if (rotacao != dir)
                func(p, 'B');
        }
    }
}

int main() {
    while (cin >> r >> c && r + c) {
        rep(i, r) rep(j, c) {
            rot[i][j] = '.';
            cin >> m[i][j];
        }

        rep(i, r) rep(j, c) if (m[i][j] == 'I') func(ii(i, j), '(');

        rep(i, r) rep(j, c) if (m[i][j] == '*' && rot[i][j] == '.') rot[i][j] = 'F';

        cout << endl;
        rep(i, r) {
            rep(j, c) cout << rot[i][j];
            cout << endl;
        }
    }
    return 0;
}