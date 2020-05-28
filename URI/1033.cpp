#include <stdio.h>
using namespace std;
#define pb push_back
#define rep(i, a, b) for (int i = a; i < b; i++)

// typedef pair<int,int> ii;
// typedef vector<int> vi;

struct MAT {
    int mat[2][2];
};
int MOD;

MAT multiply(MAT A, MAT B) {
    MAT C;
    rep(i, 0, 2) rep(j, 0, 2) for (int k = C.mat[i][j] = 0; k < 2; k++) {
        C.mat[i][j] = (C.mat[i][j] + (A.mat[i][k] * B.mat[k][j]) % MOD) % MOD;
    }
    return C;
}

MAT pow(MAT B, unsigned long long int P) {
    MAT A;
    rep(i, 0, 2) rep(j, 0, 2) A.mat[i][j] = (i == j);
    while (P) {
        if (P & 1)
            A = multiply(A, B);
        B = multiply(B, B);
        P >>= 1;
    }
    return A;
}

int main() {
    MAT f;
    f.mat[0][0] = 1;
    f.mat[0][1] = 1;
    f.mat[1][0] = 1;
    f.mat[1][1] = 0;

    unsigned long long int N;
    int caso = 1;

    while (scanf("%lld %d", &N, &MOD) == 2) {
        if (MOD == 0 && N == 0)
            break;
        MAT R = pow(f, N);
        int ans = ((R.mat[0][0] % MOD + R.mat[1][0] % MOD + R.mat[1][1] % MOD - 1) + MOD) % MOD;
        printf("Case %d: %lld %d %d\n", caso++, N, MOD, ans);
    }

    return 0;
}
