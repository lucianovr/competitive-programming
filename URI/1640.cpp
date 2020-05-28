#include <bits/stdc++.h>
using namespace std;
#define f(i, a, b) for (int i = (a); i < (b); i++)
#define all(c) (c).begin(), (c).end()
#define F first
#define S second
#define debug(x) cout << __LINE__ << ": " << #x << " = " << x << endl;
#define debug2(x, y) cout << #x << " = " << x << "  " << #y << " = " << y << endl;
#define pb push_back
#define mp make_pair

const int INF = 0x3f3f3f3f;
const long long LINF = ((1LL) << 60);
const double EPS = 1e-9;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vector<int>> vvi;

#define MAXN 10005
#define MAXH 105
int dist[MAXN][MAXH];
bool vis[MAXN][MAXH];
int N, H;
int hotel[MAXN];
vector<int> E[MAXN], T[MAXN];

void init() { f(i, 0, N + 2) E[i].clear(), T[i].clear(); }
void add(int a, int b, int t) {
    E[a].pb(b);
    T[a].pb(t);
}

int dijkstra(int s) {
    priority_queue<pair<int, ii>> pq;
    memset(dist, INF, sizeof dist);
    memset(vis, false, sizeof vis);
    dist[s][0] = 0;

    pq.push(mp(0, mp(s, 0)));
    while (!pq.empty()) {
        pair<int, ii> top = pq.top();
        pq.pop();
        s = top.second.first;
        int h = top.second.second;

        if (vis[s][h])
            continue;
        vis[s][h] = true;

        bool jump = false;
        for (int hh = h - 1; hh >= 0; hh--)
            if (dist[s][hh] <= dist[s][h]) {
                jump = true;
                break;
            }
        if (jump)
            continue;

        f(i, 0, E[s].size()) {
            int u = E[s][i];
            int d = T[s][i];
            if (dist[s][h] + d <= 600) {
                if (dist[s][h] + d < dist[u][h]) {
                    dist[u][h] = dist[s][h] + d;
                    pq.push(mp(-dist[u][h], mp(u, h)));
                }
                if (hotel[u] == 1 && h <= H) {
                    dist[u][h + 1] = 0;
                    pq.push(mp(0, mp(u, h + 1)));
                }
            }
        }
    }

    int ans = INF;
    for (int h = 0; h <= H; h++)
        if (dist[N][h] <= 600)
            ans = min(ans, h);
    if (ans == INF)
        ans = -1;
    return ans;
}

int main() {
    while (scanf("%d", &N) && N) {
        init();
        memset(hotel, 0, sizeof hotel);
        scanf("%d", &H);
        f(i, 0, H) {
            int h;
            scanf("%d", &h);
            hotel[h] = 1;
        }
        int m;
        scanf("%d", &m);
        f(i, 0, m) {
            int a, b, t;
            scanf("%d %d %d", &a, &b, &t);
            add(a, b, t);
            add(b, a, t);
        }
        printf("%d\n", dijkstra(1));
    }
    return 0;
}