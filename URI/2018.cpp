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

struct pais {
    string nome;
    int o, p, b;
    pais(){};
    pais(string _nome, int _o, int _p, int _b) {
        nome = _nome;
        o = _o;
        p = _p;
        b = _b;
    }
};

vector<pais> R; // ranking dos paises

bool comp(pais A, pais B) {
    if (A.o > B.o)
        return true;
    if (A.o < B.o)
        return false;

    if (A.p > B.p)
        return true;
    if (A.p < B.p)
        return false;

    if (A.b > B.b)
        return true;
    if (A.b < B.b)
        return false;

    if (A.nome < B.nome)
        return true;
    if (A.nome > B.nome)
        return false;
}

int main() {
    string tipo, A, B, C;
    map<string, int> mapa;
    int id = 0;

    while (getline(cin, tipo)) {
        getline(cin, A);
        if (mapa.count(A) == 0) {
            mapa[A] = id;
            R.pb(pais(A, 1, 0, 0));
            id++;
        } else
            R[mapa[A]].o++;

        getline(cin, B);
        if (mapa.count(B) == 0) {
            mapa[B] = id;
            R.pb(pais(B, 0, 1, 0));
            id++;
        } else
            R[mapa[B]].p++;

        getline(cin, C);
        if (mapa.count(C) == 0) {
            mapa[C] = id;
            R.pb(pais(C, 0, 0, 1));
            id++;
        } else
            R[mapa[C]].b++;
    }

    sort(R.begin(), R.end(), comp);
    cout << "Quadro de Medalhas\n";
    rep(i, 0, R.size()) { cout << R[i].nome << " " << R[i].o << " " << R[i].p << " " << R[i].b << "\n"; }

    return 0;
}