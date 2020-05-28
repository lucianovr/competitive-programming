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

// direcoes  N  S  D  E NW SW SE NE
int dx[] = {-1, 1, 0, 0, -1, 1, 1, -1};
int dy[] = {0, 0, 1, -1, -1, -1, 1, 1};

typedef vector<string> matrix;

inline string toString(matrix M) { return M[0] + M[1] + M[2]; }

inline matrix toMatrix(string S) {
    matrix M;
    M.pb(S.substr(0, 3));
    M.pb(S.substr(3, 3));
    M.pb(S.substr(6, 3));
    return M;
}

unordered_map<string, ll> dist;
unordered_map<string, string> parent;
queue<pair<string, ii>> Q;
string END;

ll bfs(string S, ii pos) {
    int x, y, a, b;
    matrix M;
    string T;
    ll old;

    while (!Q.empty())
        Q.pop();
    dist.clear();
    parent.clear();

    Q.push(mp(S, pos));
    dist[S] = 0;

    while (!Q.empty()) {
        S = Q.front().fst;
        pos = Q.front().snd;
        Q.pop();

        old = dist[S];
        x = pos.fst;
        y = pos.snd;
        M = toMatrix(S);

        if (S == END)
            return old;
        for (int i = 0; i < 4; i++) {
            a = x + dx[i];
            b = y + dy[i];
            if (a < 0 || a > 2 || b < 0 || b > 2)
                continue;
            swap(M[x][y], M[a][b]);
            T = toString(M);
            if (dist.count(T) == 0) {
                dist[T] = old + 1;
                Q.push(mp(T, ii(a, b)));
                parent[T] = S;
            }
            swap(M[x][y], M[a][b]);
        }
    }
    return -1;
}

int main() {

    END = "123456780";

    string s, T;
    matrix m;
    vector<string> path;

    while (cin >> s) {
        path.clear();
        m.clear();
        // leitura
        m.pb(s);
        rep(i, 0, 2) {
            cin >> s;
            m.pb(s);
        }

        int x, y;
        rep(i, 0, 3) rep(j, 0, 3) if (m[i][j] == '0') {
            x = i;
            y = j;
            break;
        }
        ll ret;
        s = toString(m);
        ret = bfs(s, ii(x, y));

        // saida
        if (ret == -1)
            printf("Problema sem solucao\n");
        else {
            printf("Quantidade minima de passos = %lld\n", ret);

            T = END;
            while (T != s) {
                path.push_back(T);
                T = parent[T];
            }
            reverse(path.begin(), path.end());
            for (int i = 0; i < path.size(); i++) {
                s = path[i];
                if (i)
                    printf("\n");
                printf("%s\n%s\n%s\n", s.substr(0, 3).c_str(), s.substr(3, 3).c_str(), s.substr(6, 3).c_str());
            }
        }
    }

    return 0;
}
