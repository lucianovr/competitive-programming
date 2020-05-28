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

typedef long long int ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define rep(i, n) for (int i = 0; i < n; ++i)
#define pb push_back
#define debug(x) cout << #x << " = " << x << endl;

long long int v[10010];
long long int m[10010][2];

int main() {
    int n;
    long long int soma;

    while (scanf("%d", &n) == 1) {
        soma = 0;
        rep(i, n) {
            scanf("%lld", &v[i]);
            soma += v[i];
        }

        for (int i = 0; i < n; i++)
            m[i][0] = 0;
        m[0][0] = v[0]; // inicializado primeira coluna

        for (int j = 1; j < n; j++) { // para cada coluna, de baixo para cima
            for (int i = n - 1; i >= 0; i--) {
                if (i > j)
                    m[i][1] = 0;
                else if (i == j)
                    m[i][1] = v[i];
                else
                    m[i][1] = max(v[i] - m[i + 1][1], v[j] - m[i][0]);

                m[i][0] = m[i][1]; // copiando o valor para a coluna anterior
            }
        }

        long long int result = (soma + m[0][1]) / 2;

        printf("%lld\n", result);
    }
    return 0;
}
