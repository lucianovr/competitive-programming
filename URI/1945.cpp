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

bool hasPlus(char *s) {
    for (int i = 0; i < strlen(s); i++) {
        if (s[i] == '+')
            return true;
    }
    return false;
}

int main() {
    map<string, int> mapa;
    char var[1000], s[1000];

    while (scanf("%s := ", var) != EOF) {
        gets(s);

        if (hasPlus(s)) {
            int i = 0;
            string va;
            int aa = 0;

            while (s[i] == ' ' || s[i] == '+')
                i++;

            if (isalpha(s[i])) {
                while (s[i] != ' ')
                    va += s[i++];
                mapa[var] = mapa[va];
            } else {
                while (s[i] != ' ')
                    aa = aa * 10 + s[i++] - '0';
                mapa[var] = aa;
            }

            while (s[i] == ' ' || s[i] == '+')
                i++;
            va = "";
            aa = 0;
            if (isalpha(s[i])) {
                while (s[i] != '\0')
                    va += s[i++];
                mapa[var] = mapa[var] + mapa[va];
            } else {
                while (s[i] != '\0')
                    aa = aa * 10 + s[i++] - '0';
                mapa[var] = mapa[var] + aa;
            }

        } else {
            mapa[var] = atoi(s);
        }
    }

    cout << mapa[var] << "\n";

    return 0;
}
