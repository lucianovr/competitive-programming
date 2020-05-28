#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i(a); i < (b); i++)

#define all(c) c.begin(), c.end()
#define UNIQUE(c)                                                                                                      \
    {                                                                                                                  \
        sort(all(c));                                                                                                  \
        (c).resize(unique(all(c)) - c.begin());                                                                        \
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

#define isOne(mask, bit) (mask & (1LL << bit)) > 0
#define isZero(mask, bit) (mask & (1LL << bit)) == 0
#define stBit(mask, bit) (mask | (1LL << bit))
#define clrBit(mask, bit) (mask & ~(1LL << bit))
#define toogleBit(mask, bit) (mask ^ (1LL << bit))
#define LSOne(mask) (mask & (-mask))

typedef pair<int, int> ii;
typedef long long ll;

const int INF = 0x3f3f3f3f;
const double EPS = 1e-11;

// compara doubles
inline int cmp(double x, double y = 0, double tol = EPS) { return ((x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1); }

// compara inteiros
inline int cmp(int x, int y = 0) { return (x <= y) ? (x < y) ? -1 : 0 : 1; }

// direcoes  N  W  S  E  NW SW SE NE
int dx[] = {-1, 0, 1, 0, -1, 1, 1, -1};
int dy[] = {0, -1, 0, 1, -1, -1, 1, 1};

// knight moves
int dkx[] = {-2, -2, -1, 1, 2, 2, 1, -1};
int dky[] = {1, -1, -2, -2, -1, 1, 2, 2};

int T[1000010][26], tam, grau[1000010], ans;
bool term[1000010];

void add(string s) {
    int slen = s.size();
    int root = 0;
    rep(i, 0, slen) {
        int c = s[i] - 'a';
        if (T[root][c])
            root = T[root][c];
        else {
            grau[root]++;
            root = T[root][c] = ++tam;
        }
    }
    term[root] = true;
}

void dfs(int root, int cnt) {
    if (term[root]) {
        ans += cnt;
    }
    for (int c = 0; c < 26; c++) {
        if (T[root][c]) {
            if (grau[root] > 1 || term[root] || root == 0)
                dfs(T[root][c], cnt + 1);
            else
                dfs(T[root][c], cnt);
        }
    }
}

void trie_init(int n) {
    tam = 0;
    memset(term, false, sizeof term);
    memset(T, 0, sizeof T);
    memset(grau, 0, sizeof grau);
}

int main() {

    int n;
    string s;

    while (scanf("%d", &n) > 0) {
        trie_init(n);
        rep(i, 0, n) {
            cin >> s;
            add(s);
        }
        ans = 0;
        dfs(0, 0);
        printf("%.2lf\n", (double(ans)) / (double(n)));
    }
    return 0;
}
