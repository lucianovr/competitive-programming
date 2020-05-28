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

typedef long long ll;
typedef pair<ll, ll> point;

const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;

#define MAXV 50000 + 100
point p[MAXV];

ll d[] = {0, 1, 2, 3, 4, 5};
ll sgn[] = {1, -1};

vector<int> E[MAXV];
bool vis[MAXV];
int n;
int temx[500010];
int temy[500010];
int cor[2];
map<point, int> idx;

void dfs(int v, int L) {
    cor[L]++;
    vis[v] = true;

    rep(i, 0, E[v].size()) {
        if (!vis[E[v][i]])
            dfs(E[v][i], 1 - L);
    }
}

int main() {
    ll x, y;
    while (scanf("%d", &n) == 1) {

        memset(temx, 0, sizeof temx);
        memset(temy, 0, sizeof temy);
        idx.clear();

        rep(i, 0, n) {
            E[i].clear();
            vis[i] = false;

            scanf("%lld %lld", &x, &y);
            temx[x] = 1;
            temy[y] = 1;
            p[i] = point(x, y);
            idx[point(x, y)] = i;
        }

        for (int v = 0; v < n; v++) {
            x = p[v].fst;
            y = p[v].snd;
            ll a, b;

            rep(ii, 0, 2) rep(jj, 0, 2) rep(i, 0, 6) rep(j, 0, 6) {
                a = x + sgn[ii] * d[i];
                b = y + sgn[jj] * d[j];
                if (a == x && b == y)
                    continue;

                if (a >= 1 && a <= 500000 && b >= 1 && b <= 500000) {
                    ll d2 = (a - x) * (a - x) + (b - y) * (b - y);
                    if (d2 <= 25 && temx[a] && temy[b] && idx.count(point(a, b))) {
                        E[v].push_back(idx[point(a, b)]);
                        //		cout << v << "-> " << E[v].back() << "\n";
                        //		cout << "("<<a<<","<<b<<")\n";
                    }
                }
            }
        }
        //		rep(v,0,n){
        //			cout << "\nv = " << v << "\n";
        //			DVEC(E[v], E[v].size());
        //		}

        int menor = 0;
        rep(v, 0, n) {
            if (!vis[v]) {
                cor[0] = cor[1] = 0;
                dfs(v, 0);

                menor += min(cor[0], cor[1]);
            }
        }
        printf("%d\n", menor);
    }
    return 0;
}
