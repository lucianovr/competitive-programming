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

struct posicao {
    int A, B, H;
    posicao() {}
    posicao(int A, int B, int H) : A(A), B(B), H(H) {}
};

struct peca {
    posicao comb[6];
    peca(){};
    peca(int a, int b, int c) {
        comb[0] = posicao(a, b, c);
        comb[1] = posicao(b, a, c);
        comb[2] = posicao(a, c, b);
        comb[3] = posicao(c, a, b);
        comb[4] = posicao(b, c, a);
        comb[5] = posicao(c, b, a);
    }
};

vector<peca> V;
int pd[100010][6];

int S(int i, int p) {
    if (i == V.size())
        return 0;
    if (pd[i][p] != -1)
        return pd[i][p];

    int ans = 0;
    int j = i - 1;

    for (int k = 0; k < 6; k++) {
        if (V[i].comb[k].A <= V[j].comb[p].A && V[i].comb[k].B <= V[j].comb[p].B) {
            ans = max(ans, S(i + 1, k) + V[i].comb[k].H);
        }
    }
    if (ans == 0)
        return pd[i][p] = -INF;
    return pd[i][p] = ans;
}

int main() {
    int N;
    while (cin >> N) {
        int x, y, z;

        V.clear();
        V.pb(peca(INF, INF, INF));

        rep(i, 1, N + 1) {
            cin >> x >> y >> z;
            V.pb(peca(x, y, z));
        }

        memset(pd, -1, sizeof pd);
        int ans = 0;
        for (int i = 0; i < 6; i++)
            ans = max(ans, S(1, i));

        if (ans == 0)
            cout << -1 << "\n";
        else
            cout << ans << "\n";
    }
    return 0;
}