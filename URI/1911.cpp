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

bool diferente(string a, string b) {
    int cont = 0;
    rep(i, 0, a.size()) if (a[i] != b[i]) cont++;
    return cont > 1;
}

int main() {
    int N, M, cont;
    map<string, string> MAP;
    string nome, assinatura;

    while (scanf("%d", &N) && N) {

        cont = 0;
        MAP.clear();

        rep(i, 0, N) {
            cin >> nome >> assinatura;
            MAP[nome] = assinatura;
        }
        scanf("%d", &M);
        rep(i, 0, M) {
            cin >> nome >> assinatura;
            if (diferente(MAP[nome], assinatura))
                cont++;
        }
        cout << cont << "\n";
    }
    return 0;
}
