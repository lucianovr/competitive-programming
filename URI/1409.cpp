#include <algorithm>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i = i + 1)
#define tr(it, S) for (typeof(S.begin()) it = S.begin(); it != S.end(); it++)
#define all(S) (S).begin(), (S).end()
#define setar(S, x) memset(S, x, sizeof(S))
#define sz size()
#define contem(s, x) (s.find(x) != s.end())
#define NOS 1010

vector<pair<int, long long>> ladj[NOS];

long long dijkstra(int nos, long long valor_inicial) {
    vector<long long> dist(nos + 2);
    vector<int> vis(nos + 2);

    rep(i, nos + 2) {
        dist[i] = -1LL;
        vis[i] = 0;
    }

    priority_queue<pair<long long, int>> Q;

    dist[1] = valor_inicial;
    Q.push(make_pair(valor_inicial, 1));
    int s, v, len;
    long long cost;

    while (!Q.empty()) {
        s = Q.top().second;
        Q.pop();
        if (!vis[s]) {
            vis[s] = 1;
            if (s == nos)
                break;

            len = ladj[s].size();
            for (int i = 0; i < len; i++) {
                v = ladj[s][i].first;
                cost = ladj[s][i].second;

                if (!vis[v] && (dist[v] == -1LL || dist[v] > dist[s] + cost)) {
                    dist[v] = dist[s] + cost;
                    Q.push(make_pair(-dist[v], v));
                }
            }
        }
    }
    return dist[nos];
}

long long mana[1000], dano[1000], pd[1002], caverna[1001];

int main() {
    int magias, nos, arestas, monstros, leng;
    while (cin >> magias >> nos >> arestas >> monstros && (magias + nos + arestas + monstros)) {

        for (int i = 0; i <= nos; i++) {
            caverna[i] = 0LL;
            ladj[i].clear();
        }

        for (int i = 0; i < magias; i++)
            cin >> mana[i] >> dano[i];

        for (int i = 1; i <= 1000; i++)
            pd[i] = -1LL;
        pd[0] = 0LL;

        for (int i = 0; i < magias; i++)
            for (int k = 1; k <= 1001; k++) {
                if (k - dano[i] >= 0LL) {
                    if (pd[k] == -1LL)
                        pd[k] = pd[k - dano[i]] + mana[i];
                    else
                        pd[k] = min(pd[k], pd[k - dano[i]] + mana[i]);
                } else {
                    if (pd[k] == -1LL)
                        pd[k] = mana[i];
                    else
                        pd[k] = min(pd[k], mana[i]);
                }
            }

        vector<pair<int, int>> edges;
        int x, y;
        while (arestas--) {
            cin >> x >> y;
            edges.push_back(make_pair(x, y));
        }

        for (int k = 0; k < monstros; k++) {
            int posicao, pontos;
            cin >> posicao >> pontos;
            caverna[posicao] += pd[pontos];
        }

        leng = edges.size();
        for (int i = 0; i < leng; ++i) {
            x = edges[i].first;
            y = edges[i].second;
            ladj[x].push_back(make_pair(y, caverna[y]));
            ladj[y].push_back(make_pair(x, caverna[x]));
        }

        cout << dijkstra(nos, caverna[1]) << endl;
    }
    return 0;
}