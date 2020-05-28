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
#define DVEC2(v, n)                                                                                                    \
    {                                                                                                                  \
        cout << #v << "[] ={ ";                                                                                        \
        rep(i, 0, n) { cout << "(" << v[i].fst << " " << v[i].snd << ") "; }                                           \
        cout << "}\n";                                                                                                 \
    }

#define mp make_pair
#define fst first
#define snd second

#define isONE(mask, bit) ((mask & (1<<bit))>0
#define isZERO(mask, bit) ((mask & (1<<bit))==0
#define setBIT(mask, bit) (mask | (1 << bit))
#define clearBIT(mask, bit) (mask & ~(1 << bit))
#define toogleBIT(mask, bit) (mask ^ (1 << bit))
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

int main() {

    int count;
    set<string> perolas, respostas;
    vector<pair<int, string>> vec;

    string nome, s;
    int P, A, R;

    while (scanf("%d %d %d", &P, &A, &R) > 0) {
        if (P == 0 && A == 0 && R == 0)
            break;

        getchar();

        perolas.clear();
        vec.clear();

        rep(i, 0, P) {
            getline(cin, s);
            perolas.insert(s);
        }

        rep(i, 0, A) {
            respostas.clear();
            getline(cin, nome);
            rep(j, 0, R) {
                getline(cin, s);
                respostas.insert(s);
            }
            count = 0;
            for (set<string>::iterator it = respostas.begin(); it != respostas.end(); it++) {
                count += perolas.find(*it) != perolas.end() ? 1 : 0;
            }
            vec.pb(mp(-count, nome));
        }

        UNIQUE(vec);

        printf("%s", vec[0].snd.c_str());
        rep(i, 1, vec.size()) if (vec[i].fst == vec[i - 1].fst) printf(", %s", vec[i].snd.c_str());
        else break;
        printf("\n");
    }

    return 0;
}
