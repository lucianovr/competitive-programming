#include <algorithm>
#include <cmath> // atan2(dy,dx) :retorna angulo polar
#include <cstdlib>
#include <iostream>
#include <string.h>
#include <utility> // #define x first , y second  quando trabalhar com pontos
#include <vector>  // #include <map> , <set> , <stack> , <queue> , <deque>
using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define rep(i, n) for (int i = 0; i < (n); i = i + 1)
#define tr(it, S) for (typeof(S.begin()) it = S.begin(); it != S.end(); it++)
#define all(S) (S).begin(), (S).end()
#define pb push_back
#define sz size()

string func(int n, int m, int values[]) {

    int MAX = 0;
    rep(i, 110) MAX += values[i];
    int tab[MAX + 1];
    memset(tab, 0, sizeof(tab));
    tab[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = MAX; j >= values[i]; j--) {
            tab[j] |= tab[j - values[i]];
        }
        if (tab[m])
            return "S";
    }
    return "N";
}

int main() {

    int r, k, a, b;
    int cont[110];
    while (cin >> r >> k) {
        memset(cont, 0, sizeof(cont));
        rep(i, k) {
            cin >> a >> b;
            cont[a]++;
            cont[b]++;
        }
        cout << func(r, k, cont) << endl;
    }
    return 0;
}
