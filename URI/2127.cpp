#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i(a); i < (b); i++)
#define all(c) (c).begin(), (c).end()
#define fst first
#define snd second
#define db(x) cerr << __LINE__ << ": " << #x << " = " << x << endl

#define pb push_back
#define mp make_pair

const int INF = 0x3f3f3f3f;
typedef long long ll;
typedef pair<int, int> ii;

int pai[1010];
int find(int x) {
    if (x != pai[x])
        return pai[x] = find(pai[x]);
    return pai[x];
}

void join(int x, int y) { pai[find(x)] = find(y); }

bool same(int x, int y) { return find(x) == find(y); }

int main() {
#ifndef ONLINE_JUDGE
    // freopen("_in.txt", "r", stdin);
    // freopen("_out.txt", "w", stdout);
#endif
    int n, m, u, v, w, inst = 1;
    int val[] = {1235, 8977, 10923};

    vector<pair<int, int>> E[3];

    while (scanf("%d %d", &n, &m) != EOF) {
        rep(i, 0, n + 1) pai[i] = i;

        rep(i, 0, 3) E[i].clear();
        while (m--) {
            scanf("%d %d %d", &u, &v, &w);
            rep(i, 0, 3) {
                if (w == val[i]) {
                    E[i].pb(mp(u, v));
                    break;
                }
            }
        }
        int edges = 0;
        ll ans = 0;
        rep(i, 0, 3) {
            rep(j, 0, E[i].size()) {
                u = E[i][j].fst;
                v = E[i][j].snd;
                if (!same(u, v)) {
                    ans += val[i];
                    join(u, v);
                    edges++;
                }
            }
        }
        printf("Instancia %d\n%lld\n\n", inst++, ans);
    }
    return 0;
}
