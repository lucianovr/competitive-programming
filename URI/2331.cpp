#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <utility>
#include <vector>
using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define rep(i, a, b) for (int i = a; i < b; i++)
#define tr(it, S) for (typeof(S.begin()) it = S.begin(); it != S.end(); it++)
#define all(S) S.begin(), S.end()
#define STD std::ios::sync_with_stdio(false)

int main() {
    map<string, int> mp;
    map<int, string> _mp;

    vector<pair<string, string>> edges;
    vector<int> g[2010]; // grafo
    queue<ii> fila;

    int n;
    string s1, s2;

    set<string> Set;
    cin >> n;
    rep(i, 0, n) { // lendo as arestas
        cin >> s1 >> s2;
        edges.push_back(make_pair(s1, s2));
        Set.insert(s1);
        Set.insert(s2);
    }
    cin >> s1 >> s2;

    int k = 0, size = Set.size();
    for (set<string>::iterator it = Set.begin(); it != Set.end(); it++) {
        mp[*it] = k++;
    }

    for (vector<pair<string, string>>::iterator it = edges.begin(); it != edges.end(); it++) {
        g[mp[it->first]].push_back(mp[it->second]);
    }

    int final = mp[s2];

    fila.push(ii(mp[s1], 0));
    vector<int> vis(size + 10, 0);

    while (!fila.empty()) {
        ii topo = fila.front();
        fila.pop();
        int s = topo.first, dist = topo.second;

        if (s == final) {
            cout << dist << "\n";
            break;
        }
        if (vis[s])
            continue;
        vis[s] = 1;

        for (vector<int>::iterator it = g[s].begin(); it != g[s].end(); it++) {
            fila.push(ii(*it, dist + 1));
        }

        if (s >= 1)
            fila.push(ii(s - 1, dist + 1));
        if (s < size - 1)
            fila.push(ii(s + 1, dist + 1));
    }

    return 0;
}
