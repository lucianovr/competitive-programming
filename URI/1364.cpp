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

struct match {
    int i, j, id;
    match() {}
    match(int i, int j, int id) : i(i), j(j), id(id) {}
};

bool cmp(match a, match b) {
    if (a.i == b.i)
        return a.j < b.j;
    return a.i < b.i;
}

int N, M;
vector<string> E;

int solve(string t) {
    vector<match> vec;
    string s;

    for (int a = 0; a < N; a++) {
        s = E[a];
        for (int i = 0; i < t.size(); i++) {
            int k = 0;
            while (k < s.size() && i + k < t.size() && s[k] == t[i + k])
                k++;
            if (k == s.size())
                vec.pb(match(i, i + k - 1, a));
        }
    }

    if (vec.size() == 0)
        return 0;

    sort(vec.begin(), vec.end(), cmp);

    vector<match> aux;
    aux.pb(vec[0]);
    for (int i = 1; i < vec.size(); i++) {
        while (aux.size() && vec[i].j <= aux.back().j)
            aux.pop_back();
        aux.pb(vec[i]);
    }
    vec = aux;
    if (vec.size() < 2)
        return vec.size();

    int i = 0, j = 1;
    int Right = vec[0].j;
    int cont = 0;
    while (j < vec.size()) {
        while (j < vec.size() && vec[j].i <= Right)
            j++;
        cont++;
        if (j < vec.size())
            Right = vec[j].j;
    }

    return cont;
}

int main() {
    while (scanf("%d %d", &N, &M) && !(N == 0 && M == 0)) {
        E.resize(N);
        for (int i = 0; i < N; i++) {
            cin >> E[i];
        }
        cin.ignore();

        string Line;
        int ans = 0;
        while (M--) {
            getline(cin, Line);
            ans += solve(Line);
        }
        printf("%d\n", ans);
    }
    return 0;
}
