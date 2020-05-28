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

int pos[27];
char M[27];

void init() {
    for (int i = 1; i <= 26; i++) {
        pos[i] = i;
        M[i] = 'A' + i - 1;
    }
}

vector<string> vec;
string ss;

void process(int x) {
    if (x == 27) {
        ss += " ";
        return;
    }

    // for (int i=1; i <= 26; i++)
    //	printf("%2d ", i); cout << "\n";

    // for (int i=1; i <= 26; i++)
    //	printf(" %c ", M[i]); cout << "\n";

    // for (int i=1; i <= 26; i++)
    //	printf("%2d ", pos[i]); cout << "\n";

    int i = pos[x];
    char letra = M[i];
    ss += letra;

    for (int j = i; j < 26; j++) {
        M[j] = M[j + 1];
    }
    for (int j = x; j < 26; j++) {
        pos[j] = pos[j + 1];
    }

    pos[26] = i;
    M[26] = letra;
}

int main() {
    int N;
    int lista = 1;
    while (scanf("%d", &N) == 1) {
        scanf("\n");

        if (lista != 1)
            printf("\n");
        vec.clear();

        init();

        while (N--) {
            char s[1000000];
            cin.getline(s, 1000000);
            char *pch;
            pch = strtok(s, " ");
            while (pch != NULL) {
                int x = atoi(pch);
                process(x);
                pch = strtok(NULL, " ");
            }
            vec.pb(ss);
            ss.clear();
        }

        sort(vec.begin(), vec.end());

        printf("LISTA #%d:\n", lista++);
        rep(i, 0, vec.size()) { printf("%s\n", vec[i].c_str()); }
    }
    return 0;
}