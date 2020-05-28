#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctype.h>
#include <iostream>
#include <map>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define rep(i, a, b) for (int i = a; i < b; ++i)
#define pb push_back

const int INF = 0x3F3F3F3F;
//		 0   1    2  3    4    5   6  7
//   E  EC   C   CD  D   DB  B   BE
int di[] = {0, -1, -1, -1, 0, 1, 1, 1};
int dj[] = {-1, -1, 0, 1, 1, 1, 0, -1};

int mat[1010][1010];
bool vis[1010][1010];

int main() {
    int ans = 0;
    int n, m, a, b;
    bool ok, achou;

    while (scanf("%d %d", &n, &m) == 2) {

        rep(i, 0, n) rep(j, 0, m) {
            scanf("%d", &mat[i][j]);
            vis[i][j] = false;
        }

        achou = false;

        rep(i, 0, n) rep(j, 0, m) {
            if (vis[i][j])
                continue;

            ok = true;
            for (int k = 0; k < 8 && ok; ++k) {
                a = i + di[k];
                b = j + dj[k];
                if (a >= 0 && a < n && b >= 0 && b < m) {
                    if (mat[i][j] <= mat[a][b])
                        ok = false;
                }
            }
            if (ok == true) {
                achou = true;
                printf("%d %d\n", i + 1, j + 1);
                ans++;
                rep(k, 4, 8) {
                    a = i + di[k];
                    b = j + dj[k];
                    if (a >= 0 && a < n && b >= 0 && b < m) {
                        vis[a][b] = true;
                    }
                }
            }
        }
        //
        //			printf("\n");
        //			rep(i,0,n){
        //				rep(j,0,m)
        //					if( !vis[i][j] )
        //						printf("%d ", mat[i][j]);
        //					else printf("* ");
        //				printf("\n");
        //			}

        if (achou == false)
            printf("-1\n");

        printf("\n");
    }
    return 0;
}
