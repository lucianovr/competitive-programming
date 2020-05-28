#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <utility>
#include <vector>
using namespace std;
typedef unsigned long long int lli;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define rep(i, a, b) for (int i = a; i < b; i++)
#define tr(it, S) for (typeof(S.begin()) it = S.begin(); it != S.end(); it++)
#define all(S) S.begin(), S.end()
#define STD std::ios::sync_with_stdio(false)
#define x first
#define y second
vector<ii> black, white;

int buscaMINp(int ini, int fim, int X) {
    int me;
    while (ini < fim) {
        me = (ini + fim) >> 1;
        if (white[me].x >= X)
            fim = me - 1;
        else
            ini = me + 1;
    }
    return ini;
}
int buscaMAXp(int ini, int fim, int X) {
    int me;
    while (ini < fim) {
        me = (ini + fim) >> 1;
        if (white[me].x <= X)
            ini = me + 1;
        else
            fim = me - 1;
    }
    return ini;
}

bool dentro(int i, int j, int k, int p) {
    // 3 vetores, ij, jk, ki;
    int ijx = black[j].x - black[i].x;
    int ijy = black[j].y - black[i].y;
    int ipx = white[p].x - black[i].x;
    int ipy = white[p].y - black[i].y;

    int jkx = black[k].x - black[j].x;
    int jky = black[k].y - black[j].y;
    int jpx = white[p].x - black[j].x;
    int jpy = white[p].y - black[j].y;

    int kix = black[i].x - black[k].x;
    int kiy = black[i].y - black[k].y;
    int kpx = white[p].x - black[k].x;
    int kpy = white[p].y - black[k].y;

    int d1 = (ijx * ipy - ijy * ipx) > 0;

    int d2 = (jkx * jpy - jky * jpx) > 0;

    if (d1 != d2)
        return false;

    int d3 = (kix * kpy - kiy * kpx) > 0;

    if (d1 != d3)
        return false;

    return true;
}

bool comp(ii a, ii b) {
    if (a.x < b.x)
        return true;
    if (a.x > b.x)
        return false;
    if (a.y < a.y)
        return true;
    return false;
}

int main() {
    STD;
    int n, m, a, b;
    int cont;
    while (cin >> n >> m) {
        black.clear();
        white.clear();
        rep(i, 0, n) {
            cin >> a >> b;
            black.push_back(ii(a, b));
        }
        rep(i, 0, m) {
            cin >> a >> b;
            white.push_back(ii(a, b));
        }

        sort(all(black), comp);
        sort(all(white), comp);

        lli soma = 0LL;

        rep(i, 0, n) {
            rep(j, i + 1, n) {
                rep(k, j + 1, n) {
                    lli ponto = 0LL;
                    int xmax = buscaMAXp(0, m - 1, black[k].x);
                    int xmin = buscaMINp(0, m - 1, black[i].x);

                    for (int p = xmin; p <= xmax; p++)
                        if (dentro(i, j, k, p))
                            ponto++;
                    ponto *= ponto;
                    soma += ponto;
                }
            }
        }

        cout << soma << endl;
    }
    return 0;
}
