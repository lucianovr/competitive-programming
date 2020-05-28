#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)

string g[201];
int R, C, cor[201][201];
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};
int brancos;

#define RED 0
#define BLACK 1
#define BLUE 2

bool dentro(int xx, int yy) { return xx >= 0 && yy >= 0 && xx < R && yy < C * 4 && cor[xx][yy] == -1; }

void dfs_red(int x, int y) {
    cor[x][y] = RED;
    int xx, yy;
    for (int i = 0; i < 4; i++) {
        xx = x + dx[i];
        yy = y + dy[i];
        if (dentro(xx, yy)) {
            if (g[xx][yy] == '0')
                dfs_red(xx, yy);
        }
    }
}

void dfs_blue(int x, int y) {
    cor[x][y] = BLUE;
    int xx, yy;
    for (int i = 0; i < 4; i++) {
        xx = x + dx[i];
        yy = y + dy[i];
        if (dentro(xx, yy)) {
            if (g[xx][yy] == '0')
                dfs_blue(xx, yy);
        }
    }
}

void dfs_black(int x, int y) {
    cor[x][y] = BLACK;
    int xx, yy;
    for (int i = 0; i < 4; i++) {
        xx = x + dx[i];
        yy = y + dy[i];
        if (dentro(xx, yy)) {
            if (g[xx][yy] == '1')
                dfs_black(xx, yy);
            else {
                brancos++;
                dfs_blue(xx, yy);
            }
        }
    }
}

int main() {
    int caso = 1;

    char hieroglyphs[] = {'W', 'A', 'K', 'J', 'S', 'D'};
    map<char, string> mapa;
    mapa['0'] = "0000";
    mapa['1'] = "0001";
    mapa['2'] = "0010";
    mapa['3'] = "0011";
    mapa['4'] = "0100";
    mapa['5'] = "0101";
    mapa['6'] = "0110";
    mapa['7'] = "0111";
    mapa['8'] = "1000";
    mapa['9'] = "1001";
    mapa['a'] = "1010";
    mapa['b'] = "1011";
    mapa['c'] = "1100";
    mapa['d'] = "1101";
    mapa['e'] = "1110";
    mapa['f'] = "1111";

    while (scanf("%d %d", &R, &C) > 0) {
        if (R == 0 && C == 0)
            break;

        char c;
        rep(i, 0, R) {
            g[i].clear();
            rep(j, 0, C) {
                scanf(" %c", &c);
                g[i] += mapa[c];
            }
        }

        /*
        rep(i,0,R){
                rep (j, 0, g[i].size())
                        cout << g[i][j];
                cout << "\n";
        }
        */

        memset(cor, -1, sizeof cor);
        for (int i = 0; i < R; i++)
            if (cor[i][0] == -1 && g[i][0] == '0')
                dfs_red(i, 0);
        for (int i = 0; i < R; i++)
            if (cor[i][4 * C - 1] == -1 && g[i][4 * C - 1] == '0')
                dfs_red(i, 4 * C - 1);

        for (int j = 0; j < 4 * C; j++)
            if (cor[0][j] == -1 && g[0][j] == '0')
                dfs_red(0, j);
        for (int j = 0; j < 4 * C; j++)
            if (cor[R - 1][j] == -1 && g[R - 1][j] == '0')
                dfs_red(R - 1, j);

        string ans;
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < 4 * C; j++) {
                if (g[i][j] == '1' && cor[i][j] == -1) { // se for preto e nao foi visitado
                    brancos = 0;
                    dfs_black(i, j); // visito os pretos
                    ans += (hieroglyphs[brancos]);
                }
            }
        }

        sort(ans.begin(), ans.end());
        printf("Case %d: %s\n", caso++, ans.c_str());
    }
    return 0;
}