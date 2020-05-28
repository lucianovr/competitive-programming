#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < b; i++)
#define mp make_pair
#define pb push_back
#define contains(s, x) (s.find(x) != s.end())

const int oo = 0x3f3f3f3f;
const double EPS = 1e-9;

long long pd[20][2][20 * 9];

vector<long long> X;
int N;

long long S(int pos, int menor, long long soma) {
    if (pos == N)
        return soma;
    long long &ret = pd[pos][menor][soma];

    if (ret != -1)
        return ret;
    ret = 0;

    if (menor) { // posso add 'qlqr' digito
        // add impares
        for (long long d = 1; d <= 9; d += 2) {
            ret += S(pos + 1, 1, soma + d);
        }
        // add pares
        if (pos != N - 1) {
            for (long long d = 0; d <= 9; d += 2) {
                ret += S(pos + 1, 1, soma + d);
            }
        }
    } else {
        // add impares
        for (long long d = 1; d < X[pos]; d += 2) {
            ret += S(pos + 1, 1, soma + d);
        }
        // add pares
        if (pos != N - 1) {
            for (long long d = 0; d < X[pos]; d += 2) {
                ret += S(pos + 1, 1, soma + d);
            }
        }

        if (pos == N - 1) {
            if (X[pos] % 2 == 1) {
                ret += S(pos + 1, 0, soma + X[pos]);
            }
        } else {
            ret += S(pos + 1, 0, soma + X[pos]);
        }
    }

    return ret;
}

int main() {

    long long A, B, a, b;
    long long soma;

    while (cin >> A >> B) {

        a = min(A, B);
        b = max(A, B);
        a--;

        X.clear();
        while (b) {
            X.pb(b % 10);
            b /= 10;
        }
        reverse(X.begin(), X.end());
        N = X.size();

        memset(pd, -1, sizeof pd);
        soma = S(0, 0, 0);

        X.clear();
        while (a) {
            X.pb(a % 10);
            a /= 10;
        }
        reverse(X.begin(), X.end());
        N = X.size();

        memset(pd, -1, sizeof pd);
        soma -= S(0, 0, 0);

        cout << soma << "\n";
    }

    return 0;
}
