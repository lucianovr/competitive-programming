#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout << #x << " = " << x << endl;
#define mp make_pair

typedef pair<long, long> pp;

const long long oo = ((1LL) << 60);

long long N;
long long M[111][111];
const long long mod = 1000000009LL;

long long dist[111][111], ways[111][111];

//  up, down, right, left
long long dx[] = {-1, 1, 0, 0, -1, 1};
long long dy[] = {0, 0, 1, -1, 0, 0};

long long dijkstra() {
#define inside(x, y) (x >= 0 && y >= 0 && x < N && y < N)
    for (int i = 0; i <= N; i++)
        for (int j = 0; j <= N; j++)
            dist[i][j] = oo, ways[i][j] = 0;

    priority_queue<pair<long long, pair<pp, pp>>> pq;

    long long x = 0, y = 0, r = N - 1, s = N - 1;
    ways[x][y] = 1;
    dist[x][y] = M[x][y] + M[r][s];
    pq.push(mp(-dist[x][y], mp(mp(x, y), mp(r, s))));

    while (!pq.empty()) {
        pair<long long, pair<pp, pp>> top = pq.top();
        pq.pop();

        long long d = -top.first;
        pair<pp, pp> pos = top.second;

        x = pos.first.first;
        y = pos.first.second;
        r = pos.second.first;
        s = pos.second.second;

        // cout << d << "  ("<<x<<", "<<y<<")\n";

        if (x + y == N - 1)
            continue;

        for (long long k = 0; k < 4; k++) {
            long long xx = x + dx[k];
            long long yy = y + dy[k];
            long long rr = r + dx[k + 2];
            long long ss = s + dy[k + 2];
            if (inside(xx, yy) && inside(rr, ss)) {
                long long new_dist = d + M[xx][yy] + M[rr][ss];
                if (xx == rr && yy == ss)
                    new_dist -= M[xx][yy];

                //                 printf("x=%lld,y=%lld,r=%lld,s=%lld,nd=%lld\n",xx,yy,rr,ss,new_dist);

                if (dist[xx][yy] == oo || dist[xx][yy] > new_dist) {
                    dist[xx][yy] = new_dist;
                    ways[xx][yy] = ways[x][y];
                    pq.push(mp(-dist[xx][yy], mp(mp(xx, yy), mp(rr, ss))));
                } else if (new_dist == dist[xx][yy]) {
                    ways[xx][yy] += ways[x][y];
                    ways[xx][yy] %= mod;
                }
            }
        }
    }

    long long min_dist = oo, sum = 0;
    for (long long x = 0; x < N; x++) {
        long long y = N - 1 - x;
        if (dist[x][y] < min_dist) {
            min_dist = dist[x][y];
            sum = ways[x][y];
        } else if (dist[x][y] == min_dist) {
            sum = (sum + ways[x][y]) % mod;
        }
    }
    // debug(min_dist);
    return sum;
}

int main() {
    while (scanf("%lld", &N) == 1) {
        if (!N)
            break;
        for (long long x = 0; x < N; x++)
            for (long long y = 0; y < N; y++)
                scanf("%lld", &M[x][y]);

        printf("%lld\n", dijkstra());
    }
    return 0;
}