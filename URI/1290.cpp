#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <vector>
#define f first
#define s second
#define rdi(a) scanf("%d", &a)
#define rdii(a, b) scanf("%d%d", &a, &b)
using namespace std;

struct tipo {
    int x, y, z;
};

vector<tipo> vect;
int mat[51][51][51];

int main() {

    int n, m, v[3], vlm, volume, flag;
    tipo c, caixa;

    while (rdii(n, m) && n) {
        for (int i = 0; i < 51; i++)
            for (int j = 0; j < 51; j++)
                for (int k = 0; k < 51; k++)
                    mat[i][j][k] = 0;
        vect.clear();
        flag = 1;
        vlm = 125001;

        scanf("%d%d%d", &v[0], &v[1], &v[2]);
        sort(v, v + 3);
        caixa.x = v[0];
        caixa.y = v[1];
        caixa.z = v[2];

        for (int i = 0; i < m; i++) {
            scanf("%d%d%d", &v[0], &v[1], &v[2]);
            sort(v, v + 3);
            c.x = v[0];
            c.y = v[1];
            c.z = v[2];
            vect.push_back(c);
            mat[c.x][c.y][c.z]++;
        }
        for (int i = 0, len = vect.size(); i < len; i++) {
            c = vect[i];
            if (mat[c.x][c.y][c.z] >= n) {
                mat[c.x][c.y][c.z] = 0;
                if (c.x >= caixa.x && c.y >= caixa.y && c.z >= caixa.z) {
                    volume = c.x * c.y * c.z;
                    if (volume < vlm)
                        vlm = volume;
                    flag = 0;
                }
            }
        }

        if (flag)
            printf("impossible\n");
        else
            printf("%d\n", vlm - (caixa.x * caixa.y * caixa.z));
    }
    return 0;
}
