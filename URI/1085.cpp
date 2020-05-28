#include <algorithm>
#include <cstdlib>
#include <map>
#include <queue>
#include <stdio.h>
#include <string.h>
#include <string>
#include <utility>
#include <vector>
using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define rep(i, n) for (int i = 0; i < (n); i = i + 1)
#define tr(it, S) for (typeof(S.begin()) it = S.begin(); it != S.end(); it++)
#define all(S) (S).begin(), (S).end()
#define setar(S, x) memset(S, x, sizeof(S))
#define pb push_back
#define sz size()
#define contem(s, x) (s.find(x) != s.end())
#define inf 1000000000
int dist[4010][27];
int vis[4010][27];
typedef struct {
    int Vertice, Letra, Custo;
} aresta;

vector<aresta> adj[4010][27];

int dijkstra(int s, int d, int k) {
    int letra, v, l, cost, size;
    rep(i, k) rep(j, 26) {
        dist[i][j] = inf;
        vis[i][j] = 0;
    }

    priority_queue<pair<int, ii>> Q;
    for (int i = 0; i < 26; i++) {
        dist[s][i] = 0;
        Q.push(make_pair(0, ii(s, i)));
    }
    while (!Q.empty()) {
        s = Q.top().second.first;
        letra = Q.top().second.second;
        Q.pop();

        if (!vis[s][letra]) {
            vis[s][letra] = 1;
            size = adj[s][letra].size();
            rep(i, size) {
                v = adj[s][letra][i].Vertice;
                l = adj[s][letra][i].Letra;
                cost = adj[s][letra][i].Custo;
                if (dist[v][l] > dist[s][letra] + cost) {
                    dist[v][l] = dist[s][letra] + cost;
                    Q.push(make_pair(-dist[v][l], ii(v, l)));
                }
            }
        }
    }
    int MIN = inf;
    rep(i, 26) {
        if (dist[d][i] < MIN)
            MIN = dist[d][i];
    }

    return MIN;
}

int main() {
    map<string, int> mp;
    char s[100], d[100], idioma[100], idioma_[100], word[100];
    int n;

    while (scanf("%d", &n) && n) {
        scanf("%s%s", s, d);
        int k = 3;
        mp[s] = 1;
        mp[d] = 2;
        aresta a;
        int u, v, letra, tamanho;
        rep(i, n) {
            scanf("\n%s%s%s", idioma, idioma_, word);
            if (mp[idioma] == 0)
                mp[idioma] = k++;
            if (mp[idioma_] == 0)
                mp[idioma_] = k++;

            tamanho = strlen(word);
            letra = word[0] - 'a';
            u = mp[idioma];
            v = mp[idioma_];

            a.Custo = tamanho;

            a.Vertice = v - 1;
            rep(i, 26) {
                if (i != letra) {
                    a.Letra = i;
                    adj[u - 1][letra].push_back(a);
                }
            }
            a.Vertice = u - 1;
            rep(i, 26) {
                if (i != letra) {
                    a.Letra = i;
                    adj[v - 1][letra].push_back(a);
                }
            }
        }

        int res = dijkstra(0, 1, k);
        if (res != inf)
            printf("%d\n", res);
        else
            printf("impossivel\n");
        k;
        rep(i, k) rep(j, 26) adj[i][j].clear();
        mp.clear();
    }
    return 0;
}