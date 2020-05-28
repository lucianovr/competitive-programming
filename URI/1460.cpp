#include <bits/stdc++.h>
using namespace std;

pair<pair<int, int>, pair<int, int>> query[10100];
int L, C; // linhas, colunas
int caso = 1;

int main() {
    while (cin >> L >> C) {
        if (L == 0 && C == 0)
            break;

        vector<vector<int>> M(L, vector<int>(C));
        for (int i = 0; i < L; i++) {
            for (int j = 0; j < C; j++) {
                scanf("%d", &M[i][j]);
            }
        }
        int Q, Lq, Uq;
        scanf("%d", &Q);
        for (int i = 0; i < Q; i++) {
            scanf("%d %d", &Lq, &Uq);

            int D = 0; // maior diagonal para a consulta 'q'
            for (int i = 0; i < L; i++) {
                if (M[i].back() < Lq)
                    continue;

                int x = i;
                int y = (int)(lower_bound(M[i].begin(), M[i].end(), Lq) - M[i].begin());
                int md = min(L - x, C - y);
                if (L - i < D)
                    break; // as proximas linhas terao diagonais menores ainda
                if (md < D)
                    continue; // esta linha atual, com a coluna minima, possui diagonal que nao interessa
                int lo = 1, hi = md;
                int best = 0;
                while (lo <= hi) {
                    int k = (lo + hi) / 2;
                    if (x + k - 1 >= L || y + k - 1 >= C)
                        hi = k - 1;
                    else {
                        if (M[x + k - 1][y + k - 1] > Uq) {
                            hi = k - 1;
                        } else {
                            best = max(best, k);
                            lo = k + 1;
                        }
                    }
                }
                D = max(D, best);
            }
            printf("%d\n", D);
        }
        printf("-\n");
    }
}
