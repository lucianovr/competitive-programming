#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(c) (c).begin(), (c).end()
#define F first
#define S second
#define debug(x) cout << __LINE__ << ": " << #x << " = " << x << endl;
#define debug2(x, y) #x << " = " << x << "  " << #y << " = " << y << endl;
#define pb push_back
#define mk make_pair

const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;
typedef long long ll;
typedef pair<int, int> ii;

map<vector<int>, int> dist;

ll dijkstra(vector<int> s, vector<int> t) {
    priority_queue<pair<ll, vector<int>>> pq;
    dist.clear();
    pq.push(mk(dist[s] = 0, s));

    vector<int> v;
    ll custo;
    while (!pq.empty()) {
        s = pq.top().S;
        pq.pop();
        if (s == t)
            return dist[s];
        v = s;
        rep(i, 0, 3) {
            custo = s[i] + s[i + 1];
            swap(v[i], v[i + 1]);
            if (dist.count(v) == 0 || dist[v] > dist[s] + custo) {
                dist[v] = dist[s] + custo;
                pq.push(mk(-dist[v], v));
            }
            swap(v[i], v[i + 1]);
        }

        rep(i, 4, 7) {
            custo = s[i] + s[i + 1];
            swap(v[i], v[i + 1]);
            if (dist.count(v) == 0 || dist[v] > dist[s] + custo) {
                dist[v] = dist[s] + custo;
                pq.push(mk(-dist[v], v));
            }
            swap(v[i], v[i + 1]);
        }

        rep(i, 0, 4) {
            custo = s[i] + s[i + 4];
            swap(v[i], v[i + 4]);
            if (dist.count(v) == 0 || dist[v] > dist[s] + custo) {
                dist[v] = dist[s] + custo;
                pq.push(mk(-dist[v], v));
            }
            swap(v[i], v[i + 4]);
        }
    }
}

int main() {

    vector<int> A(8), B(8);
    rep(i, 0, 8) scanf("%d", &A[i]);
    rep(i, 0, 8) scanf("%d", &B[i]);
    printf("%lld\n", dijkstra(A, B));

    return 0;
}
