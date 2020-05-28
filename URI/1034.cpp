#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <queue>
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
int dist[1000010];

bool comp(int i, int j) { return j > i; }

int main() {
    int t, n, m, u, v, w;
    int tam[25];

    for (cin >> t; t > 0; t--) {
        cin >> n >> m;
        rep(i, n) cin >> tam[i];
        sort(tam, tam + n, comp);

        queue<int> fila;
        fila.push(0);
        setar(dist, -1);
        dist[0] = 0;
        while (!fila.empty()) {
            u = fila.front();
            fila.pop();
            if (u == m)
                break;
            rep(i, n) {
                v = u + tam[i];
                if (v <= m && dist[v] == -1) {
                    dist[v] = dist[u] + 1;
                    fila.push(v);
                }
            }
        }

        cout << dist[m] << endl;
    }
    return 0;
}
