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
#define D2(x, y) cout << #x " = " << x << "  " << #y " = " << y << endl;
#define DVEC(v, n)                                                                                                     \
    {                                                                                                                  \
        cout << #v << "[] ={ ";                                                                                        \
        rep(i, 0, n) cout << v[i] << " ";                                                                              \
        cout << "}\n";                                                                                                 \
    }
#define mp make_pair
#define fst first
#define snd second
#define isONE(mask, bit) ((mask & (1 << bit))) > 0
#define isZERO(mask, bit) ((mask & (1 << bit))) == 0
#define setBIT(mask, bit) (mask | (1 << bit))

typedef pair<int, int> ii;
typedef long long ll;

typedef vector<int> vi;
typedef vector<ii> vii;

const int INF = 0x3f3f3f3f;
const double EPS = 1e-11;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int tam;
string s;
int dp[2002];

bool palin(int i, int j) {
    while (i < j) {
        if (s[i] != s[j])
            return false;
        i++, j--;
    }
    return true;
}

int S(int pos) {
    if (pos == tam)
        return 0;
    int &ans = dp[pos];
    if (ans != -1)
        return ans;

    ans = 1000000000;
    for (int j = pos; j < tam; j++) {
        if (palin(pos, j))
            ans = min(ans, 1 + S(j + 1));
    }
    return ans;
}
int main() {
    int teste = 1;
    while (cin >> tam) {
        if (tam == 0)
            break;
        cin >> s;
        tam = s.size();
        memset(dp, -1, sizeof dp);
        printf("Teste %d\n%d\n\n", teste++, S(0));
    }

    return 0;
}
