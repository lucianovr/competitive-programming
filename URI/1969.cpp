#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i(a); i < (b); i++)

typedef long long ll;

ll readInt() {
    bool minus = false;
    ll result = 0;
    char ch;

    ch = getchar();
    while (true) {
        if (ch == '-')
            break;
        if (ch >= '0' && ch <= '9')
            break;
        ch = getchar();
    }
    if (ch == '-')
        minus = true;
    else
        result = ch - '0';
    while (true) {
        ch = getchar();
        if (ch < '0' || ch > '9')
            break;
        result = result * 10 + (ch - '0');
    }
    if (minus)
        return -result;
    else
        return result;
}

// variaveis
#define MAXN 1000000
ll MOD = 1000000007;
ll N;
ll bit[MAXN];
ll V[MAXN];

ll ret[3][3], M[3][3], C[3][3];

void multiply(ll A[][3], ll B[][3]) {
    int i, j, k;
    rep(i, 0, 2) {
        rep(j, 0, 2) {
            for (k = C[i][j] = 0; k < 2; k++) {
                if (A[i][k] > MOD)
                    A[i][k] = A[i][k] % MOD;
                if (B[k][j] > MOD)
                    B[k][j] = B[k][j] % MOD;
                C[i][j] = (C[i][j] + (A[i][k] * B[k][j]) % MOD);
                if (C[i][j] > MOD)
                    C[i][j] = C[i][j] % MOD;
            }
        }
    }
    rep(i, 0, 2) rep(j, 0, 2) A[i][j] = C[i][j];
}

void fast_pow(ll e) {

    ret[0][0] = 1;
    ret[0][1] = 0;
    ret[1][0] = 0;
    ret[1][1] = 1;

    M[0][0] = 1;
    M[0][1] = 1;
    M[1][0] = 1;
    M[1][1] = 0;

    while (e) {
        if (e & 1)
            multiply(ret, M);
        multiply(M, M);
        e >>= 1;
    }
}

// Bit
ll query(int x) {
    ll p = 1;
    while (x) {
        p = (p * (bit[x] % MOD));
        if (p > MOD)
            p = p % MOD;
        x -= (x & -x);
    }
    return p;
}

ll update(int x, ll value) {
    while (x <= N) {
        bit[x] = ((bit[x] % MOD) * value) % MOD;
        if (bit[x] > MOD)
            bit[x] = bit[x] % MOD;
        x += (x & -x);
    }
}

ll fermat(ll a, ll p) {
    if (p == 0)
        return 1LL;

    ll ret = fermat(a, p / 2) % MOD;
    ret = (ret * ret) % MOD;
    if (ret > MOD)
        ret = ret % MOD;
    if (p & 1)
        ret = (ret * a) % MOD;
    return ret;
}

int main() {
    ll Q;
    char c, op;
    ll A, B, Ci, AA, BB, invA, value;

    while (scanf("%lld %lld", &N, &Q) == 2) {
        for (ll i = 0; i <= N + 1; i++)
            bit[i] = 1LL;
        for (ll i = 1; i <= N; i++) {
            scanf("%lld", &Ci);
            fast_pow(Ci - 2);
            value = ((ret[1][0] % MOD) + (ret[1][1] % MOD)) % MOD;
            update(i, V[i] = value);
        }

        while (Q--) {
            scanf(" %c%c %lld %lld", &c, &op, &A, &B);

            //	cout << "Q = " << Q << " op = " << op << "\n";
            if (op == '>') {
                invA = 1;
                BB = query(B);
                if (A != 1) {
                    AA = query(A - 1);
                    invA = fermat(AA % MOD, MOD - 2);
                }
                printf("%lld\n", (BB * invA) % MOD);
            } else {
                update(A, fermat(V[A], MOD - 2));
                fast_pow(B - 2);
                value = ((ret[1][0] % MOD) + (ret[1][1] % MOD)) % MOD;
                update(A, V[A] = value);
            }
        }
        BB = query(N);
        printf("%lld\n", BB);
    }
    return 0;
}