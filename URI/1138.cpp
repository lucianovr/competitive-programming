#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i(a); i < (b); i++)

#define ALL(c) c.begin(), c.end()
#define UNIQUE(c)                                                                                                      \
    { sort(ALL(c); (c).resize( unique(ALL(c))-c.begin() );                                               \
    }
#define pb push_back
#define sz size()
#define D(x)                                                                                                           \
    if (1)                                                                                                             \
        cout << __LINE__ << " " << #x " = " << (x) << endl;

typedef pair<int, int> ii;
typedef long long ll;

const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;

char A[10];
int tam;
int dig; // digito a ser contado no intervalo [0 ... A]

int dp[10][2][10][2];

int solve(int pos, int prefix, int qt, int ok) {
    if (ok)
        ok = 1;

    if (pos == tam)
        return qt;

    if (dp[pos][prefix][qt][ok] == -1) {
        int ret = 0;

        if (prefix == 0) {
            for (int v = 0; v <= 9; v++) {
                int valor;
                if (dig != 0)
                    valor = qt + (v == dig);
                else {
                    if (ok)
                        valor = qt + (v == dig);
                    else
                        valor = 0;
                }

                ret += solve(pos + 1, 0, valor, ok | v);
            }
        }

        else {

            for (int v = 0; v < (A[pos] - '0'); v++) {
                int valor;
                if (dig != 0)
                    valor = qt + (v == dig);
                else {
                    if (ok)
                        valor = qt + (v == dig);
                    else
                        valor = 0;
                }
                ret += solve(pos + 1, 0, valor, ok | v);
            }

            int v = (A[pos] - '0');
            int valor;
            if (dig != 0)
                valor = qt + (v == dig);
            else {
                if (ok)
                    valor = qt + (v == dig);
                else
                    valor = 0;
            }
            ret += solve(pos + 1, 1, valor, ok | v);
        }
        dp[pos][prefix][qt][ok] = ret;
    }
    return dp[pos][prefix][qt][ok];
}

int main() {
    int n1, n2;

    int sup[10], inf[10];

    while (cin >> n1 >> n2) {
        if (n1 == 0 && n2 == 0)
            break;

        sprintf(A, "%d", n2);
        tam = strlen(A); //.size();
        for (dig = 0; dig <= 9; dig++) {
            memset(dp, -1, sizeof dp);
            sup[dig] = solve(0, 1, 0, 0);
        }

        n1--;
        sprintf(A, "%d", n1);
        tam = strlen(A);
        for (dig = 0; dig <= 9; dig++) {
            memset(dp, -1, sizeof dp);
            inf[dig] = solve(0, 1, 0, 0);
        }
        for (dig = 0; dig <= 9; dig++) {
            if (dig)
                cout << " ";
            cout << sup[dig] - inf[dig];
        }
        cout << endl;
    }

    return 0;
}
