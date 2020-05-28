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

char troca[300];

void init() {
    for (char c = 'a'; c <= 'z'; c++) {
        troca[c] = c;
    }
    for (char c = 'A'; c <= 'Z'; c++) {
        troca[c] = c;
    }

    troca['b'] = 'f';
    troca['B'] = 'F';

    troca['j'] = 'f';
    troca['J'] = 'F';

    troca['p'] = 'f';
    troca['P'] = 'F';

    troca['s'] = 'f';
    troca['S'] = 'F';

    troca['v'] = 'f';
    troca['V'] = 'F';

    troca['x'] = 'f';
    troca['X'] = 'F';

    troca['z'] = 'f';
    troca['Z'] = 'F';
}

char s[1000000];
void process() {
    int slen = strlen(s);
    for (int i = 0; i < slen; i++) {
        if (isalpha(s[i]))
            s[i] = troca[s[i]];
    }

    for (int i = 0; i < slen; i++) {
        if (isalpha(s[i]) && tolower(s[i]) == 'f' && i && tolower(s[i - 1]) == 'f')
            continue;
        printf("%c", s[i]);
    }
    printf("\n");
}

int main() {
    init();

    //	freopen("EpiIN.txt", "r", stdin);
    //	freopen("EpiOUT.txt", "w", stdout);
    while (gets(s)) {
        process();
    }

    return 0;
}
