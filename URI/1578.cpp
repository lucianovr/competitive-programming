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

typedef unsigned long long int ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define rep(i, a, b) for (int i = a; i < b; ++i)
#define pb push_back
#define debug(x) cout << #x << " = " << x << endl;

#define printMatriz(M, r, c)                                                                                           \
    rep(i, 0, r) {                                                                                                     \
        printVetor(M[i], c);                                                                                           \
        cout << endl;                                                                                                  \
    }
#define printVetor(V, n) rep(j, 0, n) cout << V[j] << " ";

const int INF = 0x3f3f3f3f;
const int NULO = -1;
const double pi = acos(-1);
const int dx[] = {0, -1, 0, 1}, dy[] = {-1, 0, 1, 0};

int func(ll x) {
    int cont = 0;
    while (x) {
        x /= 10;
        cont++;
    }
    return cont;
}

int main() {

    int n, m, caso = 4;
    int tam[22], dig;
    ll mat[22][22], x;

    scanf("%d", &n);
    rep(t, 0, n) {
        scanf("%d", &m);

        rep(i, 0, m) tam[i] = 0;

        rep(i, 0, m) rep(j, 0, m) {
            scanf("%llu", &x);
            x = x * x;
            mat[i][j] = x;
            dig = func(x);
            if (dig > tam[j])
                tam[j] = dig;
        }

        printf("Quadrado da matriz #%d:\n", caso++);

        rep(i, 0, m) {
            rep(j, 0, m) {
                printf("%*llu", tam[j], mat[i][j]);
                if (j != m - 1)
                    printf(" ");
            }
            printf("\n");
        }

        if (t != n - 1)
            printf("\n");
    }

    return 0;
}
