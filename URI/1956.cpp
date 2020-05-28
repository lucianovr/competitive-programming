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

int N; //#vertices
vector<pair<int, ii>> E;

// kruskal
int parent[10010];
int ncomp;

void init_kruskal() {
    ncomp = N;
    rep(i, 0, N) parent[i] = i;
}

int find(int x) {
    if (x != parent[x])
        parent[x] = find(parent[x]);
    return parent[x];
}

bool same(int x, int y) { return find(x) == find(y); }

void join(int x, int y) {
    x = find(x);
    y = find(y);
    parent[x] = y;
    ncomp--;
}

//

int main() {
    int j, cij, k;

    while (scanf("%d", &N) == 1) {

        E.clear();
        init_kruskal();

        for (int i = 0; i < N - 1; i++) {
            scanf("%d", &k);
            while (k--) {
                scanf("%d %d", &j, &cij);
                E.pb(mp(cij, mp(i, j - 1)));
            }
        }

        sort(all(E));

        ll mst = 0;
        rep(i, 0, E.size()) {
            if (!same(E[i].snd.fst, E[i].snd.snd)) {
                join(E[i].snd.fst, E[i].snd.snd);
                mst += (ll)E[i].fst;
            }
        }
        printf("%d %lld\n", ncomp, mst);
    }
    return 0;
}
