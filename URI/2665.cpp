#include <bits/stdc++.h>

using namespace std;

struct point {
    int x, y;
    point(int _x = 0, int _y = 0) {
        x = _x;
        y = _y;
    }
    point operator-(point q) { return point(x - q.x, y - q.y); }
};
#define vec(a, b) (b - a)

int cross(point a, point b) {
    int dx = a.x * b.y;
    int dy = a.y * b.x;
    return dx - dy;
}

int ccw(point a, point b, point c) {
    int ret = cross(vec(a, b), vec(b, c));
    if (ret > 0)
        return 1;
    if (ret < 0)
        return -1;
    return 0;
}

point P[110];
point A, B;
int g[110][110], N;
int dp[110];

bool ok(point u, point v) { return ccw(A, u, v) == -1 && ccw(B, u, v) == 1; }

int S(int i) {
    if (dp[i] > -1)
        return dp[i];

    int r = 0;
    for (int j = 0; j < N; j++)
        if (g[i][j])
            r = max(r, 1 + S(j));
    return dp[i] = r;
}

int main() {
    while (cin >> N) {
        cin >> A.x >> B.x;
        A.y = B.y = 0;
        for (int i = 0; i < N; i++) {
            cin >> P[i].x >> P[i].y;
        }
        memset(g, 0, sizeof g);
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++) {
                if (i == j)
                    continue;
                else
                    g[i][j] = ok(P[i], P[j]);
            }
        int ans = 0;
        memset(dp, -1, sizeof dp);
        for (int i = 0; i < N; i++)
            ans = max(ans, 1 + S(i));
        printf("%d\n", ans);

        /*
                        int r = 0;
                        for (int k = 0; k < N; k++)
                        for (int i = 0; i < N; i++)
                                for (int j = 0; j < N; j++){
                                        if (k != i && k != j && i != j){
                                                if (g[i][j] && g[i][k] && g[k][j]){
                                                        g[i][j] = max(g[i][j], g[i][k] + g[k][j]);
                                                        r = max(r, g[i][j]);
                                                }
                                        }
                                }
                        
                        printf("%d\n", r + 1);
        */
    }
    return 0;
}