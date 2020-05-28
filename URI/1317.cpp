#include <cstdlib>
#include <iostream>
#include <queue>
#include <string.h>
#include <string>
#include <vector>
using namespace std;
typedef vector<int> vi;
#define rep(i, n) for (int i = 0; i < (n); i = i + 1)
#define tr(it, S) for (typeof(S.begin()) it = S.begin(); it != S.end(); it++)
#define all(S) (S).begin(), (S).end()
#define pb push_back
#define sz size()

int main() {

    int n, p, t1, t2, t3;
    int g[25][25], c[25], cont;
    string a1, a2, a3;
    while (cin >> n && n) {

        rep(i, n + 1) rep(j, n + 1) g[i][j] = 0;
        rep(i, n + 1) c[i] = 0;
        for (int i = 1; i <= n; i++) {
            cont = 0;
            while (cin >> p && p) {
                g[i][p] = 1;
                cont++;
            }
            c[i] = cont;
        }
        vector<pair<string, vector<string>>> pessoa;
        pessoa.resize(n + 1);
        queue<int> q;

        while (cin >> p && p) {
            cin >> t1 >> t2 >> a1 >> a2 >> a3;
            q.push(p);
            int vis[25];
            rep(i, n + 1) vis[i] = 0;
            vis[p] = 1;
            while (!q.empty()) {
                p = q.front();
                q.pop();
                if (c[p] < t1)
                    pessoa[p].second.pb(a1 + " ");
                else if (c[p] < t2)
                    pessoa[p].second.pb(a2 + " ");
                else
                    pessoa[p].second.pb(a3 + " ");

                for (int i = 1; i <= n; i++)
                    if (g[p][i] && vis[i] == 0) {
                        q.push(i);
                        vis[i] = 1;
                    }
            }
            for (int i = 1; i <= n; i++)
                if (!vis[i])
                    pessoa[i].second.pb(a1 + " ");
        }
        string nome;
        for (int i = 1; i <= n; i++) {
            cin >> nome;
            pessoa[i].first = (nome + ": ");
        }

        for (int i = 1; i <= n; i++) {
            cout << pessoa[i].first;
            vector<string> vec = pessoa[i].second;
            rep(j, vec.sz) cout << vec[j];
            cout << endl;
        }
    }
    return 0;
}
