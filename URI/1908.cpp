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

vector<int> E[10010];
int fila[10010];

int bfs(int s, int t, int N) {
    vector<int> dist(N, -1);

    dist[s] = 0;
    int inicio = 0, fim = 0, v;
    fila[fim++] = s;
    while (inicio != fim) {
        s = fila[inicio++];
        if (s == t)
            break;
        rep(i, 0, E[s].size()) {
            v = E[s][i];
            if (dist[v] == -1) {
                dist[v] = dist[s] + 1;
                fila[fim++] = v;
            }
        }
    }
    return dist[t];
}

int main() {

    int N, K, Q;
    while (scanf("%d", &N) == 1) {
        K = readInt();
        //	vertices comecam em 1!
        for (int i = 0; i < N; i++)
            E[i].clear();

        while (K--) {
            Q = readInt();
            vector<int> aux(Q);
            rep(i, 0, Q) {
                aux[i] = readInt();
                aux[i]--;
            }
            rep(i, 0, aux.size()) rep(j, i + 1, aux.size()) {
                E[aux[i]].pb(aux[j]);
                E[aux[j]].pb(aux[i]);
            }
        }

        printf("%d\n", bfs(0, N - 1, N));
    }

    return 0;
}
