#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <map>
#include <queue>
#include <string.h>
#include <utility>
#include <vector>
using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define rep(i, n) for (int i = 0; i < (n); i = i + 1)
#define tr(it, S) for (typeof(S.begin()) it = S.begin(); it != S.end(); it++)
#define all(S) (S).begin(), (S).end()
#define setar(S, x) memset(S, x, sizeof(S))
#define pb push_back
#define sz size()
#define inf 1000000000
#define x first
#define y second

int d[101][101], N, M, K;
char m[101][101];
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};
char ok[] = {"<>v^"};
char ok_[] = {"><^v"};

bool dentro(ii v) {
    if (v.x >= 0 && v.x < N && v.y >= 0 && v.y < M)
        return true;
    return false;
}

bool testa() {
    rep(j, M) if (d[0][j] <= K || d[N - 1][j] <= K) return true;
    rep(i, N) if (d[i][0] <= K || d[i][M - 1] <= K) return true;
    return false;
}

void dijkstra(ii s) {
    bool vis[N][M];
    map<int, ii> mp;
    map<ii, int> mp_;
    ii v;
    int cost, k = 0, t;
    rep(i, N) rep(j, M) {
        mp[k] = ii(i, j);
        mp_[ii(i, j)] = k;
        d[i][j] = inf;
        if (s.x == i && s.y == j)
            t = k;
        vis[i][j] = false;
        k++;
    }
    priority_queue<ii> Q;
    Q.push(ii(0, t));
    d[s.x][s.y] = 0;
    while (true) {
        while (!Q.empty()) {
            k = Q.top().second;
            v = mp[k];
            if (vis[v.x][v.y] == true)
                Q.pop();
            else
                break;
        }
        if (Q.empty())
            break;

        k = Q.top().second;
        s = mp[k];
        vis[s.x][s.y] = true;
        rep(i, 4) {
            v.x = s.x + dx[i];
            v.y = s.y + dy[i];
            if (dentro(v))
                if (m[v.x][v.y] == ok[i] || m[v.x][v.y] == ok_[i]) {
                    cost = 0;
                    if (m[v.x][v.y] == ok_[i])
                        cost = 1;
                    if (d[v.x][v.y] > d[s.x][s.y] + cost) {
                        d[v.x][v.y] = d[s.x][s.y] + cost;
                        Q.push(ii(-d[v.x][v.y], mp_[v]));
                    }
                }
        }
    }
}

int main() {
    while (cin >> N >> M >> K && N + M + K) {
        rep(i, N) rep(j, M) { cin >> m[i][j]; }
        dijkstra(ii(N / 2, M / 2));

        if (testa())
            cout << "Sim\n";
        else
            cout << "Nao\n";
    }
    return 0;
}
