#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define rep(i, a, b) for (int i(a); i < (b); i++)
#define debug(x) cout << #x << " = " << x << "\n";
#define MAXN 20000 + 10
#define MAXS 50000 + 10

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int N, M, S;

int pai[MAXN], size[MAXN];

vector<int> conjunto[MAXN]; // identificadores das consutas presentes em cada componente
pair<int, int> query[MAXS]; // consultas
int resp[MAXS];             // respostas das consultas

bool comp(pair<int, ii> A, pair<int, ii> B) { return A.first > B.first; }

int find_set(int i) {
    if (i != pai[i])
        pai[i] = find_set(pai[i]);
    return pai[i];
}

void unio(int x, int y, int peso) {
    x = find_set(x);
    y = find_set(y);

    if (x != y) {
        if (size[x] < size[y]) {
            swap(x, y);
        }
        pai[y] = x;
        size[x] += size[y];

        rep(i, 0, conjunto[y].size()) {
            int c = conjunto[y][i]; // consultas presentes na componente do conjunto Y
            if (resp[c] == -1) {
                if (find_set(query[c].first) == find_set(query[c].second)) // caso os dois vertices estejam
                    resp[c] = peso;                                        // agora na mesma componente
            }
            if (resp[c] == -1) {
                conjunto[x].pb(c);
            }
        }
        conjunto[y].clear();
    }
}

int main() {
    int A, B, P;

    while (cin >> N >> M >> S) {

        pair<int, ii> arestas[M];

        rep(i, 0, M) {
            cin >> A >> B >> P;
            arestas[i] = make_pair(P, ii(A, B));
        }

        sort(arestas, arestas + M, comp); // O(M log M)

        for (int i = 1; i <= N; i++) {
            pai[i] = i;
            size[i] = 1;
        }

        for (int i = 1; i <= S; i++) {
            cin >> A >> B;

            resp[i] = -1;
            query[i] = ii(A, B);
            conjunto[A].pb(i);
            conjunto[B].pb(i);
        }

        rep(i, 0, M) {
            P = arestas[i].first;
            A = arestas[i].second.first;
            B = arestas[i].second.second;
            unio(A, B, P);
        }

        for (int i = 1; i <= S; i++)
            cout << resp[i] << "\n";
    }

    return 0;
}
