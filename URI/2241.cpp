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

const int MAX = 500 + 10;
int mat[2][MAX][MAX];
int N; // tam
#define p 0
#define b 1
void precompute(int k) {
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            mat[k][i][j] += mat[k][i][j - 1] + mat[k][i - 1][j] - mat[k][i - 1][j - 1];
}

int get(int i, int j, int ii, int jj, int k) {
    return mat[k][ii][jj] - mat[k][ii][j - 1] - mat[k][i - 1][jj] + mat[k][i - 1][j - 1];
}

int preto(int i, int j, int k) { return get(i, j, i + k - 1, j + k - 1, p); }
int branco(int i, int j, int k) { return get(i, j, i + k - 1, j + k - 1, b); }

int main() {
    int P;
    while (scanf("%d %d", &N, &P) != EOF) {
        memset(mat, 0, sizeof mat);
        int i, j;
        rep(t, 0, P) { // pretas
            scanf("%d %d", &i, &j);
            mat[p][i][j] = 1;
        }
        rep(t, 0, P) { // brancas
            scanf("%d %d", &i, &j);
            mat[b][i][j] = 1;
        }
        precompute(p);
        precompute(b);

        int ans_preto = 0;

        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                bool achou = false;
                int inicio, fim;
                for (int k = min(N, 1 + N - max(i, j)); k >= 1; k--) // K eh o tam da diagonal
                {
                    if (branco(i, j, k) == 0 && preto(i, j, k) != 0)
                        achou = true;
                    if (achou) {
                        fim = k;
                        break;
                    }
                }
                if (achou) {
                    for (int k = 1; k <= min(N, 1 + N - max(i, j)); k++) // K eh o tam da diagonal
                    {
                        if (preto(i, j, k) != 0) {
                            inicio = k;
                            break;
                        }
                    }
                }
                if (achou) {
                    ans_preto += (fim - inicio + 1);
                }
            }
        }

        int ans_branco = 0;

        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                bool achou = false;
                int inicio, fim;
                for (int k = min(N, 1 + N - max(i, j)); k >= 1; k--) // K eh o tam da diagonal
                {
                    if (preto(i, j, k) == 0 && branco(i, j, k) != 0)
                        achou = true;
                    if (achou) {
                        fim = k;
                        break;
                    }
                }
                if (achou) {
                    for (int k = 1; k <= min(N, 1 + N - max(i, j)); k++) // K eh o tam da diagonal
                    {
                        if (branco(i, j, k) != 0) {
                            inicio = k;
                            break;
                        }
                    }
                }
                if (achou) {
                    ans_branco += (fim - inicio + 1);
                }
            }
        }

        printf("%d %d\n", ans_preto, ans_branco);
    }
    return 0;
}
