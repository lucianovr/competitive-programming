#include <iostream>
#include <stdio.h>
using namespace std;

int n, m, count, inst = 1, val;
char mat[1001][1001], quad[61][61];
int flag, ma;

int main() {

    while (scanf("%d%d\n", &n, &m) != EOF) {
        for (int i = 0; i < n; i++)
            gets(mat[i]);

        for (int i = 0; i < m; i++)
            gets(quad[i]);

        flag = 1;
        printf("Instancia %d\n", inst++);
        ma = n - m;
        val = m * m;
        for (int j = 0; j <= ma; j++) {
            for (int i = 0; i <= ma; i++) {
                if (mat[i][j] == quad[0][0] && mat[i][j + m - 1] == quad[0][m - 1] &&
                    mat[i + m - 1][j] == quad[m - 1][0] && mat[i + m - 1][j + m - 1] == quad[m - 1][m - 1]) {
                    count = 0;
                    for (int k = 0; k < m; k++) {
                        for (int l = 0; l < m; l++) {
                            if (mat[i + l][j + k] == quad[l][k])
                                count++;
                            else {
                                k = m + 1;
                                break;
                            }
                        }
                    }
                    if (count == val) {
                        printf("%d %d\n", i, j);
                        flag = 0;
                    }
                }
            }
        }
        if (flag == 1)
            printf("nenhuma ocorrencia\n");
        printf("\n");
    }

    return 0;
}
