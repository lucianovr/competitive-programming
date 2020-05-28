#include <cstdlib>
#include <queue>
#include <stdio.h>
#include <string.h>
#include <utility>
using namespace std;
typedef pair<int, int> parii;
#define rep(i, n) for (int i = 0; i < (n); i = i + 1)
#define x first
#define y second
queue<parii> q;
int dx[] = {1, 1, -1, -1, 2, 2, -2, -2};
int dy[] = {2, -2, 2, -2, 1, -1, 1, -1};
int d[8][8];

void tenta_movimento(parii p, int w) {
    if (p.x < 0 || p.x >= 8 || p.y < 0 || p.y >= 8 || d[p.x][p.y] != -1)
        return;

    d[p.x][p.y] = w;
    q.push(p);
}
int main() {
    parii ini, fim;
    char a[5], b[5];
    while (scanf("%s %s", a, b) != EOF) {

        ini = parii(a[0] - 'a', a[1] - '1');
        fim = parii(b[0] - 'a', b[1] - '1');
        while (!q.empty()) {
            q.pop();
        }
        q.push(ini);
        memset(d, -1, sizeof(d));
        d[ini.x][ini.y] = 0;
        while (!q.empty()) {
            parii p = q.front();
            q.pop();
            if (p == fim) {
                printf("To get from %s to %s takes %d knight moves.\n", a, b, d[p.x][p.y]);
            }
            rep(i, 8) { tenta_movimento(parii(p.x + dx[i], p.y + dy[i]), d[p.x][p.y] + 1); }
        }
    }
    return 0;
}
