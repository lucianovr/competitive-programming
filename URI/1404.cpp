#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <stdio.h>
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
int n, m, resp, cont;
int G[22][22];
void func(int x, int y, int c) {
    int i, j, a, b;
    resp = max(resp, c);

    i = x + 1;
    j = y + 1;
    a = i + 1;
    b = j + 1;
    if (i <= n - 2 && j <= m - 2) {
        if (G[i][j] == 2 && G[a][b] == 0) {
            G[i][j] = 0;
            func(a, b, c + 1);
            G[i][j] = 2;
        }
    }

    i = x + 1;
    j = y - 1;
    a = i + 1;
    b = j - 1;
    if (i <= n - 2 && j >= 1) {
        if (G[i][j] == 2 && G[a][b] == 0) {
            G[i][j] = 0;
            func(a, b, c + 1);
            G[i][j] = 2;
        }
    }

    i = x - 1;
    j = y + 1;
    a = i - 1;
    b = j + 1;
    if (i >= 1 && j <= m - 2) {
        if (G[i][j] == 2 && G[a][b] == 0) {
            G[i][j] = 0;
            func(a, b, c + 1);
            G[i][j] = 2;
        }
    }

    i = x - 1;
    j = y - 1;
    a = i - 1;
    b = j - 1;
    if (i >= 1 && j >= 1) {
        if (G[i][j] == 2 && G[a][b] == 0) {
            G[i][j] = 0;
            func(a, b, c + 1);
            G[i][j] = 2;
        }
    }
}

int main() {
    int linha[1000];
    vii pos;
    int aux, qt;
    while (cin >> n >> m && n + m) {
        setar(G, 0);
        aux = n * m;
        if (aux % 2 == 0)
            qt = aux / 2;
        else
            qt = aux / 2 + 1;

        rep(i, qt) cin >> linha[i];
        int j, k = 0;
        pos.clear();
        for (int i = 0; i < n; i++) {
            for (j = i % 2; j < m; j += 2) {
                if (linha[k] == 1)
                    pos.pb(ii(i, j));
                G[i][j] = linha[k];
                k++;
                if (k == qt)
                    break;
            }
            if (k == qt)
                break;
        }
        resp = 0;
        int x, y;
        rep(i, pos.sz) {
            x = pos[i].first;
            y = pos[i].second;
            G[x][y] = 0;
            func(x, y, 0);
            G[x][y] = 1;
        }
        cout << resp << endl;
    }
    return 0;
}