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
    cout << __LINE__ <<\" \"<< #x \" = \" << (x) << endl;
#define DVEC(v, n)                                                                                                     \
    {                                                                                                                  \
        cout << #v <<\"[] ={ \"; rep(i,0,n)cout<<v[i]<<\" \"; cout << \"}\\n\";}
#define mp make_pair
#define fst first
#define snd second

typedef pair<int, int> ii;
typedef long long ll;

typedef vector<int> vi;
typedef vector<ii> vii;

const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;

int grid[22][22];
int dist[22][22];
int R, C;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};

bool dentro(int x, int y) { return x >= 0 && x < R && y >= 0 && y < C; }

int bfs(int x, int y) {
    queue<ii> q;
    memset(dist, -1, sizeof dist);
    q.push(ii(x, y));
    dist[x][y] = 0;

    while (!q.empty()) {
        ii front = q.front();
        q.pop();
        x = front.first;
        y = front.second;

        if (grid[x][y] == 0)
            return dist[x][y];

        rep(i, 0, 4) {
            int a = x + dx[i];
            int b = y + dy[i];
            if (dentro(a, b) && grid[a][b] != 2 && dist[a][b] == -1) {
                dist[a][b] = dist[x][y] + 1;
                q.push(ii(a, b));
            }
        }
    }
}

int main() {

    cin >> R >> C;

    int x, y;

    rep(i, 0, R) rep(j, 0, C) {
        cin >> grid[i][j];
        if (grid[i][j] == 3) {
            x = i;
            y = j;
        }
    }

    cout << bfs(x, y) << endl;

    return 0;
}
