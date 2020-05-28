#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define rep(i, a, b) for (int i(a); i < (b); i++)
#define debug(x) cout << #x << " = " << x << "\n";

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define MAX 100 + 10

int pai[MAX], sz[MAX], cnt;

int find(int i) {
    if (i != pai[i])
        pai[i] = find(pai[i]);
    return pai[i];
}

void join(int a, int b, int c) {
    a = find(a);
    b = find(b);
    if (a != b) {
        if (sz[a] < sz[b])
            swap(a, b);
        pai[b] = a;
        sz[a] += sz[b];
        cnt += c;
    }
}

int main() {
    int g[MAX][MAX];
    vector<pair<int, ii>> edges;

    int t, n, m, a, b;
    scanf("%d", &t);

    while (t--) {
        cnt = 0;
        scanf("%d %d", &n, &m);
        rep(i, 0, n) pai[i] = i, sz[i] = 1;

        rep(i, 0, n) rep(j, i + 1, n) g[j][i] = g[i][j] = 0;

        while (m--) {
            scanf("%d %d", &a, &b);
            g[a][b] = 1;
        }
        edges.clear();
        rep(i, 0, n) rep(j, i + 1, n) edges.pb(make_pair(g[i][j], ii(i, j)));

        sort(edges.begin(), edges.end());

        rep(i, 0, edges.size()) {
            int c = edges[i].first;
            a = edges[i].second.first;
            b = edges[i].second.second;
            join(a, b, c);
        }

        printf("%d\n", cnt);
    }
    return 0;
}
