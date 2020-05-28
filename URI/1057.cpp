#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

char grid[20][20];
int vis[100][100][100];

int N;

struct pos {
    int x, y;
    pos() {}
    pos(int x, int y) : x(x), y(y) {}

    pos operator+(pos d) { return pos(x + d.x, y + d.y); }
    pos operator-(pos d) { return pos(x - d.x, y - d.y); }

    bool operator==(pos r) const { return (r.x == x && r.y == y); }
    bool operator<(pos r) const { return (x == r.x ? y < r.y : x < r.x); }

    bool operator<=(pos r) const { return *this == r || *this < r; }
};

pos dxdy[] = {pos(0, -1), pos(0, 1), pos(1, 0), pos(-1, 0)};

struct tres {
    pos r1, r2, r3;
    tres(pos a, pos b, pos c) : r1(a), r2(b), r3(c) {}

    bool operator<(tres U) const {
        if (r1 < U.r1)
            return true;
        if (r2 < U.r2)
            return true;
        if (r3 < U.r3)
            return true;
        return false;
    }
};

bool match(pos A, pos B, pos C) {
    if (grid[A.x][A.y] == 'X' && grid[B.x][B.y] == 'X' && grid[C.x][C.y] == 'X')
        return true;
    return false;
}

bool dentro(pos p) { return p.x >= 0 && p.y >= 0 && p.x < N && p.y < N; }

void debug(pos A, pos B, pos C, int d) {
    cout << "(" << A.x << ", " << A.y << ") (" << B.x << "," << B.y << ") (" << C.x << ", " << C.y << ")  " << d
         << "\n";
}

int toId(pos P) { return P.x * N + P.y; }

int bfs(pos A, pos B, pos C) {

    vector<pos> V(3);
    V[0] = A;
    V[1] = B;
    V[2] = C;

    sort(V.begin(), V.end());
    A = V[0];
    B = V[1];
    C = V[2];

    queue<pair<tres, int>> Q;
    tres robos = tres(A, B, C);

    Q.push(make_pair(robos, 0));

    int ans = 0x3f3f3f3f;

    while (!Q.empty()) {

        robos = Q.front().first;
        int dist = Q.front().second;
        Q.pop();

        A = robos.r1;
        B = robos.r2;
        C = robos.r3;
        int aa = toId(A);
        int bb = toId(B);
        int cc = toId(C);

        if (vis[aa][bb][cc])
            continue;

        vis[aa][bb][cc] = 1;

        //	debug(A,B,C,dist);
        // getchar();

        pos a, b, c;

        // set<pos> S;
        if (match(A, B, C)) {
            ans = min(ans, dist);
        }

        for (int i = 0; i < 4; i++) {
            a = A + dxdy[i];
            if (!dentro(a) || grid[a.x][a.y] == '#') {
                a = A;
            }

            b = B + dxdy[i];
            if (!dentro(b) || grid[b.x][b.y] == '#') {
                b = B;
            }

            c = C + dxdy[i];
            if (!dentro(c) || grid[c.x][c.y] == '#') {
                c = C;
            }

            int change = 1;
            while (change == 1) {
                change = 0;
                if (a == b) {
                    a = A;
                    b = B;
                    change = 1;
                }
                if (a == c) {
                    a = A;
                    c = C;
                    change = 1;
                }
                if (b == c) {
                    b = B;
                    c = C;
                    change = 1;
                }
            }
            V[0] = a;
            V[1] = b;
            V[2] = c;
            sort(V.begin(), V.end());
            a = V[0];
            b = V[1];
            c = V[2];

            robos = tres(a, b, c);
            Q.push(make_pair(robos, dist + 1));
        }
    }

    return ans;
}

int main() {
    int t;
    cin >> t;
    vector<pos> V;
    int tt = 1;

    while (t--) {
        cin >> N;

        V.clear();
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++) {
                char c;
                cin >> c;
                if (c != '#' && c != '.' && c != 'X') {
                    V.push_back(pos(i, j));
                    c = '.';
                }
                grid[i][j] = c;
            }
        pos a, b, c;
        a = V[0];
        b = V[1];
        c = V[2];

        cout << "Case " << tt++ << ": ";

        for (int i = 0; i < N * N; i++)
            for (int j = 0; j < N * N; j++)
                for (int k = 0; k < N * N; k++)
                    vis[i][j][k] = 0;

        int ret = bfs(a, b, c);
        if (ret != 0x3f3f3f3f)
            cout << ret << "\n";
        else
            cout << "trapped\n";
    }
    return 0;
}
