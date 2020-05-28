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

int Q[1000100];
int dist[1000100];

int main() {
    int O, D, K, p;
    set<int> st;

    while (scanf("%d %d %d", &O, &D, &K) == 3) {
        if (O == 0 && D == 0 && K == 0)
            break;

        st.clear();
        rep(i, 0, K) {
            scanf("%d", &p);
            st.insert(p);
        }

        memset(dist, -1, sizeof dist);
        int inicio, fim;
        inicio = fim = 0;

        dist[O] = 0;
        Q[fim++] = O;

        while (inicio != fim) {
            int v = Q[inicio++];
            if (v == D)
                break;
            int u;

            u = v - 1;
            if (u >= 0 && st.find(u) == st.end()) {
                if (dist[u] == -1) {
                    dist[u] = dist[v] + 1;
                    Q[fim++] = u;
                }
            }
            u = v + 1;
            if (u <= 100000 && st.find(u) == st.end()) {
                if (dist[u] == -1) {
                    dist[u] = dist[v] + 1;
                    Q[fim++] = u;
                }
            }

            if (v % 2 == 0 && st.find(v / 2) == st.end()) {
                u = v / 2;
                if (dist[u] == -1) {
                    dist[u] = dist[v] + 1;
                    Q[fim++] = u;
                }
            }

            u = v * 2;
            if (u <= 100000 && st.find(u) == st.end()) {
                if (dist[u] == -1) {
                    dist[u] = dist[v] + 1;
                    Q[fim++] = u;
                }
            }
            u = v * 3;
            if (u <= 100000 && st.find(u) == st.end()) {
                if (dist[u] == -1) {
                    dist[u] = dist[v] + 1;
                    Q[fim++] = u;
                }
            }
        }

        cout << dist[D] << "\n";
    }
    return 0;
}
