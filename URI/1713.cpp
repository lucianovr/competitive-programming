#include <iostream>
using namespace std;
#define pb push_back
#define rep(i, a, b) for (int i(a); i < (b); i++)

struct matriz {
    int mat[100][100];
};
matriz ID;
int s, t, N, P;
int MOD = 10000;

matriz Mult(matriz A, matriz B) {
    matriz C;
    rep(i, 0, N) rep(j, 0, N) for (int k = C.mat[i][j] = 0; k < N; k++) {
        C.mat[i][j] = (C.mat[i][j] + A.mat[i][k] * B.mat[k][j]) % MOD;
    }
    return C;
}

matriz Exp(matriz B, int p) {
    if (p == 0)
        return ID;
    if (p == 1)
        return B;
    matriz C = Exp(B, p / 2);
    C = Mult(C, C);
    if (p % 2 == 1)
        C = Mult(C, B);
    return C;
}

int main() {
    rep(i, 0, 100) rep(j, 0, 100) ID.mat[i][j] = (i == j);

    while (cin >> N >> P) {
        cin >> s >> t;

        matriz M;
        rep(i, 0, 100) rep(j, 0, 100) M.mat[i][j] = 0;
        int x;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < 4; j++) {
                cin >> x;
                x--;
                M.mat[i][x]++;
            }
        }

        matriz A = Exp(M, P);

        int ans = A.mat[s - 1][t - 1];
        cout << ans << "\n";
    }
    return 0;
}
