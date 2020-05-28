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

struct tipo {
    string nome;
    double valor;
    int rank;

    tipo(){};
    tipo(string _nome, double _valor, int _rank) : nome(_nome), valor(_valor), rank(_rank){};
};

vector<tipo> P;

bool comp(tipo A, tipo B) {
    if (A.rank > B.rank)
        return true;
    if (A.rank < B.rank)
        return false;

    if (A.valor < B.valor)
        return true;
    if (A.valor > B.valor)
        return false;

    if (A.nome < B.nome)
        return true;
    if (A.nome > B.nome)
        return false;
}

int main() {
    string pessoa;
    int qt;

    double valor;
    int rank;
    string nome;

    while (cin >> pessoa >> qt) {
        P.clear();
        cin.ignore();
        rep(i, 0, qt) {
            getline(cin, nome);
            cin >> valor >> rank;
            P.pb(tipo(nome, valor, rank));
            cin.ignore();
        }
        sort(P.begin(), P.end(), comp);

        cout << "Lista de " << pessoa << "\n";
        rep(i, 0, P.size()) { printf("%s - R$%.2lf\n", P[i].nome.c_str(), P[i].valor); }
        cout << "\n";
    }

    return 0;
}