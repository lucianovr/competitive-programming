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

int N;
string dig;
int f[15];
ll MOD = 1000000007;
ll memo[10][11][110][110];

#define MAXN 100
ll C[MAXN + 1][MAXN + 1];
void pascalTriangle() {
    ll n, k;
    for (n = 0; n <= MAXN; ++n) {
        C[n][0] = C[n][n] = 1;
        for (k = 1; k < n; ++k)
            C[n][k] = (C[n - 1][k - 1] + C[n - 1][k]) % MOD;
    }
}

ll dp(int d, int r, int par, int impar) { // digito, resto, #pos pares, #pos impares

    if (d == 10)
        return ((r % 11) == 0 && par == 0 && impar == 0); // ja testei todos
    ll &ret = memo[d][r][par][impar];

    if (f[d] == 0) {
        return dp(d + 1, r, par, impar) % MOD; // frequencia do digito d
    }
    if (ret != -1)
        return ret;

    ret = 0;
    if (d != 0) {
        for (int k = 0; k <= min(par, f[d]); k++) { // k: #pos pares que serao preenchidas
            int kk = f[d] - k;                      // #pos impares que serao preenchidas
            if (kk > impar)
                continue;
            int modulo = ((r + k * d - kk * d) % 11 + 11) % 11;

            ll tmp = (C[par][k] * C[impar][kk]) % MOD;
            ret += (tmp * (dp(d + 1, modulo, par - k, impar - kk) % MOD)) % MOD;
        }
        ret %= MOD;
    } else {
        for (int k = 0; k <= min(par - 1, f[d]); k++) { // k: #pos pares que serao preenchidas
            int kk = f[d] - k;                          // #pos impares que serao preenchidas
            if (kk > impar)
                continue;
            int modulo = ((r + k * d - kk * d) % 11 + 11) % 11;

            ll tmp = (C[par - 1][k] * C[impar][kk]) % MOD;
            ret += (tmp * (dp(d + 1, modulo, par - k, impar - kk) % MOD)) % MOD;
        }
        ret %= MOD;
    }
    ret %= MOD;
    return ret;
}

int main() {
    pascalTriangle();

    char dig[1000];
    while (scanf("%s", dig) != EOF) {
        N = strlen(dig);
        rep(i, 0, 11) f[i] = 0;
        rep(i, 0, N) f[dig[i] - '0']++;

        int par = N / 2 + (N % 2);
        int impar = N / 2;

        /*
        for (int i=0; i < 10; i++)
                for (int j = 0; j < 11; j++)
                        for (int k = 0; k <= par; k++)
                                for (int kk = 0; kk <= impar; kk++)
                                        memo[i][j][k][kk] = -1;
        */

        memset(memo, -1, sizeof memo);
        cout << dp(0, 0, par, impar) << "\n";
    }
    return 0;
}
