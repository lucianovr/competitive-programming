#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i(a); i < (b); i++)

#define all(c) c.begin(), c.end()
#define SORT(c) sort(all(c))
#define UNIQUE(c)                                                                                                      \
    {                                                                                                                  \
        SORT(c);                                                                                                       \
        (c).resize(unique(all(c)) - c.begin());                                                                        \
    }
#define pb push_back
#define sz(c) ((int)(c.size()))
#define fst first
#define snd second
#define clr(x) memset(x, 0, sizeof x)
#define nulo(x) memset(x, -1, sizeof x)
#define debug(x) cout << #x << " = " << x << "\n";
#define debug2(x, y) cout << #x << " = " << x << "  " << #y << " = " << y << "\n";
#define debugV(v)                                                                                                      \
    {                                                                                                                  \
        cout << #v << "[] = ";                                                                                         \
        rep(i, 0, sz(v)) cout << v[i] << " ";                                                                          \
        cout << "\n";                                                                                                  \
    }

typedef pair<int, int> ii;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef map<string, int> msi;
typedef map<string, string> mss;

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

// xa, ya, xb, yb

char M[2][53][53];
short dist[50][50][50][50];

int R, C;
bool dentro(int x, int y) { return x >= 0 && x < R && y >= 0 && y < C; }

int bfs(int xa, int ya, int xb, int yb) {

    rep(i, 0, R) rep(j, 0, C) rep(ii, 0, R) rep(jj, 0, C) dist[i][j][ii][jj] = -1;

    dist[xa][ya][xb][yb] = 0;

    queue<pair<ii, ii>> q;
    q.push(make_pair(ii(xa, ya), ii(xb, yb)));

    while (!q.empty()) {
        pair<ii, ii> top = q.front();
        q.pop();

        ii ra = top.fst;
        xa = ra.fst;
        ya = ra.snd;

        ii rb = top.snd;
        xb = rb.fst;
        yb = rb.snd;

        if (dist[xa][ya][xb][yb] > 50)
            continue;
        if (M[0][xa][ya] == 'F' && M[1][xb][yb] == 'F')
            return dist[xa][ya][xb][yb];

        int xxa, yya, xxb, yyb;
        rep(i, 0, 4) {
            xxa = xa + dx[i];
            yya = ya + dy[i];
            xxb = xb + dx[i];
            yyb = yb + dy[i];
            if (dentro(xxa, yya)) {
                if (M[0][xxa][yya] == '#')
                    xxa = xa, yya = ya;
                if (M[0][xxa][yya] == 'B')
                    continue;
            } else
                continue;

            if (dentro(xxb, yyb)) {
                if (M[1][xxb][yyb] == '#')
                    xxb = xb, yyb = yb;
                if (M[1][xxb][yyb] == 'B')
                    continue;
            } else
                continue;

            if (dist[xxa][yya][xxb][yyb] == -1) {
                dist[xxa][yya][xxb][yyb] = dist[xa][ya][xb][yb] + 1;
                q.push(make_pair(ii(xxa, yya), ii(xxb, yyb)));
            }
        }
    }

    return -1;
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &R, &C);

        int xa, ya, xb, yb;

        rep(i, 0, R) {
            rep(j, 0, C) {
                scanf(" %c", &M[0][i][j]);
                if (M[0][i][j] == 'R')
                    xa = i, ya = j;
            }
        }

        rep(i, 0, R) {
            rep(j, 0, C) {
                scanf(" %c", &M[1][i][j]);
                if (M[1][i][j] == 'R')
                    xb = i, yb = j;
            }
        }

        int resp = bfs(xa, ya, xb, yb);
        if (resp == -1)
            printf("impossivel\n");
        else
            printf("%d\n", resp);
    }
    return 0;
}
