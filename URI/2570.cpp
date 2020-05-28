#include <bits/stdc++.h>
using namespace std;

int main() {

    int N, M, Q;
    while (scanf("%d %d %d", &N, &M, &Q) == 3) {
        vector<int> row(N + 1, -1), col(M + 1, -1);

        for (int t = 0; t < Q; t++) {
            char op;
            int pos;
            scanf(" %c %d", &op, &pos);
            pos--;
            if (op == 'L')
                row[pos] = t;
            else
                col[pos] = t;
        }
        int RH[4] = {0};
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                int dominante = max(row[i], col[j]);
                if (dominante >= 0)
                    RH[dominante % 4]++;
            }
        }
        printf("R%d H%d C%d P%d\n", RH[0], RH[1], RH[2], RH[3]);
    }

    return 0;
}