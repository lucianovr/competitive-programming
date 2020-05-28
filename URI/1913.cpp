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

#define VERM 0
#define LAR 1
#define AZUL 2
#define VERD 3

struct cilindro {
    int H, R, C;
    cilindro(int _H = 0, int _R = 0, int _C = 0) {
        H = _H;
        R = _R;
        C = _C;
    }
};

cilindro V[1010];
int N;

int dp[1010][1010];

bool pode(int ci, int cj) {
    if (ci == VERM)
        return cj != LAR;
    if (ci == LAR)
        return cj != AZUL;
    if (ci == AZUL)
        return cj != VERD;
    if (ci == VERD)
        return cj != VERM;
}

int S(int i, int j) {
    if (i == N + 1)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];

    int ans = 0;

    ans = max(ans, S(i + 1, j));

    if (V[i].R < V[j].R) {
        if (pode(V[i].C, V[j].C))
            ans = max(ans, V[i].H + S(i + 1, i));
    }

    return dp[i][j] = ans;
}

bool comp(cilindro a, cilindro b) { return a.R > b.R; }

int main() {
    int h, r, c;
    char cor[20];

    while (scanf("%d", &N) && N) {
        V[0] = cilindro(0, INF, -1);
        rep(i, 1, N + 1) {
            scanf("%d %d %s", &h, &r, cor);
            if (strcmp(cor, "VERMELHO") == 0)
                c = VERM;
            else if (strcmp(cor, "LARANJA") == 0)
                c = LAR;
            else if (strcmp(cor, "AZUL") == 0)
                c = AZUL;
            else if (strcmp(cor, "VERDE") == 0)
                c = VERD;
            V[i] = cilindro(h, r, c);
        }
        memset(dp, -1, sizeof dp);
        sort(V, V + N + 1, comp);

        printf("%d centimetro(s)\n", S(1, 0));
    }
    return 0;
}
