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

typedef pair<int, int> ii;
typedef long long ll;

typedef vector<int> vi;
typedef vector<ii> vii;

const int INF = 0x3f3f3f3f;
const double EPS = 1e-11;

inline int cmp(double x, double y = 0, double tol = EPS) { return ((x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1); }

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

int readInt() {
    bool minus = false;
    int result = 0;
    char ch;

    ch = getchar();
    while (true) {
        if (ch == '-')
            break;
        if (ch >= '0' && ch <= '9')
            break;
        ch = getchar();
    }
    if (ch == '-')
        minus = true;
    else
        result = ch - '0';
    while (true) {
        ch = getchar();
        if (ch < '0' || ch > '9')
            break;
        result = result * 10 + (ch - '0');
    }
    if (minus)
        return -result;
    else
        return result;
}

vector<pair<char, int>> vec;

int solve(int ini, int fim) {
    int v;
    int ret = 0;

    int i, j = ini + 1;
    while (true) {
        if (j > fim) {
            j = fim;
            i = j - 1;
            v = vec[j].snd - vec[i].snd;
            ret = max(ret, v);
            break;
        }
        i = j - 2;
        if (i < ini)
            i = ini;
        v = vec[j].snd - vec[i].snd;
        ret = max(ret, v);

        if (j == fim)
            break;
        j += 2;
    }

    j = ini + 2;
    while (true) {
        if (j > fim) {
            j = fim;
            i = j - 1;
            v = vec[j].snd - vec[i].snd;
            ret = max(ret, v);
            break;
        }
        i = j - 2;

        v = vec[j].snd - vec[i].snd;
        ret = max(ret, v);

        if (j == fim)
            break;
        j += 2;
    }

    return ret;
}

int main() {

    int t, caso = 1;
    t = readInt();
    char tipo;
    int pos, ans;

    while (t-- > 0) {
        int N, D;
        N = readInt();
        D = readInt();

        vec.clear();
        vec.pb(mp('B', 0));
        rep(i, 0, N) {
            scanf(" %c-%d", &tipo, &pos);
            vec.pb(mp(tipo, pos));
        }
        vec.pb(mp('B', D));

        ans = 0;
        for (int i = 0; i < vec.size() - 1;)
            for (int j = i + 1; j < vec.size(); j++)
                if (vec[j].fst == 'B') {
                    ans = max(ans, vec[j].snd - vec[i].snd);
                    i = j;
                    break;
                } else {
                    while (j < vec.size() && vec[j].fst == 'S')
                        j++;
                    ans = max(ans, solve(i, j));
                    i = j;
                    break;
                }
        printf("Case %d: %d\n", caso++, ans);
    }
    return 0;
}
