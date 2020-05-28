#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i(a); i < (b); i++)

#define all(c) c.begin(), c.end()
#define UNIQUE(c)                                                                                                      \
    { sort(ALL(c); (c).resize( unique(ALL(c))-c.begin() );                                               \
    }
#define pb push_back
#define D(x)                                                                                                           \
    if (1)                                                                                                             \
        cout << __LINE__ << " " << #x " = " << (x) << endl;
#define DVEC(v, n)                                                                                                     \
    {                                                                                                                  \
        cout << #v << "[] ={ ";                                                                                        \
        rep(i, 0, n) cout << v[i] << " ";                                                                              \
        cout << "}\n";                                                                                                 \
    }
#define mp make_pair
#define fst first
#define snd second

typedef pair<int, int> ii;
typedef long long ll;

typedef vector<int> vi;
typedef vector<ii> vii;

const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;

int dx[] = {2, 1, -1, -2, -2, -1, 1, 2, 0, 0, -2, 2, 0, 0, -2, 2, 0, 0, -1, 1, 0, 0, -1, 1};
int dy[] = {-1, -2, -2, -1, 1, 2, 2, 1, -2, 2, 0, 0, -2, 2, 0, 0, -1, 1, 0, 0, -1, 1, 0, 0};
int dz[] = {0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, -1, -1, -1, -1, 2, 2, 2, 2, -2, -2, -2, -2};

int R, C, L;

int dist[110][110][110];

bool dentro(int x, int y, int z) { return x > 0 && y > 0 && z > 0 && x <= R && y <= C && z <= L; }

int bfs(int x, int y, int z, int X, int Y, int Z) {

    pair<ii, int> dest;
    dest = mp(mp(X, Y), Z);

    memset(dist, -1, sizeof dist);
    dist[x][y][z] = 0;
    queue<pair<ii, int>> fila;
    fila.push(mp(mp(x, y), z));

    while (!fila.empty()) {
        pair<ii, int> front = fila.front();
        fila.pop();

        if (front == dest)
            break;

        x = front.fst.fst;
        y = front.fst.snd;
        z = front.snd;
        int a, b, c;

        rep(i, 0, 24) {
            a = x + dx[i];
            b = y + dy[i];
            c = z + dz[i];
            if (dentro(a, b, c) && dist[a][b][c] == -1) {
                dist[a][b][c] = dist[x][y][z] + 1;
                fila.push(mp(mp(a, b), c));
            }
        }
    }
    return dist[X][Y][Z];
}

int main() {
    int x, y, z, a, b, c;
    while (scanf("%d %d %d", &R, &C, &L) == 3) {
        scanf("%d %d %d", &x, &y, &z);
        scanf("%d %d %d", &a, &b, &c);

        printf("%d\n", bfs(x, y, z, a, b, c));
    }
    return 0;
}
